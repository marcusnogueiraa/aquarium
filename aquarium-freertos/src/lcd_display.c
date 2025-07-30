#include "lcd_display.h"
#include "hardware/i2c.h"
#include "pico/stdlib.h"
#include "pico/binary_info.h"
#include <string.h>
#include <stdio.h>

#define LCD_CLEARDISPLAY 0x01
#define LCD_RETURNHOME 0x02
#define LCD_ENTRYMODESET 0x04
#define LCD_DISPLAYCONTROL 0x08
#define LCD_CURSORSHIFT 0x10
#define LCD_FUNCTIONSET 0x20
#define LCD_SETCGRAMADDR 0x40
#define LCD_SETDDRAMADDR 0x80
#define LCD_ENTRYLEFT 0x02
#define LCD_DISPLAYON 0x04
#define LCD_2LINE 0x08
#define LCD_BACKLIGHT 0x08
#define LCD_ENABLE_BIT 0x04

#define LCD_COMMAND 0
#define LCD_CHARACTER 1
#define MAX_LINES 2
#define MAX_CHARS 16

static const int addr = 0x27; 

QueueHandle_t DisplayQueue; 

static void i2c_write_byte(uint8_t val) {
    i2c_write_blocking(i2c_default, addr, &val, 1, false);
}

static void lcd_toggle_enable(uint8_t val) {
    sleep_us(600);
    i2c_write_byte(val | LCD_ENABLE_BIT);
    sleep_us(600);
    i2c_write_byte(val & ~LCD_ENABLE_BIT);
    sleep_us(600);
}

static void lcd_send_byte(uint8_t val, int mode) {
    uint8_t high = mode | (val & 0xF0) | LCD_BACKLIGHT;
    uint8_t low = mode | ((val << 4) & 0xF0) | LCD_BACKLIGHT;

    i2c_write_byte(high);
    lcd_toggle_enable(high);
    i2c_write_byte(low);
    lcd_toggle_enable(low);
}

static void lcd_clear(void) {
    lcd_send_byte(LCD_CLEARDISPLAY, LCD_COMMAND);
}

static void lcd_set_cursor(int line, int pos) {
    int addr = (line == 0) ? 0x80 + pos : 0xC0 + pos;
    lcd_send_byte(addr, LCD_COMMAND);
}

static void lcd_char(char val) {
    lcd_send_byte(val, LCD_CHARACTER);
}

static void lcd_string(const char *s) {
    while (*s) lcd_char(*s++);
}

void lcd_display_init() {
    i2c_init(i2c_default, 100 * 1000);
    gpio_set_function(PICO_DEFAULT_I2C_SDA_PIN, GPIO_FUNC_I2C);
    gpio_set_function(PICO_DEFAULT_I2C_SCL_PIN, GPIO_FUNC_I2C);
    gpio_pull_up(PICO_DEFAULT_I2C_SDA_PIN);
    gpio_pull_up(PICO_DEFAULT_I2C_SCL_PIN);

    lcd_send_byte(0x03, LCD_COMMAND);
    lcd_send_byte(0x03, LCD_COMMAND);
    lcd_send_byte(0x03, LCD_COMMAND);
    lcd_send_byte(0x02, LCD_COMMAND);

    lcd_send_byte(LCD_ENTRYMODESET | LCD_ENTRYLEFT, LCD_COMMAND);
    lcd_send_byte(LCD_FUNCTIONSET | LCD_2LINE, LCD_COMMAND);
    lcd_send_byte(LCD_DISPLAYCONTROL | LCD_DISPLAYON, LCD_COMMAND);
    lcd_clear();

    DisplayQueue = xQueueCreate(4, sizeof(char[33])); 
}

void lcd_display_task(void *pvParameters) {
    char message[33]; 

    while (1) {
        if (xQueueReceive(DisplayQueue, &message, portMAX_DELAY)) {
            printf("[LCD] Mensagem recebida: %s\n", message); 

            lcd_clear();
            lcd_set_cursor(0, 0);
            lcd_string(message);

            char *newline = strchr(message, '\n');
            if (newline && *(newline + 1)) {
                lcd_set_cursor(1, 0);
                lcd_string(newline + 1);
            }
        }
    }
}
