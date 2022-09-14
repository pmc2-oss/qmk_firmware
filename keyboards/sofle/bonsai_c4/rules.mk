# MCU name
MCU = STM32F411
BOARD = BONSAI_C4
BOOTLOADER = stm32-dfu

# We're defining a split keyboard
SPLIT_KEYBOARD = yes

# Hold down top-row outermost key at powerup to erase EEPROM and start DFU
BOOTMAGIC_ENABLE = yes

# Enable mouse scrollwheel HID commands
MOUSEKEY_ENABLE = yes

# Bunch of extra key codes
EXTRAKEY_ENABLE = yes

# Output messages over USB/HID
CONSOLE_ENABLE = no

# Magic commands
COMMAND_ENABLE = yes

# Enables LED to breathe when computer is sleeping
SLEEP_LED_ENABLE = no

# Allow turning on NKRO
NKRO_ENABLE = no

# Enable support for audio
AUDIO_ENABLE = no

# output debug statements from the drivers/flash/flash_spi code
DEBUG_FLASH_SPI_OUTPUT = yes # MN check what this does

# Compiler: Whether to generate debug information
DEBUG_ENABLE = no

# Linker: Link time optimization
LTO_ENABLE = no

# Feature OLED driver
OLED_ENABLE = yes
OLED_DRIVER = SSD1306

# Feature Encoders
ENCODER_ENABLE = yes

# EEPROM through a SPI EEPROM chip
EEPROM_DRIVER = spi

# Split keyboard communication
SERIAL_DRIVER = usart
