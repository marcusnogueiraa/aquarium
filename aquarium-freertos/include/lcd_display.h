#ifndef LCD_DISPLAY_H
#define LCD_DISPLAY_H

#include "FreeRTOS.h"
#include "queue.h"

// Fila para envio de mensagens ao display
extern QueueHandle_t DisplayQueue;

// Inicialização do display
void lcd_display_init();

// Task que escuta a fila e mostra no LCD
void lcd_display_task(void *pvParameters);

#endif
