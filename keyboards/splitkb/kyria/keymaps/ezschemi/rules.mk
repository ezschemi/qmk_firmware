OLED_ENABLE = no 
OLED_DRIVER = SSD1306   # Enables the use of OLED displays
ENCODER_ENABLE = no # Enables the use of one or more encoders
RGBLIGHT_ENABLE = yes      # Enable keyboard RGB underglow

# from https://docs.qmk.fm/#/squeezing_avr?id=oled-tweaks
LTO_ENABLE = yes

WS2812_DRIVER = vendor

# when using KC_VOLU and KC_WH_D for e.g. encoders
EXTRAKEY_ENABLE = yes
MOUSEKEY_ENABLE = yes

#VPATH += keyboards/gboards/
#COMBO_ENABLE = yes
