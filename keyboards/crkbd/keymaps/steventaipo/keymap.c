#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum layers {
 _DOSH,
 _INNER,  // held while the inner thumb (Backspace) is down
 _OUTER,  // held while the outer thumb (Space) is down
 _BOTH,   // held while both thumbs are down together
};

// custom.h/sm_td.h/aliases.c/macros.h/tapdance.ref (SMTD home-row mods, tap
// dance, and the CTRL_*/paste-cut-copy custom keycodes) were leftovers from
// the bigger stevenschmutz userspace this was copied from -- nothing in the
// _TAIPO layout or taipo combos below references any of it, so it was pure
// dead weight pushing the firmware over the flash limit. Removed. No custom
// process_record_user is needed either: the layout is plain keycodes and
// the taipo combos are handled entirely by process_combo_event in
// g/keymap_combo.h, so QMK's default weak process_record_user is enough.
#include "g/keymap_combo.h"
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  // Dosh flavor (see users/steventaipo/dosh.def). Both
  // hands carry the same letters -- combos.def-based combos match by
  // keycode, not physical position, so either hand (or a mix of both)
  // can form any chord.
  [_DOSH] = LAYOUT_split_3x6_3(
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        //,
        KC_NO, KC_NO,          KC_S,      KC_N,         KC_I,   KC_NO,          KC_NO,   KC_I,       KC_N,       KC_S,       KC_NO,   KC_NO,
        KC_NO, KC_A,          KC_O,      KC_T,         KC_E,    KC_NO,         KC_NO,    KC_E,       KC_T,       KC_O,       KC_A,   KC_NO,
                                  // The unused outermost left thumb slot is a manual
                                  // EEPROM-clear key -- not load-bearing now that
                                  // keyboard_post_init_user() resyncs on every boot, but
                                  // handy to keep around for a VIA-enabled board.
                                  QK_CLEAR_EEPROM, LT(_OUTER, KC_SPC), LT(_INNER, KC_BSPC),   LT(_INNER, KC_BSPC), LT(_OUTER, KC_SPC), KC_NO
    ),

  // Held while the Backspace thumb is down: Escape, the arrows, Enter and `.`
  // on the single finger keys; pairs/triples combo together (see dosh.def's
  // tpDoshIn* combos) to reach the digits, symbols and brackets.
  [_INNER] = LAYOUT_split_3x6_3(
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        //,
        KC_NO, KC_NO, KC_ENT, KC_UP, KC_DOT, KC_NO,      KC_NO, KC_DOT, KC_UP, KC_ENT, KC_NO, KC_NO,
        KC_NO, KC_ESC, KC_RGHT, KC_DOWN, KC_LEFT, KC_NO,      KC_NO, KC_LEFT, KC_DOWN, KC_RGHT, KC_ESC, KC_NO,
                                  KC_NO, KC_TRNS,      KC_TRNS,                KC_TRNS,    KC_TRNS, KC_NO
    ),

  // Held while the Space thumb is down: shifted letters on the single finger
  // keys; pairs/triples combo per dosh.def's tpDoshOut* combos.
  [_OUTER] = LAYOUT_split_3x6_3(
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        //,
        KC_NO, KC_NO, S(KC_S), S(KC_N), S(KC_I), KC_NO,      KC_NO, S(KC_I), S(KC_N), S(KC_S), KC_NO, KC_NO,
        KC_NO, S(KC_A), S(KC_O), S(KC_T), S(KC_E), KC_NO,      KC_NO, S(KC_E), S(KC_T), S(KC_O), S(KC_A), KC_NO,
                                  KC_NO, KC_TRNS,      KC_TRNS,                KC_TRNS,    KC_TRNS, KC_NO
    ),

  // Held while both thumbs are down together (reached via the tpDoshBoth combo
  // in dosh.def, which chords the two thumb layer-tap keys). Single finger keys
  // are Delete, End, PgDn, Home, Tab, PgUp and `"`; pairs combo per dosh.def's
  // tpDoshBoth* combos to reach the F-keys. Media keys are unmapped, as in dosh.rs.
  [_BOTH] = LAYOUT_split_3x6_3(
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        //,
        KC_NO, KC_NO, KC_TAB, KC_PGUP, S(KC_QUOT), KC_NO,      KC_NO, S(KC_QUOT), KC_PGUP, KC_TAB, KC_NO, KC_NO,
        KC_NO, KC_DEL, KC_END, KC_PGDN, KC_HOME, KC_NO,      KC_NO, KC_HOME, KC_PGDN, KC_END, KC_DEL, KC_NO,
                                  KC_NO, KC_TRNS,      KC_TRNS,                KC_TRNS,    KC_TRNS, KC_NO
    ),

};

void housekeeping_task_user(void) {
  layer_lock_task();
  // Other tasks ...
}

// VIA/RAW_ENABLE's dynamic keymap is EEPROM-backed and is what actually gets
// read at runtime (keycode_at_keymap_location()), not this PROGMEM array
// directly -- the array only ever seeds EEPROM on a reset. In practice a
// QK_CLEAR_EEPROM press wasn't reliably resyncing it after a reflash (traced
// via the debug console: process_record_user kept seeing bare KC_BSPC
// instead of LT(_INNER, KC_BSPC)), so force the resync unconditionally on
// every boot instead. Tradeoff: any layout tweak made from the VIA GUI won't
// survive a power cycle -- fine while this keymap's source of truth is this
// file, not VIA.
void keyboard_post_init_user(void) {
  dynamic_keymap_reset();
}
