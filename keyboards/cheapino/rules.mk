CLTO_ENABLE = yes
COMBO_ENABLE = yes
APS_WORD_ENABLE = yes
CAPS_WORD_ENABLE = yes
CUSTOM_MATRIX = lite
WS2812_DRIVER = vendor
RGBLIGHT_ENABLE = yes
DEFERRED_EXEC_ENABLE = yes
SRC += encoder.c
SRC += matrix.c
SRC += features/orbital_mouse.c
SRC += features/sentence_case.c
MOUSE_ENABLE = yes
