#ifndef WATER_LEVEL_SENSOR_H
#define WATER_LEVEL_SENSOR_H

#include "pico/stdlib.h"
#include "FreeRTOS.h"
#include "task.h"

#define LEVEL_SENSOR_PIN 14

void level_sensor_task(void *pvParameters);
bool get_liquid_level(void);

#endif