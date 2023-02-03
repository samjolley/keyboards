/* Copyright 2023 Sam Jolley
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
#include "g/keymap_combo.h"

enum layers {
    HANDS_DOWN = 0,
    QWERTY,
    LOWER,
    RAISE,
    FUN,
    ADJUST,
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/*
 * Base Layer: HANDS DOWN GOLD
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |  Esc   |   J  |   G  |   M  |   P  |   V  |                              |  ; : |  . & |  / ? |  ' " |   !  |  \  |  |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |Ctrl/Bsp|   R  |   S  |   N  |   D  |   B  |                              |  , < |   A  |   E  |   I  |   H  |  ' "   |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * | LShift |   X  |   F  |   L  |   C  |   W  |LShift|HDSDWN|  |QWERTY|LShift| - _  |   U  |   O  |   Y  | /  ? |  - _   |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        | LGUI |Delete|BSP   |   T  |Enter |  |Enter |Space |Tab   | BSP  |Menu  |
 *                        |      |FUN   |ADJUST|LOWER |RAISE |  |LOWER |RAISE |ADJUST| FUN  |Vol+/_|
 *                        `----------------------------------'  `----------------------------------'
 */

[HANDS_DOWN] = LAYOUT(
    KC_ESC          , KC_J  , KC_G   ,  KC_M    , KC_P           ,  KC_V               ,                                                                                     KC_SCLN           , KC_PDOT , KC_SLSH , KC_QUOT ,   KC_EXLM , KC_BSLS, 
    LCTL_T(KC_BSPC) , KC_R  , KC_S   ,  KC_N    , KC_D           ,  KC_B               ,                                                                                     KC_COMM           , KC_A    , KC_E    , KC_I    ,   KC_H    , KC_QUOT, 
    KC_LSFT         , KC_X  , KC_F   ,  KC_L    , KC_C           ,  KC_W               ,  KC_LSFT        ,  DF(HANDS_DOWN),            DF(QWERTY)       , KC_LSFT          , KC_MINS           , KC_U    , KC_O    , KC_Y    , KC_K    , KC_MINS , 
                                        KC_LGUI , LT(FUN,KC_DEL) ,  LT(ADJUST,KC_BSPC) ,  LT(LOWER,KC_T) ,  LT(RAISE,KC_ENT),          LT(LOWER,KC_ENT) , LT(RAISE,KC_SPC) , LT(ADJUST,KC_TAB) , KC_BSPC , KC_APP) ,

/*
 * Base Layer: QWERTY
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |  Esc   |   Q  |   W  |   E  |   R  |   T  |                              |   Y  |   U  |   I  |   O  |   P  |  \  |  |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |Ctrl/Bsp|   A  |   S  |   D  |   F  |   G  |                              |   H  |   J  |   K  |   L  | ;  : |  ' "   |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  |LShift|HDSDWN|  |QWERTY|LShift|   N  |   M  | ,  < | . >  | /  ? |  - _   |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        | LGUI |Delete|BSP   |   T  |Enter |  |Enter |Space |Tab   | BSP  |Menu  |
 *                        |      |FUN   |ADJUST|LOWER |RAISE |  |LOWER |RAISE |ADJUST| FUN  |Vol+/_|
 *                        `----------------------------------'  `----------------------------------'
 */
[QWERTY] = LAYOUT
    (KC_ESC         , KC_Q  , KC_W  , KC_E    , KC_R           , KC_T               ,                                                                                     KC_Y          , KC_U    , KC_I     , KC_O   , KC_P    , KC_BSLS, 
    LCTL_T(KC_BSPC) , KC_A  , KC_S  , KC_D    , KC_F           , KC_G               ,                                                                                     KC_H          , KC_J    , KC_K     , KC_L   , KC_SCLN , KC_QUOT, 
    KC_LSFT         , KC_Z  , KC_X  , KC_C    , KC_V           , KC_B               ,  KC_TRNS          , DF(HANDS_DOWN)   ,            DF(QWERTY)       , KC_TRNS      , KC_N          , KC_M    , KC_COMM  , KC_DOT , KC_SLSH , KC_MINS,
                                      KC_TRNS , LT(FUN,KC_DEL) , LT(ADJUST,KC_BSPC) ,  LT(LOWER,KC_SPC) , LT(RAISE,KC_ENT) ,            LT(LOWER,KC_ENT) , LT(RAISE,KC_SPC) , LT(ADJUST,KC_TAB) , KC_BSPC , KC_TRNS) ,

/*
 * LOWER Layer: Symbols
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |  ` ~   |  !   |  @   |  {   |  }   |  |   |                              |      |  &   |      |      |      |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |    ~   |  #   |  $   |  (   |  )   | ` ~  |                              |   +  |  -   |  /   |  *   |   %  |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |    |   |  %   |  ^   |  <   |  >   |  ~   |      |      |  |      |      |   &  |  +=  |  <   |  >   |  / ? |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
[LOWER] = LAYOUT
    (KC_GRV , KC_EXLM , KC_AT   , KC_LCBR , KC_RCBR , KC_PIPE ,                                               KC_TRNS , KC_AMPR , KC_TRNS  , KC_TRNS  , KC_TRNS , KC_TRNS, 
    KC_TILD , KC_HASH , KC_DLR  , KC_LPRN , KC_RPRN , KC_GRV  ,                                               KC_PLUS , KC_MINS , KC_SLSH  , KC_ASTR  , KC_PERC , KC_TRNS, 
    KC_PIPE , KC_PERC , KC_CIRC , KC_LT   , KC_GT   , KC_TILD , KC_TRNS , KC_TRNS,         KC_TRNS , KC_TRNS, KC_AMPR , KC_EQL  , KC_LT    , KC_GT    , KC_SLSH , KC_TRNS, 
                                  KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS ,        KC_TRNS , KC_TRNS, KC_TRNS , KC_TRNS , KC_TRNS) ,

/*
 * RAISE Layer: Media, navigation
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |      |      |      |      |      |                              |      | Home |   ↑  |PgeUp | VolUp| Delete |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        | Ctrl |  Alt | Gui  | Shift|      |                              |      |  ←   |   ↓  |   →  | VolDn| Insert |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |      |  |      |      |      | End  | Play |PgeDwn|VolMut| PrtSc  |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
[RAISE] = LAYOUT
    (KC_TRNS, KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS ,                                                     KC_TRNS , KC_HOME , KC_UP   , KC_PGUP , KC_VOLU , KC_DEL, 
    KC_TRNS , KC_LCTL , KC_LALT , KC_LGUI , KC_LSFT , KC_TRNS ,                                                     KC_TRNS , KC_LEFT , KC_DOWN , KC_RGHT , KC_VOLD , KC_INS,
    KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS ,             KC_TRNS , KC_TRNS , KC_TRNS , KC_END  , KC_MPLY , KC_PGDN , KC_MUTE , KC_PSCR, 
                                  KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS ,             KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS),

/*
 * Function Layer: Function keys, RGB
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |HANDSDWN|  F9  | F10  | F11  | F12  |      |                              |      |Paste | Copy | Cut  | Undo |HANDSDWN|
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * | QWERTY |  F5  |  F6  |  F7  |  F8  |      |                              | RGB  | Sat+ | Hue+ |Bright| RGB+ | QWERTY |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |  F1  |  F2  |  F3  |  F4  |      |      |      |  |      |      |      | Sat- | Hue- | Dim  | RGB- |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
[FUN] = LAYOUT
    (DF(HANDS_DOWN), KC_F9, KC_F10  , KC_F11  , KC_F12  , KC_TRNS ,                                                      KC_TRNS , KC_PSTE , KC_COPY , KC_CUT  , KC_UNDO  , DF(HANDS_DOWN), 
    DF(QWERTY)     , KC_F5, KC_F6   , KC_F7   , KC_F8   , KC_TRNS ,                                                      RGB_TOG , RGB_SAI , RGB_HUI , RGB_VAI , RGB_MOD  , DF(QWERTY), 
    KC_TRNS        , KC_F1, KC_F2   , KC_F3   , KC_F4   , KC_TRNS , KC_TRNS , KC_TRNS,               KC_TRNS , KC_TRNS , KC_TRNS , RGB_SAD , RGB_HUD , RGB_VAD , RGB_RMOD , KC_TRNS, 
                                      KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS,               KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS),

/*
 * Adjust Layer: Numbers, some symbols
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |      |      |      |      |      |                              |   /  |   7  |   8  |   9  |   -  |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |   ~    |   #  |   $  |   (  |  )   |      |                              |   *  |   4  |   5  |   6  |   +  |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |    |   |      |      |  <   |  >   |  ~   |      |      |  |      |      |   0  |   1  |   2  |   3  |   =  |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
[ADJUST] = LAYOUT
    (KC_GRV , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS ,                                                           KC_PSLS , KC_P7   , KC_P8    , KC_P9 , KC_PMNS , KC_TRNS, 
    KC_TILD , KC_HASH , KC_DLR  , KC_LPRN , KC_RPRN , KC_TRNS ,                                                           KC_PAST , KC_P4   , KC_P5    , KC_P6 , KC_PPLS , KC_TRNS, 
    KC_PIPE , KC_TRNS , KC_TRNS , KC_LT   , KC_GT   , KC_TILD , KC_TRNS , KC_TRNS ,                   KC_TRNS , KC_TRNS , KC_P0   , KC_P1   , KC_P2    , KC_P3 , KC_PEQL , KC_TRNS, 
                                  KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS ,                   KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS),
};

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) { return OLED_ROTATION_180; }

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
        oled_write_P(PSTR("Kyria rev1.0\n\n"), false);

        // Host Keyboard Layer Status
        oled_write_P(PSTR("Layer: "), false);
        switch (get_highest_layer(layer_state|default_layer_state)) {
            case HANDS_DOWN:
                oled_write_P(PSTR("HandsDown Gold\n"), false);
                break;
            case QWERTY:
                oled_write_P(PSTR("Qwerty\n"), false);
                break; 
            case LOWER:
                oled_write_P(PSTR("Lower\n"), false);
                break;
            case RAISE:
                oled_write_P(PSTR("Raise\n"), false);
                break;
            case FUN:
                oled_write_P(PSTR("Function\n"), false);
                break;   
            case ADJUST:
                oled_write_P(PSTR("Adjust\n"), false);
                break;
            default:
                oled_write_P(PSTR("Undefined\n"), false);
        }

        // Write host Keyboard LED Status to OLEDs
        led_t led_usb_state = host_keyboard_led_state();
        oled_write_P(led_usb_state.num_lock    ? PSTR("NUMLCK ") : PSTR("       "), false);
        oled_write_P(led_usb_state.caps_lock   ? PSTR("CAPLCK ") : PSTR("       "), false);
        oled_write_P(led_usb_state.scroll_lock ? PSTR("SCRLCK ") : PSTR("       "), false);
    } else {
        // clang-format off
        static const char PROGMEM kyria_logo[] = {
            0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,128,192,224,240,112,120, 56, 60, 28, 30, 14, 14, 14,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7, 14, 14, 14, 30, 28, 60, 56,120,112,240,224,192,128,128,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
            0,  0,  0,  0,  0,  0,  0,192,224,240,124, 62, 31, 15,  7,  3,  1,128,192,224,240,120, 56, 60, 28, 30, 14, 14,  7,  7,135,231,127, 31,255,255, 31,127,231,135,  7,  7, 14, 14, 30, 28, 60, 56,120,240,224,192,128,  1,  3,  7, 15, 31, 62,124,240,224,192,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
            0,  0,  0,  0,240,252,255, 31,  7,  1,  0,  0,192,240,252,254,255,247,243,177,176, 48, 48, 48, 48, 48, 48, 48,120,254,135,  1,  0,  0,255,255,  0,  0,  1,135,254,120, 48, 48, 48, 48, 48, 48, 48,176,177,243,247,255,254,252,240,192,  0,  0,  1,  7, 31,255,252,240,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
            0,  0,  0,255,255,255,  0,  0,  0,  0,  0,254,255,255,  1,  1,  7, 30,120,225,129,131,131,134,134,140,140,152,152,177,183,254,248,224,255,255,224,248,254,183,177,152,152,140,140,134,134,131,131,129,225,120, 30,  7,  1,  1,255,255,254,  0,  0,  0,  0,  0,255,255,255,  0,  0,  0,  0,255,255,  0,  0,192,192, 48, 48,  0,  0,240,240,  0,  0,  0,  0,  0,  0,240,240,  0,  0,240,240,192,192, 48, 48, 48, 48,192,192,  0,  0, 48, 48,243,243,  0,  0,  0,  0,  0,  0, 48, 48, 48, 48, 48, 48,192,192,  0,  0,  0,  0,  0,
            0,  0,  0,255,255,255,  0,  0,  0,  0,  0,127,255,255,128,128,224,120, 30,135,129,193,193, 97, 97, 49, 49, 25, 25,141,237,127, 31,  7,255,255,  7, 31,127,237,141, 25, 25, 49, 49, 97, 97,193,193,129,135, 30,120,224,128,128,255,255,127,  0,  0,  0,  0,  0,255,255,255,  0,  0,  0,  0, 63, 63,  3,  3, 12, 12, 48, 48,  0,  0,  0,  0, 51, 51, 51, 51, 51, 51, 15, 15,  0,  0, 63, 63,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 48, 48, 63, 63, 48, 48,  0,  0, 12, 12, 51, 51, 51, 51, 51, 51, 63, 63,  0,  0,  0,  0,  0,
            0,  0,  0,  0, 15, 63,255,248,224,128,  0,  0,  3, 15, 63,127,255,239,207,141, 13, 12, 12, 12, 12, 12, 12, 12, 30,127,225,128,  0,  0,255,255,  0,  0,128,225,127, 30, 12, 12, 12, 12, 12, 12, 12, 13,141,207,239,255,127, 63, 15,  3,  0,  0,128,224,248,255, 63, 15,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
            0,  0,  0,  0,  0,  0,  0,  3,  7, 15, 62,124,248,240,224,192,128,  1,  3,  7, 15, 30, 28, 60, 56,120,112,112,224,224,225,231,254,248,255,255,248,254,231,225,224,224,112,112,120, 56, 60, 28, 30, 15,  7,  3,  1,128,192,224,240,248,124, 62, 15,  7,  3,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
            0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  3,  7, 15, 14, 30, 28, 60, 56,120,112,112,112,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,112,112,112,120, 56, 60, 28, 30, 14, 15,  7,  3,  1,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0
        };
        // clang-format on
        oled_write_raw_P(kyria_logo, sizeof(kyria_logo));
    }
    return false;
}
#endif

#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {

    if (index == 0) {
        // Page up/Page down
        if (clockwise) {
            tap_code(KC_PGUP);
        } else {
            tap_code(KC_PGDN);
        }
    } else if (index == 1) {
        // Volume control
        if (clockwise) {
            tap_code(KC_VOLD);
        } else {
            tap_code(KC_VOLU);
        }
    }
    return false;
}
#endif