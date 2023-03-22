/* Copyright 2019 Thomas Baart <thomas@splitkb.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H
// #include "g/keymap_combo.h"

// http://combos.gboards.ca/

enum layers {
    _COLEMAK_DH = 0,
    _NAV,
    _SYM,
    _FUNCTION,
    _ADJUST,
    _NUM,
    _HANDS_DOWN_NEU,
};

// # Hands Down Neu
//
// https://sites.google.com/alanreiser.com/handsdown/home/hands-down-neu
//
// There is this good implementation here: https://configure.zsa.io/moonlander/layouts/VaeAr/latest/0
// ==> Also see the layout tour!
//
// For now, this implements just the alpha layer of the layout. I need to add
// the Combos later.

// Aliases for readability
#define COLEMAK DF(_COLEMAK_DH)

#define SYM MO(_SYM)
#define NAV MO(_NAV)
#define FKEYS MO(_FUNCTION)
#define ADJUST MO(_ADJUST)

#define CTL_ESC MT(MOD_LCTL, KC_ESC)
#define CTL_QUOT MT(MOD_RCTL, KC_QUOTE)
#define CTL_MINS MT(MOD_RCTL, KC_MINUS)
#define ALT_ENT MT(MOD_LALT, KC_ENT)

// static uint8_t is_ctrl_and_gui_swapped = 0;

// Note: LAlt/Enter (ALT_ENT) is not the same thing as the keyboard shortcut Alt+Enter.
// The notation `mod/tap` denotes a key that activates the modifier `mod` when held down, and
// produces the key `tap` when tapped (i.e. pressed and released).

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * Base Layer: Colemak DH
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |   Q  |   W  |   F  |   P  |   B  |                              |   J  |   L  |   U  |   Y  | ' "  |OSM(Hyper)|
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+----------|
 * |OSL(SYM)|   A  |   R  |   S  |   T  |   G  |                              |   M  |   N  |   E  |   I  |   O  |          |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+----------|
 * |        |   Z  |   X  |   C  |   D  |   V  |      |      |  |      |      |   K  |   H  | ,  < | . >  | /  ? |          |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+------------------------'
 *                        |      |      | Esc  | Space| Tab  |  | Enter|BSpace| Del  |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_COLEMAK_DH] = LAYOUT(
     OSM(MOD_MEH), KC_Q ,  KC_W   ,  KC_F  ,   KC_P ,   KC_B ,                                                        KC_J,   KC_L ,  KC_U ,   KC_Y ,KC_QUOTE, OSM(MOD_HYPR),
     OSL(_SYM), MT(MOD_LGUI, KC_A), MT(MOD_LALT, KC_R), MT(MOD_LCTL, KC_S), MT(MOD_LSFT, KC_T),   KC_G ,           KC_M,   MT(MOD_RSFT, KC_N), MT(MOD_RCTL, KC_E), MT(MOD_RALT, KC_I), MT(MOD_RGUI, KC_O), _______,
     KC_F5, KC_Z ,  KC_X   ,  KC_C  ,   KC_D ,   KC_V , _______,TG(_NUM),                     FKEYS, ADJUST, KC_K,   KC_H ,KC_COMM, KC_DOT ,KC_SLSH, _______,
                                 _______, _______, KC_ESC, LT(_NAV, KC_SPC), KC_TAB,            LT(_SYM, KC_ENTER), LT(_NUM, KC_BACKSPACE), KC_DEL, _______, _______
    ),

/*
 * Base Layer: Hands Down Neu
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |      |      |      |      |      |                              |      |      |      |      |      |OSM(Hyper)|
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |OSL(SYM)|      |      |      |      |      |                              |      |      |      |      |      |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_HANDS_DOWN_NEU] = LAYOUT(
     OSL(_SYM),         KC_X,               KC_F,               KC_M,               KC_P,  KC_B ,                                                              KC_SLSH,              KC_DOT,           KC_COLON,           KC_COMMA,               KC_Q, OSM(MOD_HYPR),
     KC_Z, MT(MOD_LGUI, KC_R), MT(MOD_LALT, KC_S), MT(MOD_LCTL, KC_N), MT(MOD_LSFT, KC_T), KC_G,                                                               KC_QUOTE, MT(MOD_RSFT, KC_A), MT(MOD_RCTL, KC_E), MT(MOD_RALT, KC_I), MT(MOD_RGUI, KC_H), KC_J,
     KC_HOME,           KC_W,               KC_C,               KC_L,               KC_D,  KC_V, _______,_______,                         FKEYS,  ADJUST,      KC_MINUS,               KC_U,               KC_O,               KC_Y,               KC_K, KC_END,
                                                              _______, _______, KC_ESC, LT(_NAV, KC_SPC), KC_TAB,            LT(_SYM, KC_ENTER), LT(_NUM, KC_BACKSPACE), KC_DEL, _______, _______
    ),

/*
 * Nav Layer: Navigation
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |      |      |      |      |      |                              |      |      | Paste| Copy | Cut  | Undo   |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |  GUI |  Alt | Ctrl | Shift|      |                              |      |  ←   |   ↓  |   ↑  |   →  |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |      |  |      |      |Insert| Home | PDown| PUp  | End  |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_NAV] = LAYOUT(
      _______, _______, _______, _______, _______, _______,                                          _______, _______, KC_PASTE, KC_COPY, KC_CUT, KC_UNDO,
      _______, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, _______,                                          _______, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, _______,
      _______, _______, _______, _______, _______, _______, _______, _______,       _______, _______,KC_INSERT, KC_HOME, KC_PAGE_DOWN, KC_PAGE_UP, KC_END, _______,
                                 _______, _______, _______, _______, _______,       _______, KC_BACKSPACE, KC_DEL, _______, _______
    ),

/*
 * Sym Layer: symbols
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_SYM] = LAYOUT(
      _______, KC_EXCLAIM, KC_AT, KC_HASH, KC_COLON, KC_SEMICOLON,                                                                          KC_EQUAL, KC_AMPERSAND, KC_GRV, KC_TILDE, KC_PLUS, _______,
      _______, KC_BACKSLASH, KC_PIPE, KC_LEFT_CURLY_BRACE, KC_LEFT_PAREN, KC_LEFT_BRACKET,                                                  KC_ASTERISK, KC_DOLLAR, KC_PERCENT, KC_CIRCUMFLEX, KC_UNDERSCORE, _______,
      _______, KC_MINUS, KC_UNDERSCORE, KC_RIGHT_CURLY_BRACE, KC_RIGHT_PAREN, KC_RIGHT_BRACKET, _______, _______,         _______, _______, KC_PIPE, KC_EXCLAIM, KC_AT, KC_HASH, _______, _______,
                                 _______, _______, _______, _______, _______,                                             _______, _______, _______, _______, _______
    ),

/*
 * Numbers Layer: Numpad
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |    `   |  1   |  2   |  3   |  4   |  5   |                              |   6  |  7   |  8   |  9   |  0   |   =    |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |    ~   |  !   |  @   |  #   |  $   |  %   |                              |   ^  |  &   |  *   |  (   |  )   |   +    |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |    |   |   \  |  :   |  ;   |  -   |  [   |  {   |      |  |      |   }  |   ]  |  _   |  ,   |  .   |  /   |   ?    |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_NUM] = LAYOUT( 
      _______, KC_KP_SLASH,    KC_7, KC_8, KC_9, KC_KP_PLUS,                                            _______, _______, _______, _______, _______, _______,
      _______, KC_KP_ASTERISK, KC_4, KC_5, KC_6, KC_EQUAL,                                           _______, _______, _______, _______, _______, _______,
      _______, KC_KP_MINUS,    KC_1, KC_2, KC_3, KC_COLON, _______, _______,       _______, _______, _______, _______, _______, _______, _______, _______, 
                                  _______, _______, KC_COMMA, KC_0, KC_DOT,       _______, _______, _______, _______, _______
    ),

/*
 * Function Layer: Function keys
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |  F9  | F10  | F11  | F12  |      |                              |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |  F5  |  F6  |  F7  |  F8  |      |                              |      | Shift| Ctrl |  Alt |  GUI |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |  F1  |  F2  |  F3  |  F4  |      |      |      |  |      |      |      |      |      |      |      |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_FUNCTION] = LAYOUT(
      _______,  KC_F9 ,  KC_F10,  KC_F11,  KC_F12, _______,                                     _______, _______, _______, _______, _______, _______,
      _______,  KC_F5 ,  KC_F6 ,  KC_F7 ,  KC_F8 , _______,                                     _______, KC_RSFT, KC_RCTL, KC_LALT, KC_RGUI, _______,
      _______,  KC_F1 ,  KC_F2 ,  KC_F3 ,  KC_F4 , _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

/*
 * Adjust Layer: Default layer settings, RGB
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |                              | TOG  | SAI  | HUI  | VAI  | MOD  |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |      |      |Colmak|      |      |      |      |  |      |      |      | SAD  | HUD  | VAD  | RMOD |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_ADJUST] = LAYOUT(
      _______,  _______ ,  _______,  _______,  _______, _______,                                     _______, _______, _______, _______, _______, _______,
      _______,  _______ ,  _______ ,  _______ ,  _______ , _______,                                     RGB_TOG, RGB_SAI, RGB_HUI, RGB_VAI, RGB_MOD, _______,
      _______,  QK_CLEAR_EEPROM ,  _______ ,  COLEMAK ,  _______ , _______, _______, _______, _______, _______, _______, RGB_SAD, RGB_HUD, RGB_VAD, RGB_RMOD, _______,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

// /*
//  * Layer template
//  *
//  * ,-------------------------------------------.                              ,-------------------------------------------.
//  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
//  * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        `----------------------------------'  `----------------------------------'
//  */
//     [_LAYERINDEX] = LAYOUT(
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
//                                  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
//     ),
};

// void post_process_record_user(uint16_t keycode, keyrecord_t *record) {
//     switch(keycode) {
//         case MAGIC_TOGGLE_CTL_GUI:
//         {
//             // if(record->event.pressed) {
//             //     is_ctrl_and_gui_swapped = (is_ctrl_and_gui_swapped == 0) ? 1 : 0;  
//             // }
//             is_ctrl_and_gui_swapped++;
//         }
//         break;
//     }
// }

// from https://docs.splitkb.com/hc/en-us/articles/5799711553820-Power-LED
void keyboard_pre_init_user(void) {
  // Set our LED pin as output
  setPinOutput(24);
  // Turn the LED off
  // (Due to technical reasons, high is off and low is on)
  writePinHigh(24);
}


/* The default OLED and rotary encoder code can be found at the bottom of qmk_firmware/keyboards/splitkb/kyria/rev1/rev1.c
 * These default settings can be overriden by your own settings in your keymap.c
 * For your convenience, here's a copy of those settings so that you can uncomment them if you wish to apply your own modifications.
 * DO NOT edit the rev1.c file; instead override the weakly defined default functions by your own.
 */

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) { return rotation; }


bool oled_task_user(void) {
    if (is_keyboard_master()) {
        // QMK Logo and version information
        // clang-format off
        static const char PROGMEM qmk_logo[] = {
            0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94,
            0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,
            0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,0};
        // clang-format on

        oled_write_P(qmk_logo, false);
        oled_write_P(PSTR("Kyria rev2.1\n\n"), false);

        // Host Keyboard Layer Status
        oled_write_P(PSTR("Layer: "), false);
        switch (get_highest_layer(layer_state)) {
            case _COLEMAK_DH:
                oled_write_P(PSTR("Colemak-DH\n"), false);
                break;
            case _NAV:
                oled_write_P(PSTR("Nav\n"), false);
                break;
            case _SYM:
                oled_write_P(PSTR("Sym\n"), false);
                break;
            case _FUNCTION:
                oled_write_P(PSTR("Function\n"), false);
                break;
            case _ADJUST:
                oled_write_P(PSTR("Adjust\n"), false);
                break;
            case _NUM:
                oled_write_P(PSTR("NUM"), false);
                break;
            case _HANDS_DOWN_NEU:
                oled_write_P(PSTR("HANDS_DOWN_NEU"), false);
                break;
            default:
                oled_write_P(PSTR("Undefined\n"), false);
                break;
        }

        // Write host Keyboard LED Status to OLEDs
        led_t led_usb_state = host_keyboard_led_state();
        oled_write_P(led_usb_state.num_lock ? PSTR("NUMLCK ") : PSTR("       "), false);
        oled_write_P(led_usb_state.caps_lock ? PSTR("CAPLCK ") : PSTR("       "), false);
        oled_write_P(led_usb_state.scroll_lock ? PSTR("SCRLCK ") : PSTR("       "), false);

        oled_write_P(PSTR("keymap_config: "), false);
        oled_write(get_u8_str(keymap_config.raw, ' '), false);
        oled_write_P(PSTR("\n"), false);
    } else {
        // this is not the master
        // clang-format off
            // static const char PROGMEM kyria_logo[] = {
            //     0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,128,192,224,240,112,120, 56, 60, 28, 30, 14, 14, 14,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7, 14, 14, 14, 30, 28, 60, 56,120,112,240,224,192,128,128,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
            //     0,  0,  0,  0,  0,  0,  0,192,224,240,124, 62, 31, 15,  7,  3,  1,128,192,224,240,120, 56, 60, 28, 30, 14, 14,  7,  7,135,231,127, 31,255,255, 31,127,231,135,  7,  7, 14, 14, 30, 28, 60, 56,120,240,224,192,128,  1,  3,  7, 15, 31, 62,124,240,224,192,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
            //     0,  0,  0,  0,240,252,255, 31,  7,  1,  0,  0,192,240,252,254,255,247,243,177,176, 48, 48, 48, 48, 48, 48, 48,120,254,135,  1,  0,  0,255,255,  0,  0,  1,135,254,120, 48, 48, 48, 48, 48, 48, 48,176,177,243,247,255,254,252,240,192,  0,  0,  1,  7, 31,255,252,240,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
            //     0,  0,  0,255,255,255,  0,  0,  0,  0,  0,254,255,255,  1,  1,  7, 30,120,225,129,131,131,134,134,140,140,152,152,177,183,254,248,224,255,255,224,248,254,183,177,152,152,140,140,134,134,131,131,129,225,120, 30,  7,  1,  1,255,255,254,  0,  0,  0,  0,  0,255,255,255,  0,  0,  0,  0,255,255,  0,  0,192,192, 48, 48,  0,  0,240,240,  0,  0,  0,  0,  0,  0,240,240,  0,  0,240,240,192,192, 48, 48, 48, 48,192,192,  0,  0, 48, 48,243,243,  0,  0,  0,  0,  0,  0, 48, 48, 48, 48, 48, 48,192,192,  0,  0,  0,  0,  0,
            //     0,  0,  0,255,255,255,  0,  0,  0,  0,  0,127,255,255,128,128,224,120, 30,135,129,193,193, 97, 97, 49, 49, 25, 25,141,237,127, 31,  7,255,255,  7, 31,127,237,141, 25, 25, 49, 49, 97, 97,193,193,129,135, 30,120,224,128,128,255,255,127,  0,  0,  0,  0,  0,255,255,255,  0,  0,  0,  0, 63, 63,  3,  3, 12, 12, 48, 48,  0,  0,  0,  0, 51, 51, 51, 51, 51, 51, 15, 15,  0,  0, 63, 63,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 48, 48, 63, 63, 48, 48,  0,  0, 12, 12, 51, 51, 51, 51, 51, 51, 63, 63,  0,  0,  0,  0,  0,
            //     0,  0,  0,  0, 15, 63,255,248,224,128,  0,  0,  3, 15, 63,127,255,239,207,141, 13, 12, 12, 12, 12, 12, 12, 12, 30,127,225,128,  0,  0,255,255,  0,  0,128,225,127, 30, 12, 12, 12, 12, 12, 12, 12, 13,141,207,239,255,127, 63, 15,  3,  0,  0,128,224,248,255, 63, 15,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
            //     0,  0,  0,  0,  0,  0,  0,  3,  7, 15, 62,124,248,240,224,192,128,  1,  3,  7, 15, 30, 28, 60, 56,120,112,112,224,224,225,231,254,248,255,255,248,254,231,225,224,224,112,112,120, 56, 60, 28, 30, 15,  7,  3,  1,128,192,224,240,248,124, 62, 15,  7,  3,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
            //     0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  3,  7, 15, 14, 30, 28, 60, 56,120,112,112,112,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,112,112,112,120, 56, 60, 28, 30, 14, 15,  7,  3,  1,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0
            // };
        // clang-format on
        // oled_write_raw_P(kyria_logo, sizeof(kyria_logo));

        // if (keymap_config.swap_lctl_lgui) {
        //     oled_write_P(PSTR("GUI and CTRL swapped: Yes\n"), false);
        // } else {
        //     oled_write_P(PSTR("GUI and CTRL swapped: No\n"), false);
        // }
        // static const char PROGMEM mac_os_off[][6]  = {{0x90, 0x91, 0x92, 0x93, 0x94, 0}, {0xb0, 0xb1, 0xb2, 0xb3, 0xb4, 0}};
        // static const char PROGMEM mac_os_on[][6]   = {{0xd0, 0xd1, 0xd2, 0xd3, 0xd4, 0}, {0xf0, 0xf1, 0xf2, 0xf3, 0xf4, 0}};
        // static const char PROGMEM windows_off[][6] = {{0x95, 0x96, 0x97, 0x98, 0x99, 0}, {0xb5, 0xb6, 0xb7, 0xb8, 0xb9, 0}};
        // static const char PROGMEM windows_on[][6]  = {{0xd5, 0xd6, 0xd7, 0xd8, 0xd9, 0}, {0xf5, 0xf6, 0xf7, 0xf8, 0xf9, 0}};

        oled_write_P(PSTR("keymap_config: "), false);
        oled_write(get_u8_str(keymap_config.raw, ' '), false);
        if (keymap_config.swap_lctl_lgui) {
            // oled_set_cursor(10, 6);
            // oled_write_P(windows_on[0], false);
            // oled_set_cursor(10, 7);
            // oled_write_P(windows_on[1], false);
            // oled_set_cursor(10, 4);
            // oled_write_P(mac_os_off[0], false);
            // oled_set_cursor(10, 5);
            // oled_write_P(mac_os_off[1], false);
            oled_write_P(PSTR("Windows On\n"), false);
        } else {
            // oled_set_cursor(10, 4);
            // oled_write_P(mac_os_on[0], false);
            // oled_set_cursor(10, 5);
            // oled_write_P(mac_os_on[1], false);
            // oled_set_cursor(10, 6);
            // oled_write_P(windows_off[0], false);
            // oled_set_cursor(10, 7);
            // oled_write_P(windows_off[1], false);
            oled_write_P(PSTR("macOS On\n"), false);
        }
    }
    return false;
}
#endif

#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {
    // index 0 is on the left side
    if (index == 0) {
        // up/down navigation
        if (clockwise) {
            // tap_code(KC_VOLU);
            // tap_code(KC_DOWN);
            // tap_code(KC_DOWN);
            // tap_code(KC_DOWN);
            tap_code(KC_MS_WH_DOWN);
            tap_code(KC_MS_WH_DOWN);
            tap_code(KC_MS_WH_DOWN);
        } else {
            // tap_code(KC_VOLD);
            // tap_code(KC_UP);
            // tap_code(KC_UP);
            // tap_code(KC_UP);
            tap_code(KC_MS_WH_UP);
            tap_code(KC_MS_WH_UP);
            tap_code(KC_MS_WH_UP);
        }
        // index 1 is on the right side
    } else if (index == 1) {
        // Volume control
        if (clockwise) {
            // Windows and Linux can use C(KC_TAB) for ctrl.
            // macOS uses Meta instead.
            // tap_code16(G(KC_TAB));
            tap_code(KC_VOLU);
        } else {
            // tap_code16(S(G(KC_TAB)));
            tap_code(KC_VOLD);
        }
    }
    return false;
}
#endif

#ifdef RGBLIGHT_ENABLE
void keyboard_post_init_user(void) {
    rgblight_enable_noeeprom(); // Enables RGB, without saving settings
    rgblight_sethsv_noeeprom(HSV_PURPLE);
    rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
}
#endif

/*
#ifdef RGBLIGHT_ENABLE

#    ifndef RGBLIGHT_LAYERS
void keyboard_post_init_user(void) {
    rgblight_enable_noeeprom(); // Enables RGB, without saving settings
    rgblight_sethsv_noeeprom(HSV_PURPLE);
    rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
}
#    endif

#    ifdef RGBLIGHT_LAYERS
const rgblight_segment_t PROGMEM default_layer[]  = RGBLIGHT_LAYER_SEGMENTS({0, 20, HSV_PURPLE});
const rgblight_segment_t PROGMEM shift_layers[]   = RGBLIGHT_LAYER_SEGMENTS({0, 20, HSV_TEAL});
const rgblight_segment_t PROGMEM control_layers[] = RGBLIGHT_LAYER_SEGMENTS({0, 20, HSV_YELLOW});
const rgblight_segment_t PROGMEM alt_layers[]     = RGBLIGHT_LAYER_SEGMENTS({0, 20, HSV_GREEN});
const rgblight_segment_t PROGMEM gui_layers[]     = RGBLIGHT_LAYER_SEGMENTS({0, 20, HSV_BLUE});

// const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(shift_layers, control_layers, alt_layers, gui_layers);

// void keyboard_post_init_keymap(void) { rgblight_layers = my_rgb_layers; }

// void matrix_scan_keymap(void) {
//     uint8_t mods = mod_config(get_mods() | get_oneshot_mods());
//     rgblight_set_layer_state(0, mods & MOD_MASK_SHIFT);
//     rgblight_set_layer_state(1, mods & MOD_MASK_CTRL);
//     rgblight_set_layer_state(2, mods & MOD_MASK_ALT);
//     rgblight_set_layer_state(3, mods & MOD_MASK_GUI);
// }

const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(default_layer, shift_layers,
                                                                               control_layers, // Overrides caps lock layer
                                                                               alt_layers,     // Overrides other layers
                                                                               gui_layers      // Overrides other layers
);

void keyboard_post_init_user(void) {
    rgblight_enable_noeeprom(); // Enables RGB, without saving settings
    rgblight_sethsv_noeeprom(HSV_PURPLE);
    rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);

    // Enable the LED layers
    rgblight_layers = my_rgb_layers;
}

// bool led_update_user(led_t led_state) {
//     rgblight_set_layer_state(0, led_state.caps_lock);
//     return true;
// }

layer_state_t default_layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(0, layer_state_cmp(state, _COLEMAK_DH));
    return state;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(1, layer_state_cmp(state, _NAV));
    rgblight_set_layer_state(2, layer_state_cmp(state, _NUM));
    rgblight_set_layer_state(3, layer_state_cmp(state, _SYM));
    rgblight_set_layer_state(4, layer_state_cmp(state, _FUNCTION));
    return state;
}

#    endif

#endif

*/