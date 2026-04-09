#include "driver/gpio.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#define BUZZER_GPIO 17
#define LED_GREEN 32
#define LED_YELLOW 33
#define LED_RED 25

void setup_gpio(int pin) {
    esp_rom_gpio_pad_select_gpio(pin);
    gpio_set_direction(pin, GPIO_MODE_OUTPUT);
}

void app_main(void)
{
    // Configuração dos pinos
    setup_gpio(BUZZER_GPIO);
    setup_gpio(LED_GREEN);
    setup_gpio(LED_YELLOW);
    setup_gpio(LED_RED);

    while (1)
    {
        // ===== MODO VERDE =====
        gpio_set_level(LED_GREEN, 1);

        for (int i = 0; i < 5; i++) { // dura ~5 segundos
            gpio_set_level(BUZZER_GPIO, 1);
            vTaskDelay(pdMS_TO_TICKS(500));

            gpio_set_level(BUZZER_GPIO, 0);
            vTaskDelay(pdMS_TO_TICKS(500));
        }

        gpio_set_level(LED_GREEN, 0);

        // ===== MODO AMARELO =====
        gpio_set_level(LED_YELLOW, 1);

        for (int i = 0; i < 10; i++) { // dura ~5 segundos
            gpio_set_level(BUZZER_GPIO, 1);
            vTaskDelay(pdMS_TO_TICKS(200));

            gpio_set_level(BUZZER_GPIO, 0);
            vTaskDelay(pdMS_TO_TICKS(200));
        }

        gpio_set_level(LED_YELLOW, 0);

        // ===== MODO VERMELHO  =====
        gpio_set_level(LED_RED, 1);
        gpio_set_level(BUZZER_GPIO, 0);

        vTaskDelay(pdMS_TO_TICKS(5000)); // 5 segundos

        gpio_set_level(LED_RED, 0);
    }
}
//Feito por Lucas Espanhol