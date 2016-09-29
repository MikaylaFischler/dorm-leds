#include <Adafruit_NeoPixel.h>

/*
  Dorm LED Project: main.ino

  Created by: Michael Fischler
  9/20/2016 @ WPI
 */

// configuration (avoid pins 0 and 1)
#define STRIP_PIN_W1 2
#define STRIP_PIN_W2 3
#define STRIP_PIN_W3 4
#define STRIP_PIN_DT 5
#define STRIP_PIN_DB 6

#define STRIP_TYPE NEO_GRB + NEO_KHZ800

// RGB LED strips
Adafruit_NeoPixel strand  = Adafruit_NeoPixel(150, STRIP_PIN_W1, STRIP_TYPE);
//Adafruit_NeoPixel window1 = Adafruit_NeoPixel(60, STRIP_PIN_W1, STRIP_TYPE);
//Adafruit_NeoPixel window2 = Adafruit_NeoPixel(60, STRIP_PIN_W2, STRIP_TYPE);
//Adafruit_NeoPixel window3 = Adafruit_NeoPixel(60, STRIP_PIN_W3, STRIP_TYPE);
//Adafruit_NeoPixel desk1   = Adafruit_NeoPixel(30, STRIP_PIN_DT, STRIP_TYPE);
//Adafruit_NeoPixel desk2   = Adafruit_NeoPixel(30, STRIP_PIN_DB, STRIP_TYPE);

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize pins
  set_pin_modes();
  
  // initialize LED strips and set them to off
  init_strips();
}

// the loop function runs over and over again forever
void loop() {
  // test LEDs
  test(strand);
  
  /*
  test(window1);
  test(window2);
  test(window3);
  test(desk1);
  test(desk2);*/
}

