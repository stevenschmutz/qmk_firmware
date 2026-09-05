#include QMK_KEYBOARD_H
#include "custom.h"


// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum layers {
 _TAIPO,
};


#include "sm_td.h"
#include "aliases.c"
#include "g/keymap_combo.h"
#include "macros.h"
#include "tapdance.ref"
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  // Default taipo flavor (see users/steventaipo/taipo_default.def). Both
  // hands carry the same letters -- combos.def-based combos match by
  // keycode, not physical position, so either hand (or a mix of both)
  // can form any chord.
  [_TAIPO] = LAYOUT_split_3x6_3(
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        //,
        KC_NO, KC_R,          KC_S,      KC_N,         KC_I,   KC_NO,          KC_NO,   KC_I,       KC_N,       KC_S,       KC_R,   KC_NO,
        KC_NO, KC_A,          KC_O,      KC_T,         KC_E,    KC_NO,         KC_NO,    KC_E,       KC_T,       KC_O,       KC_A,   KC_NO,
                                  KC_NO, KC_BSPC,      KC_SPC,                 KC_NO,  KC_SPC,     KC_BSPC
    ),

};

void housekeeping_task_user(void) {
  layer_lock_task();
  // Other tasks ...
}
