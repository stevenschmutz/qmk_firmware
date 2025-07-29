// Copyright 2023 Thomas Haukland (@tompi)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* disable debug print */
//#define NO_DEBUG

/* disable print */
//#define NO_PRINT

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT

#define DOUBLE_TAP_SHIFT_TURNS_ON_CAPS_WORD
#define BOTH_SHIFTS_TURNS_ON_CAPS_WORD

#define LAYER_LOCK_IDLE_TIMEOUT 60000
// Pick good defaults for enabling homerow modifiers
#define TAPPING_TERM 230
#define SMTD_GLOBAL_RELEASE_TERM 20


#define MAX_DEFERRED_EXECUTORS 10
