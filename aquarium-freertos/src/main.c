#include <stdio.h>
#include "pico/stdlib.h"
#include "FreeRTOS.h"
#include "task.h"

#include "ow_rom.h"
#include "ds18b20.h"
#include "temperature_control.h"
#include "water_level_control.h"

#include "pico/cyw43_arch.h"
#include "http_client_util.h" 

#include "lcd_display.h"

#define HIGH_PRIORITY 3
#define MEDIUM_PRIORITY 2
#define LOW_PRIORITY 1

#define WIFI_SSID "SMARTUFC"
#define WIFI_PASSWORD "#smart@1020"

#define HOST "example.com"
#define URL "/"

void http_task(void *params) {
    EXAMPLE_HTTP_REQUEST_T req = {0};
    req.hostname = HOST;
    req.url = URL;
    req.headers_fn = http_client_header_print_fn;
    req.recv_fn = http_client_receive_print_fn;

    printf("Iniciando requisição HTTP...\n");
    int result = http_client_request_sync(cyw43_arch_async_context(), &req);
    if (result == 0) {
        printf("\nHTTP finalizado com sucesso.\n");
    } else {
        printf("\nErro HTTP: %d\n", result);
    }

    vTaskDelete(NULL);
}

int main(void) {
    stdio_init_all();

    if (cyw43_arch_init()) {
        printf("Erro ao inicializar o Wi-Fi\n");
        return 1;
    }

    cyw43_arch_enable_sta_mode();

    if (cyw43_arch_wifi_connect_timeout_ms(
            WIFI_SSID, WIFI_PASSWORD,
            CYW43_AUTH_WPA2_AES_PSK, 30000)) {
        printf("Erro ao conectar na rede Wi-Fi\n");
        return 1;
    }

    lcd_display_init();

    printf("Conectado ao Wi-Fi: %s\n", WIFI_SSID);

    xTaskCreate(level_sensor_task, "WaterControlTask", 2048, NULL, HIGH_PRIORITY, NULL);
    xTaskCreate(temperature_control_task, "TempControlTask", 2048, NULL, HIGH_PRIORITY, NULL);
    xTaskCreate(lcd_display_task, "LCD", 1024, NULL, 1, NULL);
    //xTaskCreate(http_task, "HTTP", 4096, NULL, MEDIUM_PRIORITY, NULL);

    char msg[33] = "Temperatura:\n26.5 C";
    xQueueSend(DisplayQueue, &msg, 0);

    vTaskStartScheduler();
    return 0;
}
