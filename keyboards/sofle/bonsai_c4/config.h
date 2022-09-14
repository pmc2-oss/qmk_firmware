#pragma once

#include "config_common.h"

// Key matrix size, (rows are doubled-up)
#define MATRIX_ROWS 10
#define MATRIX_COLS 6

// Pins for rows and cols
#define MATRIX_ROW_PINS { B8, A3, B10, A8, B0 }
#define MATRIX_COL_PINS { A5, A1, B13, B14, B15, B1 }
#define DIODE_DIRECTION COL2ROW

// Timing parameters
#define TAPPING_TERM 100
#define DEBOUNCE 5

// Encoder support
#define ENCODERS_PAD_A { A6 }
#define ENCODERS_PAD_B { A7 }
#define ENCODERS_PAD_A_RIGHT { A7 }
#define ENCODERS_PAD_B_RIGHT { A6 }
#define ENCODER_RESOLUTION 2

// For macros, this indicates how long to wait before unregister the tap.
#define TAP_CODE_DELAY 10

// Communication between sides
#define USE_SERIAL
#define SOFT_SERIAL_PIN A15
#define SELECT_SOFT_SERIAL_SPEED 1
#define SERIAL_USART_DRIVER SD1
#define SERIAL_USART_TX_PAL_MODE 7
#define SERIAL_USART_TIMEOUT 20
// These three parameters set up for full duplex
#define SERIAL_USART_FULL_DUPLEX
#define SERIAL_USART_RX_PIN B7
#define SERIAL_USART_RX_PAL_MODE 7

// EEPROM / FRAM configuration
#define EXTERNAL_EEPROM_SPI_SLAVE_SELECT_PIN A0
// Divisor, 48MHz / 4 = 12MHz; max supported by MB85R64 is 20MHz
#define EXTERNAL_EEPROM_SPI_CLOCK_DIVISOR 4
#define EXTERNAL_EEPROM_BYTE_COUNT 8192
// Page size does not matter for FRAM, just sets the RAM buffer size in STM32F chip
#define EXTERNAL_EEPROM_PAGE_SIZE 64
#define DYNAMIC_KEYMAP_EEPROM_MAX_ADDR 8191

// External flash configuration
#define EXTERNAL_FLASH_SPI_SLAVE_SELECT_PIN B12
// Divisor, 48MHz; max supported by W25Q128JV is 133MHz
#define EXTERNAL_FLASH_SPI_CLOCK_DIVISOR 1
// Byte count: 128Mbit or 16MByte
#define EXTERNAL_FLASH_BYTE_COUNT (16 * 1024 * 1024)
#define EXTERNAL_FLASH_PAGE_SIZE 256
// Timeout, datasheet max is 200 seconds for flash chip erase
#define EXTERNAL_FLASH_SPI_TIMEOUT 200000

// SPI Configuration (needed for FRAM and FLASH)
#define SPI_DRIVER SPID1
#define SPI_SCK_PIN B3
#define SPI_SCK_PAL_MODE 5
#define SPI_MOSI_PIN B5
#define SPI_MOSI_PAL_MODE 5
#define SPI_MISO_PIN B4
#define SPI_MISO_PAL_MODE 5

// I2C Configuration for OLED
#define I2C_DRIVER I2CD1
#define I2C1_SCL_PIN B6
#define I2C1_SDA_PIN B9
#define I2C1_SCL_PAL_MODE 4
#define I2C1_SDA_PAL_MODE 4
#define I2C1_CLOCK_SPEED 100000
#define I2C1_DUTY_CYCLE STD_DUTY_CYCLE
