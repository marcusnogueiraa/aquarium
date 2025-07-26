#include "temperature_control.h"
#include "ow_rom.h"
#include "ds18b20.h"
#include <stdio.h>

#define TEMP_TASK_PRIORITY 3
#define TEMP_GPIO_PIN 15
#define TEMP_READ_INTERVAL_MS 1000
#define TEMP_CONVERSION_DELAY_MS 800

static OW ow;
static uint64_t device_romcode = 0;
static float current_temperature = 0.0f;
static bool sensor_found = false;
static bool initialized = false;

static bool init_onewire_bus(void) {
    PIO pio = pio0;
    uint offset;

    if (!pio_can_add_program(pio, &onewire_program)) {
        printf("Erro: não foi possível adicionar o programa PIO\n");
        return false;
    }

    offset = pio_add_program(pio, &onewire_program);
    return ow_init(&ow, pio, offset, TEMP_GPIO_PIN);
}

static bool find_first_device(void) {
    uint64_t romcodes[1]; // Apenas precisamos de um dispositivo
    int found = ow_romsearch(&ow, romcodes, 1, OW_SEARCH_ROM);
    
    if (found > 0) {
        device_romcode = romcodes[0];
        printf("Dispositivo encontrado: 0x%llx\n", device_romcode);
        return true;
    }
    
    printf("Nenhum dispositivo encontrado\n");
    return false;
}

static float read_temperature(void) {
    // Inicia conversão
    ow_reset(&ow);
    ow_send(&ow, OW_SKIP_ROM);
    ow_send(&ow, DS18B20_CONVERT_T);
    
    // Aguarda a conversão
    vTaskDelay(pdMS_TO_TICKS(TEMP_CONVERSION_DELAY_MS));
    
    // Lê temperatura
    ow_reset(&ow);
    ow_send(&ow, OW_MATCH_ROM);
    
    for (int b = 0; b < 64; b += 8) {
        ow_send(&ow, device_romcode >> b);
    }
    
    ow_send(&ow, DS18B20_READ_SCRATCHPAD);
    int16_t temp = ow_read(&ow) | (ow_read(&ow) << 8);
    return temp / 16.0f;
}

float get_temperature(void) {
    if (!initialized || !sensor_found) {
        return -127.0f; // Valor inválido indicando erro
    }
    return current_temperature;
}

void temperature_task(void *pvParameters) {
    if (!init_onewire_bus()) {
        vTaskDelete(NULL);
        return;
    }

    sensor_found = find_first_device();
    initialized = true;

    while (sensor_found) {
        current_temperature = read_temperature();
        printf("Temperatura: %.2f°C\n", current_temperature);
        vTaskDelay(pdMS_TO_TICKS(TEMP_READ_INTERVAL_MS));
    }

    // todo: controle

    vTaskDelete(NULL);
}
