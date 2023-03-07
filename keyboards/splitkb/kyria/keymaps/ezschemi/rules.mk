OLED_ENABLE = yes
OLED_DRIVER = SSD1306   # Enables the use of OLED displays
ENCODER_ENABLE = yes      # Enables the use of one or more encoders
RGBLIGHT_ENABLE = yes      # Enable keyboard RGB underglow

# from https://docs.qmk.fm/#/squeezing_avr?id=oled-tweaks
LTO_ENABLE = yes

# when using KC_VOLU and KC_WH_D for e.g. encoders
EXTRAKEY_ENABLE = yes
MOUSEKEY_ENABLE = yes

VPATH += keyboards/gboards/
COMBO_ENABLE = yes