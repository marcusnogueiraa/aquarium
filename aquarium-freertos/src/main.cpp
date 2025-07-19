#include <stdio.h>
#include "pico/stdlib.h"
#include "FreeRTOS.h"
#include "task.h"

void task_serial(void *pvParameters) {
    while (true) {
        printf("🟢 Olá do FreeRTOS!\n");
        vTaskDelay(pdMS_TO_TICKS(1000));  // Aguarda 1 segundo
    }
}

int main() {
    stdio_init_all(); // Inicializa UART e USB

    xTaskCreate(task_serial, "SerialTask", 1024, NULL, 1, NULL);

    vTaskStartScheduler();  // Inicia o agendador FreeRTOS

    while (true);  // Nunca chega aqui
    return 0;
}
