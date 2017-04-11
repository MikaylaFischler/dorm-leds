#ifndef CONFIG_H_
#define CONFIG_H_

// pin configuration (avoid pins 0 and 1)
#define STRIP_PIN_W1 8
#define STRIP_PIN_W2 9
#define STRIP_PIN_W3 10
#define STRIP_PIN_DT 11
#define STRIP_PIN_DB 12
#define STRIP_PIN_XX 14

#define DISABLE_LED_PIN 14
#define DISABLE_BTN_PIN 15
#define SELECT_LED_PIN 16
#define SELECT_BTN_PIN 17

#define MODE_WIN_LED_PIN 18
#define MODE_WIN_BTN_PIN 19

#define MODE_WIN3_LED_PIN 20
#define MODE_WIN3_BTN_PIN 21
#define MODE_WIN2_LED_PIN 22
#define MODE_WIN2_BTN_PIN 23
#define MODE_WIN1_LED_PIN 24
#define MODE_WIN1_BTN_PIN 25

#define MODE_DESK_LED_PIN 26
#define MODE_DESK_BTN_PIN 27

#define MODE_DESK2_LED_PIN 28
#define MODE_DESK2_BTN_PIN 29
#define MODE_DESK1_LED_PIN 30
#define MODE_DESK1_BTN_PIN 31

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
#define WINDOW_LENGTH 81
#define DESK1_LENGTH 28
#define DESK2_LENGTH 29

// strip rectangle corners
#define WINDOW_BOTTOM_RIGHT 9
#define WINDOW_TOP_RIGHT 40
#define WINDOW_TOP_LEFT 50
#define WINDOW_BOTTOM_LEFT 80

// strip type
#define STRIP_TYPE NEO_GRB + NEO_KHZ800

#endif
