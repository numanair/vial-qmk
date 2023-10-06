VIA_ENABLE = yes
VIAL_ENABLE = yes

VIALRGB_ENABLE = yes

ifeq ($(strip $(MCU)), atmega32u4)
    QMK_SETTINGS = no
    COMBO_ENABLE = no
    MOUSEKEY_ENABLE = no
    TAP_DANCE_ENABLE = no
    SPACE_CADET_ENABLE = no
    GRAVE_ESC_ENABLE = no
    KEY_OVERRIDE_ENABLE = no
    MAGIC_ENABLE = no
endif
