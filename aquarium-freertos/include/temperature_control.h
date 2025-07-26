#ifndef TEMPERATURE_CONTROL_H
#define TEMPERATURE_CONTROL_H

#include "pico/stdlib.h"
#include "FreeRTOS.h"
#include "task.h"
#include "onewire_library.h"

float get_temperature(void);
void temperature_control_task(void *pvParameters);

#endif