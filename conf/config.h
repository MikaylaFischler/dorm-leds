#ifndef CONFIG_H_
#define CONFIG_H_

// pin configuration (avoid pins 0 and 1)
#define STRIP_PIN_W1 2
#define STRIP_PIN_W2 3
#define STRIP_PIN_W3 4
#define STRIP_PIN_CL 5
#define STRIP_PIN_CR 6
#define STRIP_PIN_XX 7

#define EQ_L_STROBE 32
#define EQ_L_RESET 33
#define EQ_L_INPUT A0

#define EQ_R_STROBE 34
#define EQ_R_RESET 35
#define EQ_R_INPUT A1

#define LCD_D7_PIN 49
#define LCD_D6_PIN 48
#define LDC_D5_PIN 51
#define LCD_D4_PIN 50
#define LCD_RS_PIN 53
#define LCD_E_PIN 52

#define RAND_SEED_ANALOG_NOISE_PORT A2

// strip length
// #define WINDOW_LENGTH 81
// #define DESK1_LENGTH 28
// #define DESK2_LENGTH 29

#define CEILING_LEFT_LENGTH 126
#define CEILING_RIGHT_LENGTH 135
#define WINDOW_A_LENGTH 33
#define WINDOW_B_LENGTH 34

// strip rectangle corners
// #define WINDOW_BOTTOM_RIGHT 9
// #define WINDOW_TOP_RIGHT 40
// #define WINDOW_TOP_LEFT 50
// #define WINDOW_BOTTOM_LEFT 80

// strip type
#define STRIP_TYPE_RGB NEO_GRB + NEO_KHZ800
#define STRIP_TYPE_RGBW NEO_GRBW + NEO_KHZ800

#endif
