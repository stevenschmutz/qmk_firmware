CLTO_ENABLE = yes
COMBO_ENABLE = yes
CONSOLE_ENABLE = yes
APS_WORD_ENABLE = yes
CUSTOM_MATRIX = lite
WS2812_DRIVER = vendor
RGBLIGHT_ENABLE = yes
DEFERRED_EXEC_ENABLE = yes
OLED_ENABLE = yes
OLED_DRIVER = ssd1306
OPT_DEFS += -DHAL_USE_I2C=TRUE
OLED_TRANSPORT = i2c
SRC += matrix.c
