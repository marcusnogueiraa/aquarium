#include "temperature_control.h"
#include "ow_rom.h"
#include "ds18b20.h"
#include <stdio.h>

#define TEMP_GPIO_PIN 15
#define TEMP_READ_INTERVAL_MS 1000
#define TEMP_CONVERSION_DELAY_MS 800
#define INVALID_TEMPERATURE -127.0f

static OW ow;
static uint64_t device_romcode = 0;
static float current_temperature = INVALID_TEMPERATURE;
static bool sensor_found = false;

static bool verify_crc(uint64_t romcode) {
    return (romcode & 0xFF) == 0x28;
}

static bool init_onewire_bus(void) {
    PIO pio = pio0;
    uint offset = pio_add_program(pio, &onewire_program);
    
    if (!ow_init(&ow, pio, offset, TEMP_GPIO_PIN)) {
        printf("Falha na inicialização do barramento 1-Wire\n");
        return false;
    }
    return true;
}

static bool find_first_device(void) {
    uint64_t romcode;
    if (ow_romsearch(&ow, &romcode, 1, OW_SEARCH_ROM) > 0) {
        if (verify_crc(romcode)) {
            device_romcode = romcode;
            printf("DS18B20 encontrado (ROM: 0x%016llx)\n", romcode);
            return true;
        }
        printf("Dispositivo não é um DS18B20 válido\n");
    }
    printf("Nenhum sensor encontrado\n");
    return false;
}

static bool read_temperature(float *temp) {
    if (!ow_reset(&ow)) return false;
    ow_send(&ow, OW_SKIP_ROM);
    ow_send(&ow, DS18B20_CONVERT_T);
    
    vTaskDelay(pdMS_TO_TICKS(TEMP_CONVERSION_DELAY_MS));
    
    if (!ow_reset(&ow)) return false;
    ow_send(&ow, OW_MATCH_ROM);
    for (int b = 0; b < 64; b += 8) {
        ow_send(&ow, device_romcode >> b);
    }
    ow_send(&ow, DS18B20_READ_SCRATCHPAD);
    
    int16_t raw = ow_read(&ow) | (ow_read(&ow) << 8);
    
    if (raw == 0xFFFF || raw == 0) return false;
    
    *temp = (float)raw / 16.0f;
    return true;
}

float get_temperature(void) {
    return sensor_found ? current_temperature : INVALID_TEMPERATURE;
}

void temperature_control_task(void *pvParameters) {
    stdio_init_all();
    printf("Iniciando tarefa de temperatura...\n");

    if (!init_onewire_bus() || !find_first_device()) {
        vTaskDelete(NULL);
        return;
    }

    sensor_found = true;
    
    while (true) {
        float temp;
        if (read_temperature(&temp)) {
            current_temperature = temp;
            printf("Temperatura: %.2f°C (Raw: 0x%04x)\n", 
                  temp, (int16_t)(temp * 16));
        } else {
            printf("Erro na leitura!\n");
            current_temperature = INVALID_TEMPERATURE;
        }
        
        vTaskDelay(pdMS_TO_TICKS(TEMP_READ_INTERVAL_MS));
    }
}