#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "driver/ledc.h"
#include "rom/gpio.h"

#define R_IS_GPIO 6
#define R_EN_GPIO 2
#define R_PWM_CHANNEL LEDC_CHANNEL_0
#define R_PWM_PIN GPIO_NUM_3

#define L_IS_GPIO 7
#define L_EN_GPIO 4
#define L_PWM_CHANNEL LEDC_CHANNEL_1
#define L_PWM_PIN GPIO_NUM_5

void setup() {
    gpio_config_t io_conf = {
        .pin_bit_mask = (1ULL<<R_IS_GPIO) | (1ULL<<R_EN_GPIO) | (1ULL<<R_PWM_PIN) |
                        (1ULL<<L_IS_GPIO) | (1ULL<<L_EN_GPIO) | (1ULL<<L_PWM_PIN),
        .mode = GPIO_MODE_OUTPUT,
        .intr_type = GPIO_PIN_INTR_DISABLE,
        .pull_down_en = GPIO_PULLDOWN_DISABLE,
        .pull_up_en = GPIO_PULLUP_DISABLE,
    };
    gpio_config(&io_conf);

    gpio_set_level(R_IS_GPIO, 0);
    gpio_set_level(L_IS_GPIO, 0);
    gpio_set_level(R_EN_GPIO, 1);
    gpio_set_level(L_EN_GPIO, 1);

    ledc_timer_config_t ledc_timer = {
        .speed_mode = LEDC_LOW_SPEED_MODE,
        .duty_resolution = LEDC_TIMER_8_BIT,
        .timer_num = LEDC_TIMER_0,
        .freq_hz = 5000,
        .clk_cfg = LEDC_AUTO_CLK,
    };
    ledc_timer_config(&ledc_timer);

    ledc_channel_config_t pwm_channel = {
        .gpio_num = R_PWM_PIN,
        .speed_mode = LEDC_LOW_SPEED_MODE,
        .channel = R_PWM_CHANNEL,
        .intr_type = LEDC_INTR_DISABLE,
        .timer_sel = LEDC_TIMER_0,
        .duty = 0,
        .hpoint = 0,
    };
    ledc_channel_config(&pwm_channel);

    pwm_channel.gpio_num = L_PWM_PIN;
    pwm_channel.channel = L_PWM_CHANNEL;
    ledc_channel_config(&pwm_channel);
}

void loop() {
    int i;
    //előre
    for(i = 0; i <= 100; i = i + 3){
        ledc_set_duty(LEDC_LOW_SPEED_MODE, R_PWM_CHANNEL, i);
        ledc_update_duty(LEDC_LOW_SPEED_MODE, R_PWM_CHANNEL);
        ledc_set_duty(LEDC_LOW_SPEED_MODE, L_PWM_CHANNEL, 0);
        ledc_update_duty(LEDC_LOW_SPEED_MODE, L_PWM_CHANNEL);
        vTaskDelay(100 / portTICK_PERIOD_MS);
    }
    vTaskDelay(1000 / portTICK_PERIOD_MS);
    //hátra
    for(i = 0; i <= 100; i = i + 3){
        ledc_set_duty(LEDC_LOW_SPEED_MODE, R_PWM_CHANNEL, 0);
        ledc_update_duty(LEDC_LOW_SPEED_MODE, R_PWM_CHANNEL);
        ledc_set_duty(LEDC_LOW_SPEED_MODE, L_PWM_CHANNEL, i);
        ledc_update_duty(LEDC_LOW_SPEED_MODE, L_PWM_CHANNEL);
        vTaskDelay(100 / portTICK_PERIOD_MS);
    }
    vTaskDelay(1000 / portTICK_PERIOD_MS);
}

void app_main() {
    setup();
    while (1) {
        loop();
    }
}
