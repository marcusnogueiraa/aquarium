#include <stdio.h>
#include "pico/stdlib.h"
#include "FreeRTOS.h"
#include "task.h"

#include "onewire_library.h"  // Biblioteca de leitura de temperatura
#include "ow_rom.h"
#include "ds18b20.h"
#include "temperature_control.h"


#define HIGH_PRIORITY 3
#define MEDIUM_PRIORITY 2
#define LOW_PRIORITY

int main(void) {
    stdio_init_all();

    // Cria a tarefa de controle de temperatura
    xTaskCreate(temperature_control_task, "TempControlTask", 2048, NULL, HIGH_PRIORITY, NULL);

    // Inicia o agendador FreeRTOS
    vTaskStartScheduler();
    return 0;
}
