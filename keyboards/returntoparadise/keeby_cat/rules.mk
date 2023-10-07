# MCU name
MCU = STM32F103
# Bootloader for 64k STM32
# BOOTLOADER = stm32duino
BOOTLOADER = stm32duino

# Custom loader configuration for 128k STM32
MCU_LDSCRIPT = STM32F103xB
OPT_DEFS += -DBOOTLOADER_STM32DUINO
BOARD = STM32_F103_STM32DUINO
BOOTLOADER_TYPE = stm32duino
DFU_ARGS = -d 1EAF:0003 -a 2 -R
DFU_SUFFIX_ARGS = -v 1EAF -p 0003

# Build Options

BOOTMAGIC_ENABLE = no
MOUSEKEY_ENABLE = yes       # Mouse keys
EXTRAKEY_ENABLE = yes       # Audio control and System control
CONSOLE_ENABLE = no         # Console for debug
COMMAND_ENABLE = no         # Commands for debug and configuration
# Do not enable SLEEP_LED_ENABLE. it uses the same timer as BACKLIGHT_ENABLE
SLEEP_LED_ENABLE = no       # Breathing sleep LED during USB suspend
# if this doesn't work, see here: https://github.com/tmk/tmk_keyboard/wiki/FAQ#nkro-doesnt-work
NKRO_ENABLE = no            # USB Nkey Rollover
MIDI_ENABLE = yes           # MIDI support
UNICODE_ENABLE = no         # Unicode
BLUETOOTH_ENABLE = no       # Enable Bluetooth with the Adafruit EZ-Key HID
AUDIO_ENABLE = no           # Audio output on port C6
FAUXCLICKY_ENABLE = no      # Use buzzer to emulate clicky switches
RGBLIGHT_ENABLE = no        # RGB underglow
RGB_MATRIX_ENABLE = yes     # RGB key lights
RGB_MATRIX_DRIVER = ws2812  # RGB LED driver
TAP_DANCE_ENABLE = yes
OLED_ENABLE = yes           # SSD1306 128x32
OLED_DRIVER_ENABLE = yes
OLED_DRIVER = ssd1306

# Enter lower-power sleep mode when on the ChibiOS idle thread
OPT_DEFS += -DCORTEX_ENABLE_WFI_IDLE=TRUE
