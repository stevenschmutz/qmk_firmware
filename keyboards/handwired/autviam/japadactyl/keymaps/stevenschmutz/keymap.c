#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum layers {
    _DVORAK,
};

enum custom_keycodes {
    CTRL_TICK,
};

#include "aliases.c"
#include "g/keymap_combo.h"

/*
// copied from https://beta.docs.qmk.fm/faqs/faq_debug#which-matrix-position-is-this-keypress
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  // If console is enabled, it will print the matrix position and status of each key pressed
#ifdef CONSOLE_ENABLE
    uprintf("KL: kc: 0x%04X, col: %u, row: %u, pressed: %b, time: %u, interrupt: %b, count: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed, record->event.time, record->tap.interrupted, record->tap.count);
#endif
  return true;
}
*/
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[_DVORAK] = LAYOUT_ortho_5x4 (
            //,-----------------------------------------------------.                 
             LGUI_T(KC_QUOT), KC_COMM, KC_DOT, KC_P, KC_Y,                         
              //,-----------------------------------------------------.              
             KC_A, KC_O, KC_E, KC_U, KC_I,                                    
              //,-----------------------------------------------------.            
           LSFT_T(KC_SCLN), KC_Q, KC_J, KC_K, KC_X,                
              //,-----------------------------------------------------.          
                         LSFT_T(KC_TAB), KC_SPC, KC_TRNS),                



};


bool process_record_user(uint16_t keycode, keyrecord_t* record) {
  switch (keycode) {
    case CTRL_TICK:  // Types ctrl + backtick
      if (record->event.pressed) {
        SEND_STRING(SS_LCTL("`"));
      }
      return false;
  }
  return true;
}


