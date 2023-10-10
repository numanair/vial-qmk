# MCU name
MCU = STM32F103
# Bootloader for STM32
BOOTLOADER = stm32duino
# Configuration for 128k STM32
MCU_LDSCRIPT = STM32F103xB

# These should be already set in chibios/bootloader.mk
# BOARD = STM32_F103_STM32DUINO
# OPT_DEFS += -DBOOTLOADER_STM32DUINO
# DFU_ARGS = -d 1EAF:0003 -a 2 -R
# DFU_SUFFIX_ARGS ?= -v 1EAF -p 0003

# Build Options
# Some options have moved to info.json
BOOTMAGIC_ENABLE = no
# These options may require more USB endpoints
CONSOLE_ENABLE = no         # Console for debug
MIDI_ENABLE = yes           # MIDI support
# These ones are combined into a single endpoint
MOUSEKEY_ENABLE = yes       # Mouse keys
EXTRAKEY_ENABLE = yes       # Audio control and System control
NKRO_ENABLE = no            # USB Nkey Rollover, 6KRO when off. Must be turned on with bound key.
# Settings to reduce endpoint usage
KEYBOARD_SHARED_EP = yes    # Enable to combine keyboard endpoints. May break boot/bios keyboard usage.
MOUSE_SHARED_EP = yes       # Enable to combine mouse endpoints. May break bios mouse usage.

COMMAND_ENABLE = no         # Commands for debug and configuration
# Do not enable SLEEP_LED_ENABLE. it uses the same timer as BACKLIGHT_ENABLE
SLEEP_LED_ENABLE = no       # Breathing sleep LED during USB suspend
# if this doesn't work, see here: https://github.com/tmk/tmk_keyboard/wiki/FAQ#nkro-doesnt-work
UNICODE_ENABLE = yes        # Unicode
TAP_DANCE_ENABLE = yes
RGBLIGHT_ENABLE = no        # RGB underglow
RGB_MATRIX_ENABLE = yes     # RGB key lights
RGB_MATRIX_DRIVER = ws2812  # RGB LED driver
OLED_ENABLE = yes           # SSD1306 128x32
OLED_DRIVER_ENABLE = yes
OLED_DRIVER = ssd1306

# Enter lower-power sleep mode when on the ChibiOS idle thread
OPT_DEFS += -DCORTEX_ENABLE_WFI_IDLE=TRUE
