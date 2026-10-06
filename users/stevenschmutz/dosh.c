// Dosh chord layout, ported from dosh.rs.
// Derived from Dane Lipscombe's (@dlip) Taipo implementation in taipo.c;
// the chord accumulation, timing and modifier handling are the same, only the
// chord table differs.
// SPDX-License-Identifier: GPL-2.0-or-later
//
// Dosh is a Taipo-style layout that leaves out the upper pinky key but keeps
// the lower one: 7 finger keys per hand plus 2 thumbs.  The bit names are
// Taipo's, so a Dosh chord can be spelled in the same alphabet as a Taipo one.
// The upper pinky (r) is never used.
//
// The thumbs: it (inner) is Backspace and ot (outer) is Space.  Capitals are
// +ot, and digits, symbols and navigation keys are +it.
//
// Left unmapped on purpose, as in dosh.rs: everything needing a consumer
// control report (play/pause, track skip, volume, brightness), the chord table
// selection chords (rsni, aote) and the Orsy switch, which are firmware
// concepts that do not apply here.

#include QMK_KEYBOARD_H
#include "custom.h"
#include "dosh.h"
#ifndef TAIPO_TAP_TIMEOUT
#define TAIPO_TAP_TIMEOUT 150
#endif

typedef struct {
    uint16_t keycode;
    bool     hold;
    bool     hold_handled;
} dosh_keypress;

typedef struct {
    uint16_t      combo;
    uint16_t      timer;
    dosh_keypress key;
} dosh_state;

static dosh_state left_state;
static dosh_state right_state;

static void clear_state(dosh_state* state) {
    state->combo            = 0;
    state->timer            = 0;
    state->key.keycode      = KC_NO;
    state->key.hold         = false;
    state->key.hold_handled = false;
}

#define r (1 << 0)
#define s (1 << 1)
#define n (1 << 2)
#define i (1 << 3)
#define a (1 << 4)
#define o (1 << 5)
#define t (1 << 6)
#define e (1 << 7)
#define it (1 << 8)
#define ot (1 << 9)

static uint16_t determine_key(uint16_t val) {
    switch (val) {
        case ot: // 0x200
            return KC_SPC;
        case it: // 0x100
            return KC_BSPC;
        // case it | ot: both thumbs alone is the null key, as in Taipo
        //     return KC_NO;
        case a: // 0x001
            return KC_A;
        case a | ot: // 0x201
            return S(KC_A);
        case a | it: // 0x101
            return KC_ESC;
        case a | it | ot: // 0x301
            return KC_DEL;
        case o: // 0x002
            return KC_O;
        case o | ot: // 0x202
            return S(KC_O);
        case o | it: // 0x102
            return KC_RGHT;
        case o | it | ot: // 0x302
            return KC_END;
        case t: // 0x004
            return KC_T;
        case t | ot: // 0x204
            return S(KC_T);
        case t | it: // 0x104
            return KC_DOWN;
        case t | it | ot: // 0x304
            return KC_PGDN;
        case e: // 0x008
            return KC_E;
        case e | ot: // 0x208
            return S(KC_E);
        case e | it: // 0x108
            return KC_LEFT;
        case e | it | ot: // 0x308
            return KC_HOME;
        case s: // 0x020
            return KC_S;
        case s | ot: // 0x220
            return S(KC_S);
        case s | it: // 0x120
            return KC_ENT;
        case s | it | ot: // 0x320
            return KC_TAB;
        case n: // 0x040
            return KC_N;
        case n | ot: // 0x240
            return S(KC_N);
        case n | it: // 0x140
            return KC_UP;
        case n | it | ot: // 0x340
            return KC_PGUP;
        case i: // 0x080
            return KC_I;
        case i | ot: // 0x280
            return S(KC_I);
        case i | it: // 0x180
            return KC_DOT;
        case i | it | ot: // 0x380
            return S(KC_QUOT);
        case t | e: // 0x00c
            return KC_H;
        case t | e | ot: // 0x20c
            return S(KC_H);
        case t | e | it: // 0x10c
            return KC_COMM;
        case t | e | i: // 0x08c
            return KC_QUOT;
        case e | n: // 0x048
            return KC_R;
        case e | n | ot: // 0x248
            return S(KC_R);
        case e | n | it: // 0x148
            return KC_0;
        case e | n | it | ot: // 0x348
            return KC_F10;
        case a | e: // 0x009
            return KC_D;
        case a | e | ot: // 0x209
            return S(KC_D);
        case a | e | it: // 0x109
            return KC_1;
        case a | e | it | ot: // 0x309
            return KC_F1;
        case a | o: // 0x003
            return KC_L;
        case a | o | ot: // 0x203
            return S(KC_L);
        case a | o | it: // 0x103
            return KC_2;
        case a | o | it | ot: // 0x303
            return KC_F2;
        case o | e: // 0x00a
            return KC_C;
        case o | e | ot: // 0x20a
            return S(KC_C);
        case o | e | it: // 0x10a
            return KC_3;
        case o | e | it | ot: // 0x30a
            return KC_F3;
        case o | t: // 0x006
            return KC_U;
        case o | t | ot: // 0x206
            return S(KC_U);
        case o | t | it: // 0x106
            return KC_4;
        case o | t | it | ot: // 0x306
            return KC_F4;
        case e | s: // 0x028
            return KC_M;
        case e | s | ot: // 0x228
            return S(KC_M);
        case e | s | it: // 0x128
            return KC_5;
        case e | s | it | ot: // 0x328
            return KC_F5;
        case a | i: // 0x081
            return KC_W;
        case a | i | ot: // 0x281
            return S(KC_W);
        case a | i | it: // 0x181
            return KC_6;
        case a | i | it | ot: // 0x381
            return KC_F6;
        case s | i: // 0x0a0
            return KC_F;
        case s | i | ot: // 0x2a0
            return S(KC_F);
        case s | i | it: // 0x1a0
            return KC_7;
        case s | i | it | ot: // 0x3a0
            return KC_F7;
        case o | n: // 0x042
            return KC_G;
        case o | n | ot: // 0x242
            return S(KC_G);
        case o | n | it: // 0x142
            return KC_8;
        case o | n | it | ot: // 0x342
            return KC_F8;
        case n | i: // 0x0c0
            return KC_Y;
        case n | i | ot: // 0x2c0
            return S(KC_Y);
        case n | i | it: // 0x1c0
            return KC_9;
        case n | i | it | ot: // 0x3c0
            return KC_F9;
        case s | n: // 0x060
            return KC_P;
        case s | n | ot: // 0x260
            return S(KC_P);
        case s | n | it: // 0x160
            return S(KC_EQL);
        case s | n | it | ot: // 0x360
            return KC_EQL;
        case o | t | e: // 0x00e
            return KC_B;
        case o | t | e | ot: // 0x20e
            return S(KC_B);
        case o | t | e | it: // 0x10e
            return KC_MINS;
        case o | t | e | it | ot: // 0x30e
            return S(KC_MINS);
        case e | s | n: // 0x068
            return KC_V;
        case e | s | n | ot: // 0x268
            return S(KC_V);
        case e | s | n | it: // 0x168
            return KC_SLSH;
        case e | s | n | it | ot: // 0x368
            return KC_BSLS;
        case o | i: // 0x082
            return KC_K;
        case o | i | ot: // 0x282
            return S(KC_K);
        case o | i | it: // 0x182
            return KC_SCLN;
        case o | i | it | ot: // 0x382
            return S(KC_BSLS);
        case a | n: // 0x041
            return KC_J;
        case a | n | ot: // 0x241
            return S(KC_J);
        case a | n | it: // 0x141
            return S(KC_SCLN);
        case a | n | it | ot: // 0x341
            return S(KC_8);
        case t | e | s: // 0x02c
            return KC_X;
        case t | e | s | ot: // 0x22c
            return S(KC_X);
        case t | e | s | it: // 0x12c
            return S(KC_4);
        case t | e | s | it | ot: // 0x32c
            return S(KC_3);
        case a | t: // 0x005
            return KC_Q;
        case a | t | ot: // 0x205
            return S(KC_Q);
        case a | t | it: // 0x105
            return S(KC_2);
        case a | t | it | ot: // 0x305
            return KC_F11;
        case t | e | n: // 0x04c
            return KC_Z;
        case t | e | n | ot: // 0x24c
            return S(KC_Z);
        case t | e | n | it: // 0x14c
            return S(KC_7);
        case t | e | n | it | ot: // 0x34c
            return KC_F12;
        case t | s: // 0x024
            return S(KC_SLSH);
        case t | s | ot: // 0x224
            return S(KC_1);
        case t | s | it: // 0x124
            return S(KC_6);
        case o | e | i: // 0x08a
            return KC_GRV;
        case o | e | i | ot: // 0x28a
            return S(KC_GRV);
        case o | e | i | it: // 0x18a
            return S(KC_5);
        case e | i: // 0x088
            return KC_LSFT;
        case e | i | ot: // 0x288
            return KC_RBRC;
        case e | i | it: // 0x188
            return KC_LBRC;
        case t | n: // 0x044
            return KC_LCTL;
        case t | n | ot: // 0x244
            return S(KC_0);
        case t | n | it: // 0x144
            return S(KC_9);
        case t | n | it | ot: // 0x344
            return KC_MOD_CS;
        case o | s: // 0x022
            return KC_LALT;
        case o | s | ot: // 0x222
            return S(KC_RBRC);
        case o | s | it: // 0x122
            return S(KC_LBRC);
        case o | s | it | ot: // 0x322
            return KC_MOD_AS;
        case a | o | s: // 0x023
            return KC_LGUI;
        case a | o | s | it | ot: // 0x323
            return KC_MOD_GS;
        case o | t | s | ot: // 0x226
            return S(KC_DOT);
        case o | t | s | it: // 0x126
            return S(KC_COMM);
        case o | t | n: // 0x046
            return KC_PSCR;
        case e | s | i: // 0x0a8
            return KC_INS;
    }
    return KC_NO;
}

#undef r
#undef s
#undef n
#undef i
#undef a
#undef o
#undef t
#undef e
#undef it
#undef ot

static void handle_key(dosh_keypress* key) {
    uint8_t mods = 0;
    switch (key->keycode) {
        case KC_MOD_GS:
            mods = MOD_BIT(KC_LGUI) | MOD_BIT(KC_LSFT);
            break;
        case KC_MOD_AS:
            mods = MOD_BIT(KC_LALT) | MOD_BIT(KC_LSFT);
            break;
        case KC_MOD_CS:
            mods = MOD_BIT(KC_LCTL) | MOD_BIT(KC_LSFT);
            break;
        case KC_LGUI:
        case KC_LALT:
        case KC_LCTL:
        case KC_LSFT:
            mods = MOD_BIT(key->keycode);
            break;
        default:
            if (key->hold_handled) {
                unregister_code16(key->keycode);
            } else if (key->hold) {
                register_code16(key->keycode);
                key->hold_handled = true;
            } else {
                tap_code16(key->keycode);
            }
    }
    if (mods) {
        if (key->hold_handled) {
            del_mods(mods);
            send_keyboard_report();
        } else if (key->hold) {
            add_mods(mods);
            send_keyboard_report();
            key->hold_handled = true;
        } else {
            add_oneshot_mods(mods);
        }
    }
}

bool dosh_process_record_user(uint16_t keycode, keyrecord_t* record) {
    uint16_t    key   = keycode - TP_TLP;
    dosh_state* state = (key / 10) ? &right_state : &left_state;

    if (record->event.pressed) {
        if (state->key.keycode != KC_NO) {
            handle_key(&state->key);
            clear_state(state);
        }
        state->timer = (record->event.time + TAIPO_TAP_TIMEOUT) | 1;
        state->combo |= 1 << (key % 10);
    } else {
        if (!state->key.hold) {
            state->key.keycode = determine_key(state->combo);
        }
        handle_key(&state->key);
        clear_state(state);
    }
    return false;
}

void dosh_matrix_scan_user(void) {
    if (left_state.timer && timer_expired(timer_read(), left_state.timer)) {
        left_state.key.keycode = determine_key(left_state.combo);
        left_state.key.hold    = true;
        handle_key(&left_state.key);
        left_state.timer = 0;
    }
    if (right_state.timer && timer_expired(timer_read(), right_state.timer)) {
        right_state.key.keycode = determine_key(right_state.combo);
        right_state.key.hold    = true;
        handle_key(&right_state.key);
        right_state.timer = 0;
    }
}
