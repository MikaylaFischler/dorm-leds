#include <Adafruit_NeoPixel.h>

/*
  Dorm LED Project: main.ino

  Created by: Michael Fischler
  9/20/2016 @ WPI
*/

// configuration (avoid pins 0 and 1)
#define STRIP_PIN_W1 8
#define STRIP_PIN_W2 9
#define STRIP_PIN_W3 10
#define STRIP_PIN_DT 11
#define STRIP_PIN_DB 12
#define STRIP_PIN_XX 13

#define STRIP_TYPE NEO_GRB + NEO_KHZ800

// RGB LED strips
Adafruit_NeoPixel window_generic  = Adafruit_NeoPixel(81, STRIP_PIN_XX, STRIP_TYPE);
Adafruit_NeoPixel window1 = Adafruit_NeoPixel(81, STRIP_PIN_W1, STRIP_TYPE);
Adafruit_NeoPixel window2 = Adafruit_NeoPixel(81, STRIP_PIN_W2, STRIP_TYPE);
Adafruit_NeoPixel window3 = Adafruit_NeoPixel(81, STRIP_PIN_W3, STRIP_TYPE);
Adafruit_NeoPixel desk1   = Adafruit_NeoPixel(28, STRIP_PIN_DT, STRIP_TYPE);
Adafruit_NeoPixel desk2   = Adafruit_NeoPixel(29, STRIP_PIN_DB, STRIP_TYPE);

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
  //test(strand);

  for(int i = 0; i < desk1.numPixels(); i++){
    desk1.setPixelColor(i, desk1.Color(100,50,150));
    //delay(20);
    desk1.show();
  }

  for(int i = 0; i < desk2.numPixels(); i++){
    desk2.setPixelColor(i, desk2.Color(100,50,150));
    //delay(20);
    desk2.show();
  }

  for(int i = 0; i <= 150; i++){
    for(int x = 0; x < window_generic.numPixels(); x++){
      setAllWindowPixelColor(x, window_generic.Color((int)(((float)i / 150.0) * 100), 0, i));
    }
    delay(10);
    showAllWindowStrips();
  }

  for(int i = 150; i >= 0; i--){
    for(int x = 0; x < window_generic.numPixels(); x++){
      setAllWindowPixelColor(x, window_generic.Color((int)(((float)i / 150.0) * 100), 0, i));
    }
    delay(10);
    showAllWindowStrips();
  }

  //fulltest();

  //led_main_loop();
  //ctrl_main_loop();
}

