COMBO_ENABLE = yes
# markstos: smaller file size, little down-side
VPATH  +=  keyboards/gboards/
# Purely a compile-time size optimization (no behavior change) -- needed to
# fit under the AVR flash limit once the taipo combos are included.
LTO_ENABLE = yes
UNICODE_ENABLE = no
OLED_ENABLE = no
GRAVE_ESC_ENABLE = no
SPACE_CADET_ENABLE = no
MAGIC_ENABLE = no
CAPS_WORD_ENABLE = no

RAW_ENABLE = yes
VIA_ENABLE=yes
