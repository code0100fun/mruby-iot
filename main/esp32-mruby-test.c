#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"

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

#define MRUBY_TAG "mruby_task"
#define OLED_TAG "oled_task"

#define COLOR_PRINT_BLACK   "30"
#define COLOR_PRINT_RED     "31"
#define COLOR_PRINT_GREEN   "32"
#define COLOR_PRINT_BROWN   "33"
#define COLOR_PRINT_BLUE    "34"
#define COLOR_PRINT_PURPLE  "35"
#define COLOR_PRINT_CYAN    "36"
#define color_printf(COLOR,format, ... ) { printf("\033[0;" COLOR "m" format "\033[0m\n", ##__VA_ARGS__); }

static const int I2CDisplayAddress = 0x3C;
static const int I2CDisplayWidth = 128;
static const int I2CDisplayHeight = 64;
static const int I2CResetPin = -1;

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

struct GameState {
    const char* message;
};

QueueHandle_t game_state_queue = NULL;

bool init_oled(void) {
    assert(SSD1306_I2CMasterInitDefault());
    assert(SSD1306_I2CMasterAttachDisplayDefault(&I2CDisplay, I2CDisplayWidth, I2CDisplayHeight, I2CDisplayAddress, I2CResetPin ));
    return true;
}

void display_task(void* param) {
    struct SSD1306_Device* display = (struct SSD1306_Device*)param;
    SSD1306_SetFont(display, FontList[0]);

    while(true) {
        struct GameState state;
        xQueueReceive(game_state_queue, &(state), portMAX_DELAY);

        SSD1306_Clear(display, SSD_COLOR_BLACK);
        SSD1306_FontDrawAnchoredString(display, TextAnchor_Center,state.message, SSD_COLOR_WHITE);
        SSD1306_Update(display);

        vTaskDelay(pdMS_TO_TICKS(1000));
        color_printf(COLOR_PRINT_GREEN, "free DRAM %u IRAM %u", heap_caps_get_free_size(MALLOC_CAP_8BIT), heap_caps_get_free_size(MALLOC_CAP_32BIT));
    }

    ESP_LOGI(OLED_TAG, "%s", "oled task finished.");
    vTaskDelete(NULL);
}

static mrb_value mrb_game_display_write_text(mrb_state *mrb, mrb_value self) {
    char *message = NULL;
    mrb_get_args(mrb, "z", &message);
    struct GameState state;
    state.message = message;
    xQueueSend(game_state_queue, (void*)&state, portMAX_DELAY); 
    return self;
}


void init_mruby_env(mrb_state* mrb) {
    struct RClass *game_module = mrb_define_module(mrb, "Game");
    struct RClass *game_display_module = mrb_define_module_under(mrb, game_module, "Display");

    mrb_define_module_function(mrb, game_display_module, "write_text", mrb_game_display_write_text, MRB_ARGS_REQ(1));
}

void mruby_task(void *pvParameter)
{
    mrb_state *mrb = mrb_open();
    mrbc_context *context = mrbc_context_new(mrb);
    int ai = mrb_gc_arena_save(mrb);
    init_mruby_env(mrb);
    ESP_LOGI(MRUBY_TAG, "%s", "Loading binary...");
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
    mrb_gc_arena_restore(mrb, ai);
    mrbc_context_free(mrb, context);
    mrb_close(mrb);

    ESP_LOGI(MRUBY_TAG, "%s", "mruby task finished.");
    vTaskDelete(NULL);

}

void app_main(void) {
    game_state_queue = xQueueCreate(1, sizeof(struct GameState));
    if (init_oled()) {
        xTaskCreate(&display_task, "display_task", 4096, &I2CDisplay, 1, NULL);
    }
    xTaskCreate(&mruby_task, "mruby_task", 8192, NULL, 1, NULL);
}