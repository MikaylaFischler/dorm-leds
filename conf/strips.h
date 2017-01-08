#ifndef STRIPS_H
#define STRIPS_H

#include "config.h"

// RGB LED strips
Adafruit_NeoPixel& window_generic  = Adafruit_NeoPixel(WINDOW_LENGTH, STRIP_PIN_XX, STRIP_TYPE);
Adafruit_NeoPixel& window1         = Adafruit_NeoPixel(WINDOW_LENGTH, STRIP_PIN_W1, STRIP_TYPE);
Adafruit_NeoPixel& window2         = Adafruit_NeoPixel(WINDOW_LENGTH, STRIP_PIN_W2, STRIP_TYPE);
Adafruit_NeoPixel& window3         = Adafruit_NeoPixel(WINDOW_LENGTH, STRIP_PIN_W3, STRIP_TYPE);
Adafruit_NeoPixel& desk1           = Adafruit_NeoPixel(DESK1_LENGTH,  STRIP_PIN_DT, STRIP_TYPE);
Adafruit_NeoPixel& desk2           = Adafruit_NeoPixel(DESK2_LENGTH,  STRIP_PIN_DB, STRIP_TYPE);

#endif
