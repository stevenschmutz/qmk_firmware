#include QMK_KEYBOARD_H
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


enum custom_keycodes {
    CTRL_TICK,
};



#include "aliases.c"
#include "g/keymap_combo.h"


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[_DVORAK] = LAYOUT_split_3x5_3(
        //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        LGUI_T(KC_QUOT), KC_COMM, KC_DOT, KC_P, KC_Y,                         KC_F, KC_G, KC_C, KC_R, KC_L,
        //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_A, KC_O, KC_E, KC_U, LT(3,KC_I),                                          KC_D, KC_H, KC_T, KC_N, KC_S,

      LSFT_T(KC_SCLN), KC_Q, KC_J, KC_K, LT(_ART_MOU,KC_X),                             KC_B, KC_M, KC_W, KC_V, RSFT_T(KC_Z),
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
 KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                                             KC_NO, KC_HOME, KC_UP, KC_END, KC_PGUP,
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
 KC_MUTE, KC_VOLD, KC_VOLU, KC_F2, CTRL_TICK,                                     KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN,
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
  // If console is enabled, it will print the matrix position and status of each key pressed
#ifdef CONSOLE_ENABLE
    uprintf("KL: kc: 0x%04X,row: %2u,  col: %2u, pressed: %u, time: %5u, int: %u, count: %u\n", keycode, record->event.key.row,record->event.key.col,  record->event.pressed, record->event.time, record->tap.interrupted, record->tap.count);
#endif
  switch (keycode) {
    case CTRL_TICK:  // Types ctrl + backtick
      if (record->event.pressed) {
        SEND_STRING(SS_LCTL("`"));
      }
      return false;
  }
  return true;
}


