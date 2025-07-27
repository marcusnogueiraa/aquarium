#include <stdio.h>
#include "pico/stdlib.h"
#include "FreeRTOS.h"
#include "task.h"

#include "ow_rom.h"
#include "ds18b20.h"
#include "temperature_control.h"
#include "water_level_control.h"

#define HIGH_PRIORITY 3
#define MEDIUM_PRIORITY 2
#define LOW_PRIORITY 1

int main(void) {
    stdio_init_all();

    xTaskCreate(level_sensor_task, "WaterControlTask", 2048, NULL, HIGH_PRIORITY, NULL);
    xTaskCreate(temperature_control_task, "TempControlTask", 2048, NULL, HIGH_PRIORITY, NULL);

    vTaskStartScheduler();
    return 0;
}
