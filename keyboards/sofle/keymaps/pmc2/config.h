 /* Copyright 2021 Dane Evans
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
#pragma once


// Select hand configuration
#define MASTER_LEFT
// #define MASTER_RIGHT
// #define EE_HANDS

// Unused? user/devdev has an override for the actual font that this seems
// to trigger
#define CUSTOM_FONT

// Obsolete? Doesn't seem to be used anywhere.
#define CUSTOM_LAYER_READ //if you remove this it causes issues - needs better guarding

// LEDs are driven using the PWM driver.
#define WS2812_PWM_DRIVER PWMD1
#define WS2812_PWM_CHANNEL 3
#define WS2812_PWM_PAL_MODE 1
#define WS2812_DMA_STREAM STM32_DMA2_STREAM5
#define WS2812_DMA_CHANNEL 6

// Definitions for Tap-Hold
#define TAPPING_FORCE_HOLD
#ifdef TAPPING_TERM
    #undef TAPPING_TERM
    #define TAPPING_TERM 200
#endif

// Whether to reverse the directions of the encoders
// #define ENCODER_DIRECTION_FLIP

// Turn off RGBLIGHT when the host goes to sleep
#define RGBLIGHT_SLEEP
// Turn on RGBLIGHT Layers
#define RGBLIGHT_LAYERS

// ws2812 RGB LED
#define RGB_DI_PIN A10

#ifdef RGB_MATRIX_ENABLE
#define RGBLED_NUM 36    // Number of LEDs
#define DRIVER_LED_TOTAL RGBLED_NUM
#endif



// For defining the LED numbering
#define LAYOUTX(                                                        \
    /* */                         L0, R0,                               \
    L00, L01, L02, L03, L04, L05,           R05, R04, R03, R02, R01, R00, \
    /* */             LB0, LB1, LB2,     RB2, RB1, RB0,                 \
    L10, L11, L12, L13, L14, L15,           R15, R14, R13, R12, R11, R10, \
    L20, L21, L22, L23, L24, L25,           R25, R24, R23, R22, R21, R20, \
    L30, L31, L32, L33, L34, L35,           R35, R34, R33, R32, R31, R30, \
    /* */             LB3, LB4, LB5,     RB5, RB4, RB3,                 \
    /* */     L40, L41, L42, L43, L44, R44, R43, R42, R41, R40) \
    {                                                           \
    /* */   L0,                                                 \
            LB0, LB1, LB2, LB5, LB4, LB3,                       \
            L40, L30, L20, L10, L00,                            \
            L01, L11, L21, L31, L41,                            \
            L42, L32, L22, L12, L02,                            \
            L03, L13, L23, L33, L43,                            \
            L44, L34, L24, L14, L04,                            \
            L05, L15, L25, L35,                                 \
    /* */   R0,                                                 \
            RB0, RB1, RB2, RB5, RB4, RB3,                       \
            R40, R30, R20, R10, R00,                            \
            R01, R11, R21, R31, R41,                            \
            R42, R32, R22, R12, R02,                            \
            R03, R13, R23, R33, R43,                            \
            R44, R34, R24, R14, R04,                            \
            R05, R15, R25, R35}

#ifdef RGBLIGHT_ENABLE

#define RGBLIGHT_LED_MAP LAYOUTX(             \
    0, 1,                                     \
    14,15,16,17,18,19,     20,21,22,23,24,25, \
    2,3,4,                 5,6,7,             \
    26,27,28,29,30,31,     32,33,34,35,36,37, \
    38,39,40,41,42,43,     44,45,46,47,48,49, \
    50,51,52,53,54,55,     56,57,58,59,60,61, \
    8,9,10,                11,12,13,          \
    62,63,64,65,66,          67,68,69,70,71)


#undef RGBLED_NUM

#define RGBLIGHT_ANIMATIONS
#define RGBLIGHT_EFFECT_BREATHING
#define RGBLIGHT_EFFECT_RAINBOW_MOOD
#define RGBLIGHT_EFFECT_RAINBOW_SWIRL
#define RGBLIGHT_EFFECT_SNAKE
#define RGBLIGHT_EFFECT_KNIGHT
#define RGBLIGHT_EFFECT_CHRISTMAS
#define RGBLIGHT_EFFECT_STATIC_GRADIENT
#define RGBLIGHT_EFFECT_RGB_TEST
#define RGBLIGHT_EFFECT_ALTERNATING
#define RGBLIGHT_EFFECT_TWINKLE


#define POWERLED 1
#define BACKLIGHT 6
#define UNDERGLOW (4*6+5)
#define ONESIDE (POWERLED + BACKLIGHT + UNDERGLOW)

#define RGBLED_NUM (2*ONESIDE)
#define RGBLED_SPLIT { ONESIDE, ONESIDE }
#define RGBLIGHT_LIMIT_VAL 120
#define RGBLIGHT_HUE_STEP 10
#define RGBLIGHT_SAT_STEP 17
#define RGBLIGHT_VAL_STEP 17
#endif

#ifdef RGB_MATRIX_ENABLE
#   define RGB_MATRIX_KEYPRESSES // reacts to keypresses
// #   define RGB_MATRIX_KEYRELEASES // reacts to keyreleases (instead of keypresses)
// #   define RGB_DISABLE_AFTER_TIMEOUT 0 // number of ticks to wait until disabling effects
#   define RGB_DISABLE_WHEN_USB_SUSPENDED // turn off effects when suspended
#   define RGB_MATRIX_FRAMEBUFFER_EFFECTS
// #   define RGB_MATRIX_LED_PROCESS_LIMIT (DRIVER_LED_TOTAL + 4) / 5 // limits the number of LEDs to process in an animation per task run (increases keyboard responsiveness)
// #   define RGB_MATRIX_LED_FLUSH_LIMIT 16 // limits in milliseconds how frequently an animation will update the LEDs. 16 (16ms) is equivalent to limiting to 60fps (increases keyboard responsiveness)
#    define RGB_MATRIX_MAXIMUM_BRIGHTNESS 150 // limits maximum brightness of LEDs to 150 out of 255. Higher may cause the controller to crash.

#define RGB_MATRIX_STARTUP_MODE RGB_MATRIX_GRADIENT_LEFT_RIGHT

#    define RGB_MATRIX_HUE_STEP 8
#    define RGB_MATRIX_SAT_STEP 8
#    define RGB_MATRIX_VAL_STEP 8
#    define RGB_MATRIX_SPD_STEP 10

/* Disable the animations you don't want/need.  You will need to disable a good number of these    *
 * because they take up a lot of space.  Disable until you can successfully compile your firmware. */
 // #   undef ENABLE_RGB_MATRIX_ALPHAS_MODS
 // #   undef ENABLE_RGB_MATRIX_GRADIENT_UP_DOWN
 // #   undef ENABLE_RGB_MATRIX_BREATHING
 // #   undef ENABLE_RGB_MATRIX_CYCLE_ALL
 // #   undef ENABLE_RGB_MATRIX_CYCLE_LEFT_RIGHT
 // #   undef ENABLE_RGB_MATRIX_CYCLE_UP_DOWN
 // #   undef ENABLE_RGB_MATRIX_CYCLE_OUT_IN
 // #   undef ENABLE_RGB_MATRIX_CYCLE_OUT_IN_DUAL
 // #   undef ENABLE_RGB_MATRIX_RAINBOW_MOVING_CHEVRON
 // #   undef ENABLE_RGB_MATRIX_DUAL_BEACON
 // #   undef ENABLE_RGB_MATRIX_RAINBOW_BEACON
 // #   undef ENABLE_RGB_MATRIX_RAINBOW_PINWHEELS
 // #   undef ENABLE_RGB_MATRIX_RAINDROPS
 // #   undef ENABLE_RGB_MATRIX_JELLYBEAN_RAINDROPS
 // #   undef ENABLE_RGB_MATRIX_TYPING_HEATMAP
 // #   undef ENABLE_RGB_MATRIX_DIGITAL_RAIN
 // #   undef ENABLE_RGB_MATRIX_SOLID_REACTIVE
 // #   undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_SIMPLE
 // #   undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_WIDE
 // #   undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE
 // #   undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_CROSS
 // #   undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTICROSS
 // #   undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_NEXUS
 // #   undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS
 // #   undef ENABLE_RGB_MATRIX_SPLASH
 // #   undef ENABLE_RGB_MATRIX_MULTISPLASH
 // #   undef ENABLE_RGB_MATRIX_SOLID_SPLASH
 // #   undef ENABLE_RGB_MATRIX_SOLID_MULTISPLASH
#endif

// Make the Layer state available on the slave half
#define SPLIT_LAYER_STATE_ENABLE

// Synchronize turning on and off the slave OLED
#define SPLIT_OLED_ENABLE
