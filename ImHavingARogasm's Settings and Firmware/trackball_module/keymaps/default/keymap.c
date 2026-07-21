/*
Copyright 2022 aki27

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

#include QMK_KEYBOARD_H
#include <stdio.h>
#include "quantum.h"


// Defines names for use in layer keycodes and the keymap
enum layer_number {
    _BASE = 0,
    _LOWER = 1,
    _RAISE = 2,
    _TRACKBALL = 3
};


//Mapping the Keyswitches and Rotary Encoder Press
//REMAP does not show the keys correctly but once it's flashed, whatever you tried to change will be changed
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT(
       MS_BTN1,    MS_BTN2,    MS_BTN3
    ),
  [_LOWER] = LAYOUT(
       MS_BTN3,    MS_BTN2,    SCRL_TO
    ),
  [_RAISE] = LAYOUT(
       CPI_SW,    SCRL_SW,    KC_E
    ),
  [_TRACKBALL] = LAYOUT(
       KC_A,    KC_B,    KC_C
    ),
};

//Mapping the Rotary Encoder turns
//you can also use KC_PGUP or KC_PGDN
#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [_BASE] = { ENCODER_CCW_CW(MS_WHLU, MS_WHLD) },
    [_LOWER] = { ENCODER_CCW_CW(MS_BTN4, MS_BTN5) },
    [_RAISE] = { ENCODER_CCW_CW(ROT_R15, ROT_L15) },
    [_TRACKBALL] = { ENCODER_CCW_CW(MS_WHLU, MS_WHLD) },
};
#endif


// This code block dictates what layers use the trackball as a scrolling tool instead of a cursor
// This overrides the state of Scroll Toggle (SCRL_TO) when you change to the respective layer
// True = Scrolling tool; False = Cursor
layer_state_t layer_state_set_user(layer_state_t state) {

    switch (get_highest_layer(state)) {
    case _LOWER:
        cocot_set_scroll_mode(true);
        break;
    case _RAISE:
        
        break;
    case _TRACKBALL:
        
        break;


    default:
        cocot_set_scroll_mode(false);
        break;
    }
  return state;
};

// I don't have an OLED yet but will update once/if I decide to add onto my existing trackball module
#ifdef OLED_ENABLE
bool oled_task_user(void) {
    oled_write_layer_state();
    return false;
}
#endif

