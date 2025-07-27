#include <stdio.h>
#include "water_level_control.h"
#include "hardware/gpio.h"

static bool current_level = false;

void level_sensor_task(void *pvParameters) {
    gpio_init(LEVEL_SENSOR_PIN);
    gpio_set_dir(LEVEL_SENSOR_PIN, GPIO_IN);
    gpio_pull_up(LEVEL_SENSOR_PIN); 

    while(1) {
        current_level = !gpio_get(LEVEL_SENSOR_PIN);
        printf("%d\n", current_level);
        vTaskDelay(pdMS_TO_TICKS(100)); 
    }
}

bool get_liquid_level(void) {
    return current_level;
}