#include QMK_KEYBOARD_H

enum custom_keycodes {
  SMTD_KEYCODES_BEGIN = SAFE_RANGE,
    CKC_A,
    CKC_O,
    CKC_E,
    CKC_U,
    CKC_S,
    CKC_N,
    CKC_T,
    CKC_H,
    CKC_M,
    CKC_K,
    CKC_I,
    CKC_Y,
    CKC_X,
    CKC_D,
    CKC_ESC,
    CKC_SPC,

    SMTD_KEYCODES_END,
    CTRL_TICK,

};


// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum layers {
    _DVORAK,
    _SYMBOL,
    _NAV,
    _NUMERIC,
  _ART_MOU
};

#include "sm_td.h"
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
	[_DVORAK] = LAYOUT_split_3x5_3(
        //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        LT(4,KC_QUOT), KC_COMM, KC_DOT, KC_P, LT(4,KC_Y),                         KC_F, KC_G, KC_C, KC_R, LT(1,KC_L),
        //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       CKC_A, CKC_O, CKC_E , CKC_U, LT(3,KC_I),                                          CKC_D , CKC_H , KC_T , KC_N , KC_S,

      LT(2,KC_SCLN), KC_Q, KC_J, KC_K, LT(2,KC_X),                             KC_B, KC_M, KC_W, KC_V, RSFT_T(KC_Z),
      //,-----------------------------------------------------.                    ,-----------------------------------------------------.
                 LSFT_T(KC_TAB), LT(2,KC_SPC), KC_TRNS,                   KC_TRNS, SC_SENT, LT(1,KC_BSPC)

                ),
 

	[_SYMBOL] = LAYOUT_split_3x5_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
 KC_GRV, KC_CIRC, KC_AT, KC_DLR, KC_TILD,                                 KC_AMPR, KC_EXLM, KC_PIPE, KC_UNDS, KC_HASH,
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
 KC_SLSH, KC_LBRC, KC_LCBR, KC_LPRN, KC_SLSH,                              KC_HASH, KC_RPRN, KC_RCBR, KC_RBRC, KC_BSLS,
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
 KC_TRNS, KC_QUES, KC_GRV, KC_PERC, KC_QUES,                                 KC_TRNS, KC_BSLS, KC_COLN, KC_TRNS, KC_TRNS,
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
                         KC_TRNS, KC_TRNS, KC_TRNS,                             KC_TRNS, KC_TRNS, QK_BOOT),


	[_NAV] = LAYOUT_split_3x5_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
 KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                                             KC_NO, KC_HOME, KC_UP,  KC_END,KC_PGUP,
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
 KC_MUTE, KC_VOLD, KC_VOLU, KC_F2, CTRL_TICK,                                   KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN,
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
 KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO,                                            LCTL(KC_UP), LCTL(KC_DOWN), LCTL(KC_RBRC),KC_NO,KC_TRNS,
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
            QK_BOOT,KC_TRNS, KC_TRNS,                                             KC_TRNS, KC_TRNS, KC_TRNS),


	[_NUMERIC] = LAYOUT_split_3x5_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
 KC_F8, KC_F9, KC_F10, KC_F11, KC_F12,                                     KC_PLUS, KC_7, KC_8, KC_9, KC_SLSH,
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
 KC_NO, KC_F5, KC_F6, KC_F7, KC_F8,                                       KC_0, KC_4, KC_5, KC_6, KC_DOT,
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
 KC_TRNS, KC_F1, KC_F2, KC_F3, KC_F4,                                       KC_MINS, KC_1, KC_2, KC_3, KC_ASTR,
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
               KC_TRNS, KC_TRNS, KC_TRNS,                                         KC_TRNS, KC_TRNS, KC_TRNS),



[_ART_MOU] = LAYOUT_split_3x5_3(
            //,-----------------------------------------------------.                    ,-----------------------------------------------------.
             KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,                                                KC_MS_BTN4, MOU_1_1, MOU_1_2, MOU_1_3, MOU_1_4,
              //,-----------------------------------------------------.                    ,-----------------------------------------------------.
             KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,                                                KC_MS_BTN5, MOU_2_1, MOU_2_2, MOU_2_3, MOU_2_4,
              //,-----------------------------------------------------.                    ,-----------------------------------------------------.
             KC_NO,KC_NO,KC_NO,KC_NO,TG(_ART_MOU),                                         KC_NO,KC_NO,KC_MS_BTN3,KC_NO,KC_NO,
              //,-----------------------------------------------------.                    ,-----------------------------------------------------.
                        KC_NO,KC_NO,KC_NO,                                  KC_NO,KC_NO,KC_NO),

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


bool process_record_user(uint16_t keycode, keyrecord_t* record) {
 
    if (!process_smtd(keycode, record)) {
        return false;
    }

 switch (keycode) {
    case CTRL_TICK:  // Types ctrl + backtick
      if (record->event.pressed) {
        SEND_STRING(SS_LCTL("`"));
      }
      return false;
  }
  return true;
}


void on_smtd_action(uint16_t keycode, smtd_action action, uint8_t tap_count) {
    switch (keycode) {
        SMTD_MT(CKC_A, KC_A, KC_LEFT_GUI, 2)
        SMTD_MT(CKC_O, KC_O, KC_LEFT_ALT, 2)
        SMTD_MT(CKC_E, KC_E, KC_LEFT_CTRL, 2)
        SMTD_MT(CKC_U, KC_U, KC_LSFT, 2)
        //SMTD_MT(CKC_S, KC_S, KC_S, 2)
        //SMTD_MT(CKC_N, KC_N, KC_N, 2)
        //SMTD_MT(CKC_T, KC_T, KC_T, 2)
        SMTD_MT(CKC_H, KC_H, KC_LSFT, 2)

        //SMTD_LT(CKC_K, KC_K, _SECOND_SYMBOLS)
        //SMTD_LT(CKC_M, KC_M, _SECOND_SYMBOLS)
        //SMTD_LT(CKC_I, KC_I, _NAVIGATION)
        SMTD_LT(CKC_D, KC_D, _SYMBOL)
    }
}
