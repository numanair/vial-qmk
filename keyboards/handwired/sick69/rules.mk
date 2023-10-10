# 128k STM32
MCU = STM32F103
BOOTLOADER = stm32duino
MCU_LDSCRIPT = STM32F103xB

# Build Options
BOOTMAGIC_ENABLE = no       # Enable Bootmagic Lite
MOUSEKEY_ENABLE = yes       # Mouse keys
EXTRAKEY_ENABLE = yes       # Audio control and System control
CONSOLE_ENABLE = no         # Console for debug
COMMAND_ENABLE = no         # Commands for debug and configuration
NKRO_ENABLE = yes           # Enable N-Key Rollover
UNICODE_ENABLE = yes

LAYOUTS = 65_ansi
