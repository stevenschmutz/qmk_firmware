/*
This is the c configuration file for the keymap

Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2015 Jack Humbert

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

//#define USE_MATRIX_I2C

/* Select hand configuration */

#define MASTER_LEFT
#define MAX_DEFERRED_EXECUTORS 10 
#define COMBO_VARIABLE_LEN
#define COMBO_TERM 50
// Pick good defaults for enabling homerow modifiers
#define TAPPING_TERM 230
#define SMTD_GLOBAL_RELEASE_TERM 20


#define LAYER_LOCK_IDLE_TIMEOUT 60000
#define NO_ACTION_MACRO //space saving 
#define NO_ACTION_FUNCTION //space saving

    #ifndef NO_DEBUG
    #define NO_DEBUG
    #endif // !NO_DEBUG
    #if !defined(NO_PRINT) && !defined(CONSOLE_ENABLE)
    #define NO_PRINT
    #endif // !NO_PRINT
