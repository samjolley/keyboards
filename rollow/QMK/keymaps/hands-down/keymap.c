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

// Copyright 2019 Manna Harbour
// https://github.com/manna-harbour/miryoku
/* Updated 2/3/2023 */

#include QMK_KEYBOARD_H
#include "g/keymap_combo.h"

enum layers {
    BASE = 0,        // Default alpha layer - Hands Down Gold (Neu-tx)
    EXTRA,           // QWERTY
    TAP,             // 
    BUTTON,          // Shortcuts for copy/paste, alt/control/GUI/shift, etc.
    NAV,             // Navigation
    MOUSE,           // Mouse keys
    MEDIA,           // Play, pause, etc.
    NUM,             // Numbers
    SYM,             // Symbols
    FUN,             // Function keys + keyboard settings
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
 * Base Layer: Hands Down Gold (Neu-tx)
 *
 * ,----------------------------------.                              ,----------------------------------.
 * |   J  |   G  |   M  |   P  |   V  |                              |  ; : |  , < |  . > | / ?  | \ |  |
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
[BASE] = LAYOUT
    (KC_J        , KC_G         , KC_M           , KC_P           , KC_V            ,                                       KC_SCLN        , KC_COMM           , KC_DOT       , KC_SLSH      , KC_BSLSH     , 
    LCTL_T(KC_R) , LALT_T(KC_S) , LGUI_T(KC_N)   , LSFT_T(KC_D)   , KC_B            ,                                       KC_AMPR        , LSFT_T(KC_A)      , LGUI_T(KC_E) , LALT_T(KC_I) , LCTL_T(KC_H) , 
    KC_X         , KC_F         , KC_L           , KC_C           , KC_W            ,                                       KC_MINS        , KC_U              , KC_O         , KC_Y         , KC_K         , 
                                                   LT(NUM,KC_ESC) , LT(SYM,KC_BSPC) , LT(NAV,KC_T),        LT(SYM,KC_ENT) , LT(NAV,KC_SPC) , LT(FUN,KC_DEL)  ) , 

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
[EXTRA] = LAYOUT
    (KC_Q        , KC_W         , KC_E           , KC_R           , KC_T            ,                                       KC_Y           , KC_U             , KC_I         , KC_O         , KC_P            , 
    LCTL_T(KC_A) , LALT_T(KC_S) , LGUI_T(KC_D)   , LSFT_T(KC_F)   , KC_G            ,                                       KC_H           , LSFT_T(KC_J)     , LGUI_T(KC_K) , LALT_T(KC_L) , LCTL_T(KC_QUOT) , 
    KC_Z         , KC_X         , KC_C           , KC_V           , KC_B            ,                                       KC_N           , KC_M             , KC_COMM      , KC_DOT       , KC_SLSH         , 
                                                   LT(NUM,KC_ESC) , LT(SYM,KC_BSPC) , LT(NAV,KC_T),        LT(SYM,KC_ENT) , LT(NAV,KC_SPC) , LT(FUN,KC_DEL) ) , 



/*
 * Tap Layer:
 *
 * ,----------------------------------.                              ,----------------------------------.
 * |   J  |   G  |   M  |   P  |   V  |                              |  ; : |  , < |  . > | / ?  | \ |  |
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
[TAP] = LAYOUT
    (KC_J        , KC_G         , KC_M          , KC_P           , KC_V     ,                        KC_SCLN , KC_COMM      , KC_DOT       , KC_SLSH      , KC_BSLSH     ,  
    LCTL_T(KC_R) , LALT_T(KC_S) , LGUI_T(KC_N)  , LSFT_T(KC_D)   , KC_B     ,                        KC_AMPR , LSFT_T(KC_A) , LGUI_T(KC_E) , LALT_T(KC_I) , LCTL_T(KC_H) , 
    KC_X         , KC_F         , KC_L          , KC_C           , KC_W     ,                        KC_MINS , KC_U         , KC_O         , KC_Y         , KC_K         , 
                                                  KC_ESC         , KC_BSPC  , KC_T ,        KC_ENT , KC_SPC  , KC_DEL), 



/*
 * Button Layer:
 *
 * ,----------------------------------.                              ,----------------------------------.
 * | Undo | Cut  | Copy |Paste |Again |                              |Again |Paste | Copy | Cut  | Undo |
 * |------+------+------+------+------|                              |------+------+------+------+------|
 * | Ctrl |  Alt | Gui  | Shift|      |                              |      |Shift | Gui  | Alt  |Ctrl  | 
 * |------+------+------+------+------|                              |------+------+------+------+------|
 * | Undo | Cut  | Copy |Paste |Again |                              |Again |Paste | Copy | Cut  | Undo |
 * `------+------+------+------+------|------.                ,------|------+------+------+-------------'
 *                      |Middle| Left |Right |                |Right | Left |Middle|
 *                      |Button|Button|Button|                |Button|Button|Button|
 *                      |      |      |      |                |      |      |      |
 *                      `--------------------'                `--------------------'
 */
[BUTTON] = LAYOUT
    (KC_UNDO , KC_CUT  , KC_COPY  , KC_PASTE   , KC_AGAIN   ,                                 KC_AGAIN   , KC_PASTE     , KC_COPY  , KC_CUT  , KC_UNDO , 
    KC_LCTL  , KC_LALT , KC_LGUI  , KC_LSFT    , KC_TRNS    ,                                 KC_TRNS    , KC_LSFT      , KC_LGUI  , KC_LALT , KC_LCTL , 
    KC_UNDO  , KC_CUT  , KC_COPY  , KC_PASTE   , KC_AGAIN   ,                                 KC_AGAIN   , KC_PASTE     , KC_COPY  , KC_CUT  , KC_UNDO , 
                                    KC_MS_BTN2 , KC_MS_BTN1 , KC_MS_BTN3,        KC_MS_BTN3 , KC_MS_BTN1 , KC_MS_BTN2 ) , 


/*
 * NAV Layer: Navigation
 *
 * ,----------------------------------.                              ,----------------------------------.
 * | Boot |To Tap|ToXtra|ToBase|      |                              |Again |Paste | Copy | Cut  | Undo |
 * |------+------+------+------+------|                              |------+------+------+------+------|
 * | Ctrl |  Alt | Gui  | Shift| Meta |                              |CapsLk| Left | Down |  Up  |Right | 
 * |------+------+------+------+------|                              |------+------+------+------+------|
 * |      |AltGr |To Num|To Nav|      |                              |Insert| Home |Pg Up |Pg Dn | End  |
 * `------+------+------+------+------|------.                ,------|------+------+------+-------------'
 *                      |      |      |      |                |Enter |Bckspc|Delete|
 *                      |      |      |      |                |      |      |      |
 *                      |      |      |      |                |      |      |      |
 *                      `--------------------'                `--------------------'                            
 */
[NAV] = LAYOUT
    (RESET  , TG(TAP)  , TG(EXTRA) , TG(BASE) , KC_TRNS ,                          KC_AGAIN  , KC_PASTE  , KC_COPY  , KC_CUT     , KC_UNDO  , 
    KC_LCTL  , KC_LALT , KC_LGUI   , KC_LSFT  , KC_TRNS ,                          KC_CAPS   , KC_LEFT   , KC_DOWN  , KC_UP      , KC_RIGHT , 
    KC_TRNS  , KC_RALT , TG(NUM)   , TG(NAV)  , KC_TRNS ,                          KC_INSERT , KC_HOME   , KC_PGUP  , KC_PGDOWN  , KC_END  , 
                                     KC_TRNS  , KC_TRNS , KC_TRNS,        KC_ENT , KC_BSPC   , KC_DEL )  , 

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
[MOUSE] = LAYOUT
    (RESET  , TG(TAP) , TG(EXTRA) , TG(BASE)  , KC_TRNS ,                              KC_AGAIN   , KC_PASTE     , KC_COPY    , KC_CUT   , KC_UNDO     , 
    KC_LCTL , KC_LALT , KC_LGUI   , KC_LSFT   , KC_TRNS ,                              KC_TRNS    , KC_MS_LEFT   , KC_MS_DOWN , KC_MS_UP , KC_MS_RIGHT , 
    KC_TRNS , KC_RALT , TG(SYM)   , TG(MOUSE) , KC_TRNS ,                              KC_TRNS    , KC_TRNS      , KC_TRNS    , KC_TRNS  , KC_TRNS     , 
                                     KC_TRNS  , KC_TRNS , KC_TRNS,        KC_MS_BTN3 , KC_MS_BTN1 , KC_MS_BTN2 ) , 



/*
 * Media Layer
 *
 *,----------------------------------.                              ,----------------------------------.
 * | Boot |To Tap|ToXtra|ToBase|      |                              |      |      |      |      |      |
 * |------+------+------+------+------|                              |------+------+------+------+------|
 * | Ctrl |  Alt | Gui  | Shift|      |                              |      |      |      |      |      | 
 * |------+------+------+------+------|                              |------+------+------+------+------|
 * |      |      |To Fun|ToMdia|      |                              |      |      |      |      |      |
 * `------+------+------+------+------|------.                ,------|------+------+------+-------------'
 *                      |      |      |      |                | Stop | Play | Mute |
 *                      |      |      |      |                |      |Pause |      |
 *                      |      |      |      |                |      |      |      |
 *                      `--------------------'                `--------------------'
 */
[MEDIA] = LAYOUT
    (RESET  , TG(TAP) , TG(EXTRA) , TG(BASE)  , KC_TRNS ,                           KC_TRNS             , KC_TRNS    , KC_TRNS , KC_TRNS , KC_TRNS , 
    KC_LCTL , KC_LALT , KC_LGUI   , KC_LSFT   , KC_TRNS ,                           KC_TRNS             , KC_TRNS    , KC_TRNS , KC_TRNS , KC_TRNS , 
    KC_TRNS , KC_RALT , TG(FUN)   , TG(MEDIA) , KC_TRNS ,                           KC_TRNS             , KC_TRNS    , KC_TRNS , KC_TRNS , KC_TRNS , 
                                     KC_TRNS  , KC_TRNS , KC_TRNS,        KC_STOP , KC_MEDIA_PLAY_PAUSE , KC__MUTE ) , 



/*
 * Number Layer: Numbers, symbols on shift
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
    (KC_TRNS, KC_7 , KC_8 , KC_9    , KC_RBRC ,                           KC_TRNS , TG(BASE)  , TG(EXTRA) , TG(TAP) , RESET   , 
    KC_TRNS , KC_4 , KC_5 , KC_6    , KC_EQL  ,                           KC_TRNS , KC_LSFT   , KC_LGUI   , KC_LALT , KC_LCTL , 
    KC_TRNS , KC_1 , KC_2 , KC_3    , KC_TRNS ,                           KC_TRNS , TG(NUM)   , TG(NAV)   , KC_RALT , KC_TRNS , 
                            KC_TRNS , KC_0    , KC_TRNS,        KC_TRNS , KC_TRNS , KC_TRNS ) , 


/*
 * SYM Layer: Symbols, layer keys, HRMs
 *
 * ,----------------------------------.                              ,----------------------------------.
 * |  {   |  &   |   *  |   (  |   }  |                              |      |ToBase|ToXtra|To Tap| Boot |
 * |------+------+------+------+------|                              |------+------+------+------+------|
 * |  ; : |  $   |   %  |   ^  |  +   |                              |      |Shift | Gui  | Alt  |Ctrl  | 
 * |------+------+------+------+------|                              |------+------+------+------+------|
 * |  ~ ` |  !   |   @  |  #   |  |   |                              |      |To Sym|ToMous|AltGr |      |
 * `------+------+------+------+------|------.                ,------|------+------+------+-------------'
 *                      |      |      |      |                |      |      |      |
 *                      |  (   |   )  |  _   |                |      |      |      |
 *                      |      |      |      |                |      |      |      |
 *                      `--------------------'                `--------------------'
 */
[SYM] = LAYOUT
    (KC_LBRC , KC_AMPR , KC_ASTR , KC_LPRN , KC_RBRC ,                           KC_TRNS , TG(BASE)  , TG(EXTRA) , TG(TAP) , RESET   , 
    KC_SCLN  , KC_DLR  , KC_PERC , KC_CIRC , KC_PLUS ,                           KC_TRNS , KC_LSFT   , KC_LGUI   , KC_LALT , KC_LCTL , 
    KC_GRV   , KC_EXLM , KC_AT   , KC_HASH , KC_PIPE ,                           KC_TRNS , TG(SYM)   , TG(MOUSE) , KC_RALT , KC_TRNS , 
                                   KC_LPRN , KC_RPRN , KC_UNDS,        KC_TRNS , KC_TRNS , KC_TRNS ) , 



/*
 * Function Layer: Function keys
 *
 * ,----------------------------------.                              ,----------------------------------.
 * |  F12 |  F1  |  F1  |  F1  |PrtScn|                              |      |ToBase|ToXtra|To Tap| Boot |
 * |------+------+------+------+------|                              |------+------+------+------+------|
 * |  F11 |  F1  |  F1  |  F1  |Sclock|                              |      |Shift | Gui  | Alt  |Ctrl  | 
 * |------+------+------+------+------|                              |------+------+------+------+------|
 * |  F10 |  F1  |  F2  |  F1  |PseBrk|                              |      |To Num|To Nav|AltGr |      |
 * `------+------+------+------+------|------.                ,------|------+------+------+-------------'
 *                      | App  |Space | Tab  |                |      |      |      |
 *                      |      |      |      |                |      |      |      |
 *                      |      |      |      |                |      |      |      |
 *                      `--------------------'                `--------------------'
 */
[FUN] = LAYOUT
    (KC_F12, KC_F7  , KC_F8  , KC_F9  , KC_PSCR  ,                             KC_TRNS  , TG(BASE) , TG(EXTRA) , TG(TAP) , RESET   ,  
     KC_F11, KC_F4  , KC_F5  , KC_F6  , KC_SCRL  ,                             KC_TRNS  , KC_LSFT  , KC_LGUI   , KC_LALT , KC_LCTL , 
     KC_F10, KC_F1  , KC_F2  , KC_F3  , KC_PAUSE ,                             KC_TRNS  , TG(NUM)  , TG(NAV)   , KC_RALT , KC_TRNS ,   
                               KC_APP , KC_SPACE , KC_TAB ,          KC_TRNS , KC_TRNS  , KC_TRNS) ,

/*
 * Emoji Layer
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
            case BASE:
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