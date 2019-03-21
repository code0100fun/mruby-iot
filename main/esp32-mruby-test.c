#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"
#include "freertos/semphr.h"

#include "ssd1306.h"
#include "ssd1306_draw.h"
#include "ssd1306_font.h"
#include "ssd1306_default_if.h"

#include "esp_system.h"
#include "esp_log.h"
#include "nvs_flash.h"
#include "esp_system.h"
#include "esp_heap_caps.h"

#include "mruby.h"
#include "mruby/irep.h"
#include "mruby/compile.h"
#include "mruby/error.h"
#include "mruby/string.h"
#include "app_mrb.h" // generated from mruby script compile

#include "sprite_sheet.h"

#define MRUBY_TAG "mruby_task"
#define OLED_TAG "oled_task"
#define MAIN_TAG "main_task"

const int I2CDisplayAddress = 0x3C;
const int I2CDisplayWidth = 128;
const int I2CDisplayHeight = 64;
const int I2CResetPin = -1;

struct SSD1306_Device I2CDisplay;

const struct SSD1306_FontDef* FontList[] = {
    &Font_droid_sans_fallback_11x13,
    &Font_droid_sans_fallback_15x17,
    &Font_droid_sans_fallback_24x28,
    &Font_droid_sans_mono_7x13,
    &Font_droid_sans_mono_13x24,
    &Font_droid_sans_mono_16x31,
    &Font_liberation_mono_9x15,
    &Font_liberation_mono_13x21,
    &Font_liberation_mono_17x30,
    NULL
};

typedef enum {
    STATE_ANY = -1,
    STATE_EGG = 0,
    STATE_HATCHING = 1,
    STATE_HATCHED = 2,
} LifeStage_t;

typedef struct {
    uint8_t row;
    uint8_t column;
    uint8_t min_frame;
    uint8_t max_frame;
    uint16_t frame_length;
    bool loop;
} Sprite_t;

typedef struct {
    Sprite_t sprite;
    uint8_t current_frame;
    uint8_t x;
    uint8_t y;
    uint16_t elapsed_ms;
} RenderedSprite_t;

typedef struct {
    LifeStage_t state;
    uint16_t animation_tick;
    RenderedSprite_t rendered_sprites[1];
} GameState_t;

typedef struct {
    mrb_state *mrb;
    mrb_value method;
} RubyFnCall_t;

typedef struct {
    mrb_state *mrb;
    LifeStage_t state;
    esp_timer_handle_t timer;
} BlockCallback_t;

GameState_t game_state = { .state = STATE_EGG };
QueueHandle_t display_queue = NULL;
QueueHandle_t ruby_fn_call_queue = NULL;

mrb_value event_any_to_egg_block;
mrb_value event_egg_to_hatching_block;
mrb_value event_hatching_to_hatched_block;

Sprite_t egg_sprite = { .row = 0, .column = 0, .min_frame = 0, .max_frame = 1, .loop = true, .frame_length = 500 };
Sprite_t hatching_sprite = { .row = 0, .column = 1, .min_frame = 0, .max_frame = 1, .loop = true, .frame_length = 100 };
Sprite_t hatched_sprite = { .row = 0, .column = 2, .min_frame = 0, .max_frame = 1, .loop = false, .frame_length = 1000 };

void draw_sprite(struct SSD1306_Device* display, RenderedSprite_t rendered_sprite) {
    const uint32_t *frame_data = sprite_sheet_data[rendered_sprite.current_frame];
    for (uint16_t y = 0; y < 32; y++) {
        int32_t row = frame_data[y * 4 + rendered_sprite.sprite.column]; // 4 columns of sprites
        for (uint16_t x = 0; x < 32; x++) {
            int color = (row & 1 << x) ? SSD_COLOR_WHITE : SSD_COLOR_BLACK;
            SSD1306_DrawPixel(display, x + rendered_sprite.x, y + rendered_sprite.y, color);
        }
    }
}

void draw_frame(struct SSD1306_Device* display, GameState_t state) {
    draw_sprite(display, state.rendered_sprites[0]);
}

void send_to_display_queue() {
    GameState_t state = game_state;
    xQueueSend(display_queue, (void*)&state, portMAX_DELAY);
}

void render() {
    RenderedSprite_t *rendered_p = &game_state.rendered_sprites[0];
    switch (game_state.state)
    {
        case STATE_EGG:
            rendered_p->sprite = egg_sprite;
            break;
        case STATE_HATCHING:
            rendered_p->sprite = hatching_sprite;
            break;
        case STATE_HATCHED:
            rendered_p->sprite = hatched_sprite;
            break;
        default:
            break;
    }
    rendered_p->current_frame = 0;
    send_to_display_queue();
}

bool init_oled(void) {
    assert(SSD1306_I2CMasterInitDefault());
    assert(SSD1306_I2CMasterAttachDisplayDefault(&I2CDisplay, I2CDisplayWidth, I2CDisplayHeight, I2CDisplayAddress, I2CResetPin ));
    return true;
}

void handle_state_change(mrb_state *mrb, LifeStage_t from, LifeStage_t to) {
    RubyFnCall_t ruby_fn_call = { .mrb = mrb, .method = mrb_nil_value() };
    if (to == STATE_EGG) {
        ruby_fn_call.method = event_any_to_egg_block;
    }
    if (from == STATE_EGG && to == STATE_HATCHING) {
        ruby_fn_call.method = event_egg_to_hatching_block;
    }
    if (from == STATE_HATCHING && to == STATE_HATCHED) {
        ruby_fn_call.method = event_hatching_to_hatched_block;
    }
    xQueueSend(ruby_fn_call_queue, (void*)&ruby_fn_call, portMAX_DELAY);
}

void set_state(mrb_state *mrb, LifeStage_t new_state) {
    LifeStage_t old_state = game_state.state;
    game_state.state = new_state;
    render();
    handle_state_change(mrb, old_state, new_state);
}

void transition_to_callback(void* params)
{
    BlockCallback_t *callback = (BlockCallback_t*)params;
    esp_timer_stop(callback->timer);
    ESP_ERROR_CHECK(esp_timer_delete(callback->timer));
    callback->timer = NULL;
    set_state(callback->mrb, (LifeStage_t)callback->state);
}

mrb_value mrb_game_state_set_state(mrb_state *mrb, mrb_value self) {
    mrb_int state = NULL;
    mrb_get_args(mrb, "i", &state);
    set_state(mrb, (LifeStage_t)state);
    return mrb_fixnum_value(state);
}

mrb_value mrb_game_save_state_load(mrb_state *mrb, mrb_value self) {
    mrb_value block;
    mrb_get_args(mrb, "&", &block);

    // TODO - read from NVS
    mrb_funcall(mrb, block, "call", 1, mrb_nil_value());

    mrb_gc_register(mrb, block);

    return mrb_nil_value();
}

mrb_value mrb_game_state_transition_to(mrb_state *mrb, mrb_value self) {
    mrb_int to = NULL;
    mrb_int time = NULL;
    mrb_value block;
    mrb_get_args(mrb, "ii&", &to, &time, &block);
    LifeStage_t state = (LifeStage_t)to;
    BlockCallback_t callback = {
        .mrb = mrb,
        .state = state,
    };
    const esp_timer_create_args_t oneshot_timer_args = {
        .callback = &transition_to_callback,
        .arg = (void*)&callback,
        .name = "transition_to"
    };
    int32_t timeout_us = ((int32_t)time) * 1000;
    esp_timer_handle_t oneshot_timer;
    ESP_ERROR_CHECK(esp_timer_create(&oneshot_timer_args, &oneshot_timer));
    callback.timer = oneshot_timer;

    ESP_ERROR_CHECK(esp_timer_start_once(oneshot_timer, timeout_us));
    return self;
}

mrb_value mrb_game_events_state_change(mrb_state *mrb, mrb_value self) {
    mrb_int from = NULL;
    mrb_int to = NULL;
    mrb_value block;
    mrb_get_args(mrb, "ii&", &from, &to, &block);

    if ((LifeStage_t)from == STATE_ANY && (LifeStage_t)to == STATE_EGG) {
        event_any_to_egg_block = block;
    }
    if ((LifeStage_t)from == STATE_EGG && (LifeStage_t)to == STATE_HATCHING) {
        event_egg_to_hatching_block = block;
    }
    if ((LifeStage_t)from == STATE_HATCHING && (LifeStage_t)to == STATE_HATCHED) {
        event_hatching_to_hatched_block = block;
    }

    mrb_gc_register(mrb, block);

    return mrb_nil_value();
}

void init_mruby_env(mrb_state* mrb) {
    event_any_to_egg_block = mrb_nil_value();
    event_egg_to_hatching_block = mrb_nil_value();
    event_hatching_to_hatched_block = mrb_nil_value();

    struct RClass *game_module = mrb_define_module(mrb, "Game");

    struct RClass *game_save_state_module = mrb_define_module_under(mrb, game_module, "SaveState");
    mrb_define_module_function(mrb, game_save_state_module, "load", mrb_game_save_state_load, MRB_ARGS_REQ(1));

    struct RClass *game_state_module = mrb_define_module_under(mrb, game_module, "GameState");
    mrb_define_module_function(mrb, game_state_module, "state=", mrb_game_state_set_state, MRB_ARGS_REQ(1));
    mrb_define_module_function(mrb, game_state_module, "transition_to", mrb_game_state_transition_to, MRB_ARGS_REQ(2));

    struct RClass *game_events_module = mrb_define_module_under(mrb, game_module, "Events");
    mrb_define_module_function(mrb, game_events_module, "state_change", mrb_game_events_state_change, MRB_ARGS_REQ(3));

    // TODO: Move to Ruby API script
    struct RClass *game_constants_module = mrb_define_module_under(mrb, game_module, "Constants");
    struct RClass *game_constants_states_module = mrb_define_module_under(mrb, game_constants_module, "States");
    mrb_define_const(mrb, game_constants_states_module, "ANY", mrb_fixnum_value(STATE_ANY));
    mrb_define_const(mrb, game_constants_states_module, "EGG", mrb_fixnum_value(STATE_EGG));
    mrb_define_const(mrb, game_constants_states_module, "HATCHING", mrb_fixnum_value(STATE_HATCHING));
    mrb_define_const(mrb, game_constants_states_module, "HATCHED", mrb_fixnum_value(STATE_HATCHED));
}

void mruby_task(void *pvParameter)
{
    mrb_state *mrb = mrb_open();
    mrbc_context *context = mrbc_context_new(mrb);
    int ai = mrb_gc_arena_save(mrb);
    init_mruby_env(mrb);
    mrb_load_irep_cxt(mrb, app_mrb, context);
    if (mrb->exc)
    {
        ESP_LOGE(MRUBY_TAG, "Exception occurred: %s", mrb_str_to_cstr(mrb, mrb_inspect(mrb, mrb_obj_value(mrb->exc))));
        mrb->exc = 0;
    }
    else
    {
        ESP_LOGI(MRUBY_TAG, "%s", "Success");
    }

    while(true) {
        vTaskDelay(10000/portTICK_PERIOD_MS);
    }

    mrb_gc_arena_restore(mrb, ai);
    mrbc_context_free(mrb, context);
    mrb_close(mrb);

    vTaskDelete(NULL);
}

void ruby_fn_call_task(void* param) {
    while(true) {
        RubyFnCall_t ruby_fn_call;
        if(xQueueReceive(ruby_fn_call_queue, &ruby_fn_call, (TickType_t)(portTICK_PERIOD_MS * 10000))) {
            if (!mrb_nil_p(ruby_fn_call.method)) {
                mrb_funcall(ruby_fn_call.mrb, ruby_fn_call.method, "call", 0);
            }
        }
    }

    vTaskDelete(NULL);
}

void simulate_task(void *pvParameter){
    while(true){
        // Egg
        game_state.state = STATE_EGG;
        render();
        vTaskDelay(5000 / portTICK_PERIOD_MS);

        // Hatching...
        game_state.state = STATE_HATCHING;
        render();
        vTaskDelay(3000 / portTICK_PERIOD_MS);

        // Hatched!
        game_state.state = STATE_HATCHED;
        render();
        vTaskDelay(3000 / portTICK_PERIOD_MS);
    }

    vTaskDelete(NULL);
}

void animate_task(void *pvParameter){
    while(true){
        send_to_display_queue();
        vTaskDelay(game_state.animation_tick / portTICK_PERIOD_MS);
        RenderedSprite_t *rendered_p = &game_state.rendered_sprites[0]; // TODO: iterate over multiple
        rendered_p->elapsed_ms = rendered_p->elapsed_ms + game_state.animation_tick;
        Sprite_t sprite = rendered_p->sprite;
        if (rendered_p->elapsed_ms > sprite.frame_length) {
            if (sprite.max_frame > rendered_p->current_frame || sprite.loop) {
                rendered_p->current_frame = (rendered_p->current_frame + 1) % (sprite.max_frame + 1); // TODO: handle min_frame
            }
            rendered_p->elapsed_ms = 0; // TODO: this is a rough approximation
        }
    }

    vTaskDelete(NULL);
}

void display_task(void* param) {
    struct SSD1306_Device* display = (struct SSD1306_Device*)param;
    SSD1306_SetFont(display, FontList[1]);

    while(true) {
        GameState_t state;
        if(xQueueReceive(display_queue, &state, (TickType_t)(portTICK_PERIOD_MS * 10000))) {
            SSD1306_Clear(display, SSD_COLOR_BLACK);
            draw_frame(display, state);
            SSD1306_Update(display);
        }
    }

    vTaskDelete(NULL);
}

void app_main(void) {
    vTaskDelay(1000 / portTICK_PERIOD_MS);

    RenderedSprite_t rendered = { .sprite = egg_sprite, .x = (128 / 2) - (32 / 2 ), .y = (64 / 2) - (32 / 2), .current_frame = 0 };
    game_state.rendered_sprites[0] = rendered;
    game_state.animation_tick = 100;

    display_queue = xQueueCreate(10, sizeof(GameState_t));
    ruby_fn_call_queue = xQueueCreate(10, sizeof(RubyFnCall_t));

    init_oled();

    xTaskCreate(&mruby_task, "mruby_task", 16000, NULL, 1, NULL);
    xTaskCreate(&ruby_fn_call_task, "ruby_fn_call_task", 32000, NULL, 2, NULL);
    xTaskCreate(&animate_task, "animate_task", 2048, NULL, 3, NULL);
    xTaskCreate(&display_task, "display_task", 2048, &I2CDisplay, 4, NULL);
    // xTaskCreate(&simulate_task, "simulate_task", 2048, NULL, 5, NULL);
}