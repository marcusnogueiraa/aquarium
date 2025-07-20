#include <stdio.h>
#include "pico/stdlib.h"
#include "pico/binary_info.h"
#include "FreeRTOS.h"
#include "task.h"

#include "onewire_library.h"
#include "ow_rom.h"
#include "ds18b20.h"

void temperature_task(void *pvParameters) {
    stdio_init_all();

    PIO pio = pio0;
    uint gpio = 15;

    OW ow;
    uint offset;

    if (!pio_can_add_program(pio, &onewire_program)) {
        printf("Erro: não foi possível adicionar o programa PIO\n");
        vTaskDelete(NULL);
    }

    offset = pio_add_program(pio, &onewire_program);

    if (!ow_init(&ow, pio, offset, gpio)) {
        printf("Erro: falha na inicialização do driver OW\n");
        vTaskDelete(NULL);
    }

    const int maxdevs = 10;
    uint64_t romcode[maxdevs];
    int num_devs = ow_romsearch(&ow, romcode, maxdevs, OW_SEARCH_ROM);

    printf("Encontrados %d dispositivos\n", num_devs);
    for (int i = 0; i < num_devs; i++) {
        printf("\t%d: 0x%llx\n", i, romcode[i]);
    }
    printf("\n");

    while (num_devs > 0) {
        ow_reset(&ow);
        ow_send(&ow, OW_SKIP_ROM);
        ow_send(&ow, DS18B20_CONVERT_T);

        // Aguarda conversão (~750ms)
        vTaskDelay(pdMS_TO_TICKS(800));

        for (int i = 0; i < num_devs; i++) {
            ow_reset(&ow);
            ow_send(&ow, OW_MATCH_ROM);
            for (int b = 0; b < 64; b += 8) {
                ow_send(&ow, romcode[i] >> b);
            }
            ow_send(&ow, DS18B20_READ_SCRATCHPAD);

            int16_t temp = ow_read(&ow) | (ow_read(&ow) << 8);
            printf("\tSensor %d: %.2f°C\n", i, temp / 16.0);
        }

        printf("\n");
        vTaskDelay(pdMS_TO_TICKS(5000));
    }

    vTaskDelete(NULL);
}

int main(void) {
    stdio_init_all();

    xTaskCreate(temperature_task, "TempTask", 2048, NULL, 1, NULL);
    vTaskStartScheduler();
}
