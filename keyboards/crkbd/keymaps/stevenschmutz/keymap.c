#include QMK_KEYBOARD_H
#include "custom.h"



// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum layers {
    _DVORAK,
    _NAV,
    _SYMBOL,
    _NUMERIC,
    _ART_MOU
};

#include "sm_td.h"
#include "aliases.c"
#include "g/keymap_combo.h"
#include "features/layer_lock.h"
#include "macros.h"

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

/* 

NOTE: 2025-May-31 - Mouse layer not working because there's no firrmware space anymore :(

Layer lock
https://getreuer.info/posts/keyboards/layer-lock/index.html (in use)
https://docs.qmk.fm/features/layer_lock#how-do-i-enable-layer-lock (newer version)


*/


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_DVORAK] = LAYOUT_split_3x6_3(
        //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_NO, KC_QUOT, COMMA_CUT, DOT_COPY, PEE_PASTE, LT(_NAV,KC_Y),                         KC_F, KC_G, KC_C, KC_R, KC_L,KC_NO,
        //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_NO,CKC_A, CKC_O, CKC_E , CKC_U, LT(_NUMERIC,KC_I),                        CKC_D , CKC_H , KC_T , CKC_N , KC_S,KC_NO,

      KC_NO,CKC_SCLN, CKC_Q, CKC_J, CKC_K, KC_X,                                     KC_B, CKC_M, KC_W, KC_V, ALT_DOWN,KC_NO,
      //,-----------------------------------------------------.                    -----------------------------------------------------.
                 KC_NO,  KC_TAB, LT(_NAV,KC_SPC),                                   SC_SENT, LT(_NUMERIC,CW_TOGG), KC_NO

                ),

      [_NAV] = LAYOUT_split_3x6_3(
          //,-----------------------------------------------------.                    ,-----------------------------------------------------.
            KC_NO,   KC_VOLU, MOU_1_3, MOU_1_2,MOU_1_1 , MOU_1_4,                              KC_NO, KC_HOME, KC_UP, KC_END, KC_PGUP, KC_NO,
          //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        KC_NO, KC_VOLD, MOU_2_1, MOU_2_2, MOU_2_3, CTRL_TICK,                                     KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN,KC_NO,
          //,--------------             ---------------------------------------.                    ,-----------------------------------------------------.
       KC_NO,  KC_MUTE,KC_NO,KC_MS_BTN3,KC_DEL,MOU_2_4,                                            LCTL(KC_UP), LCTL(KC_DOWN), LCTL(KC_RBRC),KC_NO,KC_TRNS,KC_NO,
          //,-----------------------------------------------------.                    ,-----------------------------------------------------.
                 KC_NO,  KC_TRNS,KC_SPC,                                              KC_TRNS, QK_LAYER_LOCK, KC_NO
                 ),


    [_NUMERIC] = LAYOUT_split_3x6_3(
      //,-----------------------------------------------------.                    ,-----------------------------------------------------.
            KC_NO,  KC_TRNS, KC_F1, KC_F2, KC_F3, KC_F4,                                     KC_PLUS,  KC_7, KC_8, KC_9, KC_SLSH,KC_NO,
      //,-----------------------------------------------------.                    ,-----------------------------------------------------.
           KC_NO, KC_F5, KC_F6, KC_F7, KC_F8,KC_TRNS,                                      KC_0, KC_4, KC_5, KC_6, KC_DOT,KC_NO,
      //,-----------------------------------------------------.                    ,-----------------------------------------------------.
           KC_NO, KC_F9, KC_F10, KC_F11, KC_F12, KC_F2,                                       KC_MINS, KC_1, KC_2, KC_3, KC_ASTR,KC_NO,
      //,-----------------------------------------------------.                    ,-----------------------------------------------------.
                   KC_NO, QK_LAYER_LOCK,   KC_SPC  ,                                     KC_TRNS, QK_LAYER_LOCK,KC_NO
                   ),

};





void housekeeping_task_user(void) {
  layer_lock_task();
  // Other tasks ...
}
