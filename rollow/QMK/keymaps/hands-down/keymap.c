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

/* Updated 2/3/2023 */

#include QMK_KEYBOARD_H
#include "g/keymap_combo.h"

enum layers {
    HANDS_DOWN = 0,  // Default alpha layer
    EXTRA,           // QWERTY
    SYM,             // Symbols
    NAV,             // Navigation
    FUN,             // F keys + keyboard settings
    NUM,             // Numbers
    MEDIA,           // Play, pause, etc.
    MOUSE,           // Mouse keys
    BUTTON,          // Shortcuts for copy/paste, alt/control/GUI/shift, etc.
    EMOJI,           // Emojis, like ¯\_(ツ)_/¯
};



// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/*
 * Keyboard Layout:
 *
 * ,----------------------------------.                              ,----------------------------------.
 * |      |      |      |      |      |                              |      |      |      |      |      |
 * |------+------+------+------+------|                              |------+------+------+------+------|
 * |      |      |      |      |      |                              |      |      |      |      |      | 
 * |------+------+------+------+------|                              |------+------+------+------+------|
 * |      |      |      |      |      |                              |      |      |      |      |      |
 * `------+------+------+------+------|------.                ,------|------+------+------+-------------'
 *                      |      |      |      |                |      |      |      |
 *                      |      |      |      |                |      |      |      |
 *                      |      |      |      |                |      |      |      |
 *                      `--------------------'                `--------------------'
 */


/*
 * Base Layer: HANDS DOWN GOLD (Neu-tx)
 *
 * ,----------------------------------.                              ,----------------------------------.
 * |   J  |   G  |   M  |   P  |   V  |                              |  ; : |  , < |  . > |   !  | / ?  |
 * |------+------+------+------+------|                              |------+------+------+------+------|
 * |   R  |   S  |   N  |   D  |   B  |                              |   &  |   A  |   E  |   I  |   H  | 
 * |------+------+------+------+------|                              |------+------+------+------+------|
 * |   X  |   F  |   L  |   C  |   W  |                              | - _  |   U  |   O  |   Y  |   K  |
 * `------+------+------+------+------|------.                ,------|------+------+------+-------------'
 *                      |PGUPDN|Bckspc|  T   |                |Enter |Space |Vol   |
 *                      |Esc   |SYM   | NAV  |                |SYM   |NAV   |Delete|
 *                      |NUM   |      |      |                |      |      |FUN   |
 *                      `--------------------'                `--------------------'
 */

[HANDS_DOWN] = LAYOUT
    (KC_J        , KC_G         , KC_M           , KC_P           , KC_V            ,                                       KC_SCLN        , KC_COMM           , KC_DOT       , KC_EXLM      , KC_SLSH      , 
    LCTL_T(KC_R) , LALT_T(KC_S) , LGUI_T(KC_N)   , LSFT_T(KC_D)   , KC_B            ,                                       KC_AMPR        , LSFT_T(KC_A)      , LGUI_T(KC_E) , LALT_T(KC_I) , LCTL_T(KC_H) , 
    KC_X         , KC_F         , KC_L           , KC_C           , KC_W            ,                                       KC_MINS        , KC_U              , KC_O         , KC_Y         , KC_K         , 
                                                   LT(NUM,KC_ESC) , LT(SYM,KC_BSPC) , LT(NAV,KC_T),        LT(SYM,KC_ENT) , LT(NAV,KC_SPC) , LT(FUN,KC_DEL)    ), 

/*
 * Extra Layer: QWERTY
 *
 * ,----------------------------------.                              ,----------------------------------.
 * |   Q  |   W  |   E  |   R  |   T  |                              |   Y  |   U  |   I  |   O  |   P  |
 * |------+------+------+------+------|                              |------+------+------+------+------|
 * |   A  |   S  |   D  |   F  |   G  |                              |   H  |   J  |   K  |   L  |   '  | 
 * |------+------+------+------+------|                              |------+------+------+------+------|
 * |   Z  |   X  |   C  |   V  |   B  |                              |   N  |   M  |   ,  |   .  | / BTN|
 * `------+------+------+------+------|------.                ,------|------+------+------+-------------'
 *                      | Esc  |Space | Tab  |                |Enter |Bckspc|Delete|
 *                      |MEDIA | NAV  |MOUSE |                | SYM  | NUM  | FUN  |
 *                      |      |      |      |                |      |      |      |
 *                      `--------------------'                `--------------------'
 */



/*
 * Tap Layer:
 *
 * ,----------------------------------.                              ,----------------------------------.
 * |   Q  |   W  |   E  |   R  |   T  |                              |   Y  |   U  |   I  |   O  |   P  |
 * |------+------+------+------+------|                              |------+------+------+------+------|
 * |   A  |   S  |   D  |   F  |   G  |                              |   H  |   J  |   K  |   L  |   '  | 
 * |------+------+------+------+------|                              |------+------+------+------+------|
 * |   Z  |   X  |   C  |   V  |   B  |                              |   N  |   M  |   ,  |   .  | / BTN|
 * `------+------+------+------+------|------.                ,------|------+------+------+-------------'
 *                      | Esc  |Space | Tab  |                |Enter |Bckspc|Delete|
 *                      |      |      |      |                |      |      |      |
 *                      |      |      |      |                |      |      |      |
 *                      `--------------------'                `--------------------'
 */



/*
 * Button Layer:
 *
 * ,----------------------------------.                              ,----------------------------------.
 * | Undo | Cut  | Copy |Paste |Again |                              |Again |Paste | Copy | Cut  | Undo |
 * |------+------+------+------+------|                              |------+------+------+------+------|
 * | Ctrl |  Alt | Gui  | Shift| Meta |                              |      |Shift | Gui  | Alt  |Ctrl  | 
 * |------+------+------+------+------|                              |------+------+------+------+------|
 * | Undo | Cut  | Copy |Paste |Again |                              |Again |Paste | Copy | Cut  | Undo |
 * `------+------+------+------+------|------.                ,------|------+------+------+-------------'
 *                      |Middle| Left |Right |                |Right | Left |Middle|
 *                      |Button|Button|Button|                |Button|Button|Button|
 *                      |      |      |      |                |      |      |      |
 *                      `--------------------'                `--------------------'
 */



/*
 * NAV Layer: Navigation
 *
 * ,----------------------------------.                              ,----------------------------------.
 * | Boot |To Tap|ToXtra|ToBase|      |                              |Again |Paste | Copy | Cut  | Undo |
 * |------+------+------+------+------|                              |------+------+------+------+------|
 * | Ctrl |  Alt | Gui  | Shift| Meta |                              |Cplkwd| Left | Down |  Up  |Right | 
 * |------+------+------+------+------|                              |------+------+------+------+------|
 * |      |AltGr |To Num|To Nav|      |                              |Insert| Home |Pg Up |Pg Dn | End  |
 * `------+------+------+------+------|------.                ,------|------+------+------+-------------'
 *                      |      |      |      |                |Enter |Bckspc|Delete|
 *                      |      |      |      |                |      |      |      |
 *                      |      |      |      |                |      |      |      |
 *                      `--------------------'                `--------------------'                            
 */
[NAV] = LAYOUT
    (KC_TRNS, KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS ,                                                     KC_TRNS , KC_HOME , KC_UP   , KC_PGUP , KC_VOLU , KC_DEL, 
    KC_TRNS , KC_LCTL , KC_LALT , KC_LGUI , KC_LSFT , KC_TRNS ,                                                     KC_TRNS , KC_LEFT , KC_DOWN , KC_RGHT , KC_VOLD , KC_INS,
    KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS ,             KC_TRNS , KC_TRNS , KC_TRNS , KC_END  , KC_MPLY , KC_PGDN , KC_MUTE , KC_PSCR, 
                                  KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS ,             KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS),

/*
 * Mouse Layer:
 *
 * ,----------------------------------.                              ,----------------------------------.
 * | Boot |To Tap|ToXtra|ToBase|      |                              |Again |Paste | Copy | Cut  | Undo |
 * |------+------+------+------+------|                              |------+------+------+------+------|
 * | Ctrl |  Alt | Gui  | Shift| Meta |                              |      |MsLeft|MsDown |MsUp |MsRght| 
 * |------+------+------+------+------|                              |------+------+------+------+------|
 * |      |AltGr |To Sym|ToMous|      |                              |      |      |      |      |      |
 * `------+------+------+------+------|------.                ,------|------+------+------+-------------'
 *                      |      |      |      |                |Right | Left |Middle|
 *                      |      |      |      |                |Button|Button|Button|
 *                      |      |      |      |                |      |      |      |
 *                      `--------------------'                `--------------------'
 */



/*
 * Media Layer
 *
 *,----------------------------------.                              ,----------------------------------.
 * | Boot |To Tap|ToXtra|ToBase|      |                              |      |      |      |      |      |
 * |------+------+------+------+------|                              |------+------+------+------+------|
 * | Ctrl |  Alt | Gui  | Shift| Meta |                              |      |      |      |      |      | 
 * |------+------+------+------+------|                              |------+------+------+------+------|
 * |      |      |To Fun|ToMdia|      |                              |      |      |      |      |      |
 * `------+------+------+------+------|------.                ,------|------+------+------+-------------'
 *                      |      |      |      |                | Stop | Play | Mute |
 *                      |      |      |      |                |      |Pause |      |
 *                      |      |      |      |                |      |      |      |
 *                      `--------------------'                `--------------------'
 */



/*
 * Number Layer: Numbers, some symbols
 *
 * ,----------------------------------.                              ,----------------------------------.
 * |      |  7 & | 8 *  | 9 (  |  }   |                              |      |ToBase|ToXtra|To Tap| Boot |
 * |------+------+------+------+------|                              |------+------+------+------+------|
 * |      |  4 $ | 5 %  | 6 ^  | + =  |                              |      |Shift | Gui  | Alt  |Ctrl  | 
 * |------+------+------+------+------|                              |------+------+------+------+------|
 * |      |  1 ! | 2 @  | 3 #  |      |                              |      |To Num|To Nav|AltGr |      |
 * `------+------+------+------+------|------.                ,------|------+------+------+-------------'
 *                      |      |      |      |                |      |      |      |
 *                      |      |  0 ) |      |                |      |      |      |
 *                      |      |      |      |                |      |      |      |
 *                      `--------------------'                `--------------------'
 */
[NUM] = LAYOUT
    (KC_GRV , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS ,                                                           KC_PSLS , KC_7   , KC_8    , KC_9 , KC_MINS , KC_TRNS, 
    KC_TILD , KC_HASH , KC_DLR  , KC_LPRN , KC_RPRN , KC_TRNS ,                                                           KC_PAST , KC_4   , KC_5    , KC_6 , KC_PLUS , KC_TRNS, 
    KC_PIPE , KC_TRNS , KC_TRNS , KC_LT   , KC_GT   , KC_TILD , KC_TRNS , KC_TRNS ,                   KC_TRNS , KC_TRNS , KC_0    , KC_1   , KC_2    , KC_3 , KC_EQL  , KC_TRNS, 
                                  KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS ,                   KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS),


/*
 * SYM Layer: Symbols, layer keys, HRMs
 *
 * ,----------------------------------.                              ,----------------------------------.
 * |  {   |  &   |   *  |   (  |   }  |                              |      |ToBase|ToXtra|To Tap| Boot |
 * |------+------+------+------+------|                              |------+------+------+------+------|
 * |  ; : |  $   |   %  |   ^  |  +   |                              | Meta |Shift | Gui  | Alt  |Ctrl  | 
 * |------+------+------+------+------|                              |------+------+------+------+------|
 * |  ~ ` |  !   |   @  |  #   |  |   |                              |      |To Sym|ToMous|AltGr |      |
 * `------+------+------+------+------|------.                ,------|------+------+------+-------------'
 *                      |      |      |      |                |      |      |      |
 *                      |  (   |   )  |  _   |                |      |      |      |
 *                      |      |      |      |                |      |      |      |
 *                      `--------------------'                `--------------------'
 */
[SYM] = LAYOUT
    (KC_GRV , KC_EXLM , KC_AT   , KC_LCBR , KC_RCBR , KC_PIPE ,                                               KC_TRNS , KC_AMPR , KC_TRNS  , KC_TRNS  , KC_TRNS , KC_TRNS, 
    KC_TILD , KC_HASH , KC_DLR  , KC_LPRN , KC_RPRN , KC_GRV  ,                                               KC_PLUS , KC_MINS , KC_SLSH  , KC_ASTR  , KC_PERC , KC_TRNS, 
    KC_PIPE , KC_PERC , KC_CIRC , KC_LT   , KC_GT   , KC_TILD , KC_TRNS , KC_TRNS ,        KC_TRNS , KC_TRNS, KC_AMPR , KC_EQL  , KC_LT    , KC_GT    , KC_SLSH , KC_TRNS, 
                                  KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS ,        KC_TRNS , KC_TRNS, KC_TRNS , KC_TRNS , KC_TRNS) ,



/*
 * Function Layer: Function keys, RGB
 *
 * ,----------------------------------.                              ,----------------------------------.
 * |  F12 |  F1  |  F1  |  F1  |PrtScn|                              |      |ToBase|ToXtra|To Tap| Boot |
 * |------+------+------+------+------|                              |------+------+------+------+------|
 * |  F11 |  F1  |  F1  |  F1  |Sclock|                              | Meta |Shift | Gui  | Alt  |Ctrl  | 
 * |------+------+------+------+------|                              |------+------+------+------+------|
 * |  F10 |  F1  |  F2  |  F1  |PseBrk|                              |      |To Num|To Nav|AltGr |      |
 * `------+------+------+------+------|------.                ,------|------+------+------+-------------'
 *                      | App  |Space | Tab  |                |      |      |      |
 *                      |      |      |      |                |      |      |      |
 *                      |      |      |      |                |      |      |      |
 *                      `--------------------'                `--------------------'
 */
[FUN] = LAYOUT
    (DF(HANDS_DOWN), KC_F9, KC_F10  , KC_F11  , KC_F12  , KC_TRNS ,                                                      KC_TRNS , KC_PSTE , KC_COPY , KC_CUT  , KC_UNDO  , DF(HANDS_DOWN), 
    DF(QWERTY)     , KC_F5, KC_F6   , KC_F7   , KC_F8   , KC_TRNS ,                                                      RGB_TOG , RGB_SAI , RGB_HUI , RGB_VAI , RGB_MOD  , DF(QWERTY), 
    KC_TRNS        , KC_F1, KC_F2   , KC_F3   , KC_F4   , KC_TRNS , KC_TRNS , KC_TRNS,               KC_TRNS , KC_TRNS , KC_TRNS , RGB_SAD , RGB_HUD , RGB_VAD , RGB_RMOD , KC_TRNS, 
                                      KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS,               KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS),


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
            case SYM:
                oled_write_P(PSTR("SYM\n"), false);
                break;
            case NAV:
                oled_write_P(PSTR("NAV\n"), false);
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