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
#include "esp_task_wdt.h"

#include "sprite_sheet.h"

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

GameState_t game_state = { .state = STATE_EGG };
QueueHandle_t game_state_queue = NULL;

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

void send_state_update() {
    GameState_t state = game_state;
    xQueueSend(game_state_queue, (void*)&state, portMAX_DELAY);
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
    send_state_update();
}

bool init_oled(void) {
    assert(SSD1306_I2CMasterInitDefault());
    assert(SSD1306_I2CMasterAttachDisplayDefault(&I2CDisplay, I2CDisplayWidth, I2CDisplayHeight, I2CDisplayAddress, I2CResetPin ));
    return true;
}

void display_task(void* param) {
    struct SSD1306_Device* display = (struct SSD1306_Device*)param;
    SSD1306_SetFont(display, FontList[1]);

    while(true) {
        GameState_t state;
        if(xQueueReceive(game_state_queue, &state, (TickType_t)(portTICK_PERIOD_MS * 10000))) {
            SSD1306_Clear(display, SSD_COLOR_BLACK);
            draw_frame(display, state);
            SSD1306_Update(display);
        }
        esp_task_wdt_reset();
    }

    vTaskDelete(NULL);
}

void simulate_task(void *pvParameter){
    while(1){
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
}

void animate_task(void *pvParameter){
    while(1){
        send_state_update();
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
}

void app_main(void) {
    vTaskDelay(1000 / portTICK_PERIOD_MS);

    RenderedSprite_t rendered = { .sprite = egg_sprite, .x = (128 / 2) - (32 / 2 ), .y = (64 / 2) - (32 / 2), .current_frame = 0 };
    game_state.rendered_sprites[0] = rendered;
    game_state.animation_tick = 100;

    game_state_queue = xQueueCreate(10, sizeof(GameState_t));
    if (init_oled()) {
        xTaskCreate(&display_task, "display_task", 2048, &I2CDisplay, 1, NULL);
    }
    xTaskCreate(&animate_task, "animate_task", 2048, NULL, 2, NULL);
    xTaskCreate(&simulate_task, "simulate_task", 2048, NULL, 1, NULL);
}