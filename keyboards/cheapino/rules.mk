CLTO_ENABLE = yes
COMBO_ENABLE = yes
CAPS_WORD_ENABLE = yes
CUSTOM_MATRIX = lite
WS2812_DRIVER = vendor
RGBLIGHT_ENABLE = yes
DEFERRED_EXEC_ENABLE = yes
SRC += encoder.c
SRC += matrix.c
SRC += features/layer_lock.c
MOUSE_ENABLE = yes
LAYER_LOCK_ENABLE = yes
ARTSEY_ENABLE = yes
TAIPO_ENABLE = yes

SRC += taipo.c