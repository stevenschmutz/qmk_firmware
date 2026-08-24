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
    _ART_MOU,
    _ART_BASE,
    _ART_NUM,
    _ART_CUS,
    _ART_PUNC,
    _ART_NAV,
    _ART_SYM,
      _TAIPO,
};

#include "sm_td.h"
#include "aliases.c"
#include "g/keymap_combo.h"
#include "features/layer_lock.h"
#include "dlip.h"
#include "tapdance.ref"



/* 

Layer lock
https://getreuer.info/posts/keyboards/layer-lock/index.html (in use)
https://docs.qmk.fm/features/layer_lock#how-do-i-enable-layer-lock (newer version)

Caps-Word
CW_TOGG <= capitilise word with _

https://getreuer.info/posts/keyboards/triggers/index.html
*/


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_DVORAK] = LAYOUT_split_3x5_3(
        //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        QUOTE_BOLD, COMMA_CUT, DOT_COPY, PEE_PASTE, LT(_NAV,KC_Y),                   KC_F, KC_G, KC_C, KC_R, KC_L,
        //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       CKC_A, CKC_O, CKC_E ,LT(_NUMERIC,KC_U) , LT(_NUMERIC,KC_I),                              CKC_D , CKC_H , KC_T , CKC_N , KC_S,
        //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      CKC_SCLN, TD(TD_Q_WORKSPACE), CKC_J, CKC_K, KC_X,                                          KC_B, CKC_M, KC_W, KC_V, ALT_DOWN,
      //,-----------------------------------------------------.                    ,-----------------------------------------------------.
                 KC_NO,CKC_TAB, LT(_NAV,KC_SPC),                   RSFT_T(KC_ENT), LT(_NUMERIC,KC_DOT),KC_NO

                ),

      [_NAV] = LAYOUT_split_3x5_3(
          //,-----------------------------------------------------.                   ,-----------------------------------------------------.
          KC_VOLU, MOU_1_3, MOU_1_2,MOU_1_1 , MOU_1_4,                                KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, 
          //,-----------------------------------------------------.                   ,-----------------------------------------------------.
         KC_VOLD, MOU_2_1, MOU_2_2, MOU_2_3, CTRL_TICK,                               KC_NO, ALT_NAV_1_1, ALT_NAV_1_2, ALT_NAV_1_3, ALT_NAV_1_4,
          //,--------------             ---------------------------------------.      ,-----------------------------------------------------.
         KC_MUTE,KC_NO,KC_MS_BTN3,KC_DEL,MOU_2_4,                                     KC_NO, ALT_NAV_2_1, ALT_NAV_2_2, ALT_NAV_2_3, ALT_NAV_2_4,
          //,-----------------------------------------------------.                   ,-----------------------------------------------------.
                  KC_NO,KC_TRNS,KC_SPC,                                               KC_NO, KC_TRNS, KC_NO), 



    [_NUMERIC] = LAYOUT_split_3x5_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
 KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                                     KC_NO,  KC_NO, KC_NO, KC_NO, KC_NO,
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
 ALT_LEFT_1_4, ALT_LEFT_1_3, ALT_LEFT_1_2, ALT_LEFT_1_1,KC_NO,          KC_NO, ALT_NUM_1_1, ALT_NUM_1_2, ALT_NUM_1_3, ALT_NUM_1_4,
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
 ALT_LEFT_2_4, ALT_LEFT_2_3, ALT_LEFT_2_2, ALT_LEFT_2_1, KC_NO,         KC_NO, ALT_NUM_2_1, ALT_NUM_2_2, ALT_NUM_2_3, ALT_NUM_2_4,
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
               KC_NO,QK_LAYER_LOCK, KC_SPC,                                         KC_TRNS, QK_LAYER_LOCK,KC_NO),


  [_TAIPO] = LAYOUT_split_3x5_3(
            //,-----------------------------------------------------.                    ,-----------------------------------------------------.
             KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,                                                KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,
              //,-----------------------------------------------------.                    ,-----------------------------------------------------.
             TP_TLP,        TP_TLR,    TP_TLM,       TP_TLI,KC_NO,                          KC_NO, BASE_1_1, BASE_1_2, BASE_1_3, BASE_1_4,
              //,-----------------------------------------------------.                    ,-----------------------------------------------------.
             TP_BLP,        TP_BLR,    TP_BLM,       TP_BLI,KC_NO,                          KC_NO, BASE_2_1, BASE_2_2, BASE_2_3, BASE_2_4,
              //,-----------------------------------------------------.                    ,-----------------------------------------------------.
                       KC_NO, TP_LIT,       TP_LOT,                                  KC_NO, QK_LAYER_LOCK,KC_NO),



    [_ART_BASE] = LAYOUT_split_3x5_3(
            //,-----------------------------------------------------.                    ,-----------------------------------------------------.
             KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,                                                KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,
              //,-----------------------------------------------------.                    ,-----------------------------------------------------.
             TP_TLP,        TP_TLR,    TP_TLM,       TP_TLI,KC_NO,                          KC_NO, BASE_1_1, BASE_1_2, BASE_1_3, BASE_1_4,
              //,-----------------------------------------------------.                    ,-----------------------------------------------------.
             TP_BLP,        TP_BLR,    TP_BLM,       TP_BLI,KC_NO,                          KC_NO, BASE_2_1, BASE_2_2, BASE_2_3, BASE_2_4,
              //,-----------------------------------------------------.                    ,-----------------------------------------------------.
                        KC_NO,TP_LIT,       TP_LOT,                                  KC_NO, QK_LAYER_LOCK,KC_NO),



    [_ART_NUM] = LAYOUT_split_3x5_3(
            //,-----------------------------------------------------.                    ,-----------------------------------------------------.
             KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,                                                KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,
              //,-----------------------------------------------------.                    ,-----------------------------------------------------.
             KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,                                          KC_NO, NUM_1_1, NUM_1_2, NUM_1_3, NUM_1_4,
              //,-----------------------------------------------------.                    ,-----------------------------------------------------.
             KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,                                         KC_NO, NUM_2_1, NUM_2_2, NUM_2_3, NUM_2_4,
              //,-----------------------------------------------------.                    ,-----------------------------------------------------.
                        KC_NO,KC_NO,KC_NO,                                  KC_NO, QK_LAYER_LOCK,KC_NO),

    [_ART_CUS] = LAYOUT_split_3x5_3(
            //,-----------------------------------------------------.                    ,-----------------------------------------------------.
             KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,                                                KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,
              //,-----------------------------------------------------.                    ,-----------------------------------------------------.
             KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,                                          KC_NO, CUS_1_1, CUS_1_2, CUS_1_3, CUS_1_4,
              //,-----------------------------------------------------.                    ,-----------------------------------------------------.
             KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,                                         KC_NO, CUS_2_1, CUS_2_2, CUS_2_3, CUS_2_4,
              //,-----------------------------------------------------.                    ,-----------------------------------------------------.
                        KC_NO,KC_NO,KC_NO,                                  KC_NO, QK_LAYER_LOCK,KC_NO),


    [_ART_PUNC] = LAYOUT_split_3x5_3(
            //,-----------------------------------------------------.                    ,-----------------------------------------------------.
             KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,                                                KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,
              //,-----------------------------------------------------.                    ,-----------------------------------------------------.
             KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,                                          KC_NO, PUNC_1_1, PUNC_1_2, PUNC_1_3, PUNC_1_4,
              //,-----------------------------------------------------.                    ,-----------------------------------------------------.
             KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,                                         KC_NO, PUNC_2_1, PUNC_2_2, PUNC_2_3, PUNC_2_4,
              //,-----------------------------------------------------.                    ,-----------------------------------------------------.
                        KC_NO,KC_NO,KC_NO,                                  KC_NO, QK_LAYER_LOCK,KC_NO),


    [_ART_MOU] = LAYOUT_split_3x5_3(
            //,-----------------------------------------------------.                    ,-----------------------------------------------------.
             KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,                                                KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,
              //,-----------------------------------------------------.                    ,-----------------------------------------------------.
             KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,                                          KC_NO, MOU_1_1, MOU_1_2, MOU_1_3, MOU_1_4,
              //,-----------------------------------------------------.                    ,-----------------------------------------------------.
             KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,                                         KC_NO, MOU_2_1, MOU_2_2, MOU_2_3, MOU_2_4,
              //,-----------------------------------------------------.                    ,-----------------------------------------------------.
                        KC_NO,KC_NO,KC_NO,                                  KC_NO, QK_LAYER_LOCK,KC_NO),

    [_ART_NAV] = LAYOUT_split_3x5_3(
            //,-----------------------------------------------------.                    ,-----------------------------------------------------.
             KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,                                                KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,
              //,-----------------------------------------------------.                    ,-----------------------------------------------------.
             KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,                                          KC_NO, NAV_1_1, NAV_1_2, NAV_1_3, NAV_1_4,
              //,-----------------------------------------------------.                    ,-----------------------------------------------------.
             KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,                                         KC_NO, NAV_2_1, NAV_2_2, NAV_2_3, NAV_2_4,
              //,-----------------------------------------------------.                    ,-----------------------------------------------------.
                        KC_NO,KC_NO,KC_NO,                                  KC_NO, QK_LAYER_LOCK,KC_NO),

    [_ART_SYM] = LAYOUT_split_3x5_3(
            //,-----------------------------------------------------.                    ,-----------------------------------------------------.
             KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,                                                KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,
              //,-----------------------------------------------------.                    ,-----------------------------------------------------.
             KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,                                          KC_NO, SYM_1_1, SYM_1_2, SYM_1_3, SYM_1_4,
              //,-----------------------------------------------------.                    ,-----------------------------------------------------.
             KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,                                         KC_NO, SYM_2_1, SYM_2_2, SYM_2_3, SYM_2_4,
              //,-----------------------------------------------------.                    ,-----------------------------------------------------.
                        KC_NO,KC_NO,KC_NO,                                  KC_NO, QK_LAYER_LOCK,KC_NO),





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
#include "macros.h"
void housekeeping_task_user(void) {
  layer_lock_task();
  // Other tasks ...


 //#if TAIPO_ENABLE == yes
    //void matrix_scan_user(void) {
        taipo_matrix_scan_user();
    //}
 //#endif
}
