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

Layer lock
https://getreuer.info/posts/keyboards/layer-lock/index.html (in use)
https://docs.qmk.fm/features/layer_lock#how-do-i-enable-layer-lock (newer version)

Caps-Word
CW_TOGG <= capitilise word with _
*/


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_DVORAK] = LAYOUT_ortho_4x10(
        //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        KC_QUOT, COMMA_CUT, DOT_COPY, PEE_PASTE, LT(_NAV,KC_Y),                         KC_F, KC_G, KC_C, KC_R, KC_L,
        //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       CKC_A, CKC_O, CKC_E , CKC_U, LT(_NUMERIC,KC_I),                                          CKC_D , CKC_H , KC_T , CKC_N , KC_S,

      CKC_SCLN, CKC_Q, CKC_J, CKC_K, KC_X,                             KC_B, CKC_M, KC_W, KC_V, ALT_DOWN,
      //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        LSFT_T(KC_TAB), LT(_NAV,KC_SPC),                   SC_SENT, MO(_NUMERIC)

    ),

      [_NAV] = LAYOUT_ortho_4x10(
          //,-----------------------------------------------------.                    ,-----------------------------------------------------.
          KC_VOLU, MOU_1_3, MOU_1_2,MOU_1_1 , MOU_1_4,                              KC_NO, KC_HOME, KC_UP, KC_END, KC_PGUP, 
          //,-----------------------------------------------------.                    ,-----------------------------------------------------.
         KC_VOLD, MOU_2_1, MOU_2_2, MOU_2_3, CTRL_TICK,                                     KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN,
          //,--------------             ---------------------------------------.                    ,-----------------------------------------------------.
         KC_MUTE,KC_NO,KC_MS_BTN3,KC_DEL,MOU_2_4,                                            LCTL(KC_UP), LCTL(KC_DOWN), LCTL(KC_RBRC),KC_NO,KC_TRNS,
          //,-----------------------------------------------------.                    ,-----------------------------------------------------.
          KC_TRNS,KC_SPC,                                              KC_TRNS, QK_LAYER_LOCK

    ),


    [_NUMERIC] = LAYOUT_ortho_4x10(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
 KC_TRNS, KC_F1, KC_F2, KC_F3, KC_F4,                                     KC_PLUS,  KC_7, KC_8, KC_9, KC_SLSH,
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
 KC_F5, KC_F6, KC_F7, KC_F8,KC_TRNS,                                       KC_0, KC_4, KC_5, KC_6, KC_DOT,
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
KC_F9, KC_F10, KC_F11, KC_F12, KC_F2,                                       KC_MINS, KC_1, KC_2, KC_3, KC_ASTR,
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
            QK_LAYER_LOCK, KC_SPC,                                KC_TRNS, QK_LAYER_LOCK),

};

#ifdef OLED_ENABLE
bool oled_task_user(void) {
    // Host Keyboard Layer Status
    oled_write_P(PSTR("Layer: "), false);

    switch (get_highest_layer(layer_state)) {
        case _DVORAK:
            oled_write_P(PSTR("DVORAK\n"), false);
            break;
        case _SYMBOL:
           oled_write_P(PSTR("SYMBOL\n"), false);
            break;
        case _NAV:
            oled_write_P(PSTR("NAV\n"), false);
            break;
        default:
            // Or use the write_ln shortcut over adding '\n' to the end of your string
            oled_write_ln_P(PSTR("Undefined"), false);
    }

    // Host Keyboard LED Status
    led_t led_state = host_keyboard_led_state();
    oled_write_P(led_state.num_lock ? PSTR("NUM ") : PSTR("    "), false);
    oled_write_P(led_state.caps_lock ? PSTR("CAP ") : PSTR("    "), false);
    oled_write_P(led_state.scroll_lock ? PSTR("SCR ") : PSTR("    "), false);
    
    return false;
}
#endif





void housekeeping_task_user(void) {
  layer_lock_task();
  // Other tasks ...
}
