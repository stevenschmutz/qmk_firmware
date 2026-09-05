COMBO_ENABLE = yes
# markstos: smaller file size, little down-side
VPATH  +=  keyboards/gboards/
# Purely a compile-time size optimization (no behavior change) -- needed to
# fit under the AVR flash limit once the taipo combos are included.
LTO_ENABLE = yes

ARTSEY_ENABLE = no
TAIPO_ENABLE = no
# Nothing in this keymap's active combos.def chain (taipo.def only, no
# artsey.def) ever calls UC() -- the one UC() in aliases.c (SYM_1_4) is dead
# code left over from copying the stevenschmutz userspace. Disabling this
# recovers flash needed to fit the taipo combos.
UNICODE_ENABLE = no
OLED_ENABLE = no
GRAVE_ESC_ENABLE = no
SPACE_CADET_ENABLE = no
MAGIC_ENABLE = no
CAPS_WORD_ENABLE = no

RAW_ENABLE = yes
VIA_ENABLE=yes
