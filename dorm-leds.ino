#include <unwind-cxx.h>
#include <StandardCplusplus.h>
#include <system_configuration.h>
#include <utility.h>
#include <vector>

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
#define STRIP_PIN_XX 14

#define WINDOW_LENGTH 81
#define DESK1_LENGTH 28
#define DESK2_LENGTH 29

#define STRIP_TYPE NEO_GRB + NEO_KHZ800

// RGB LED strips
Adafruit_NeoPixel window_generic  = Adafruit_NeoPixel(WINDOW_LENGTH, STRIP_PIN_XX, STRIP_TYPE);
Adafruit_NeoPixel window1         = Adafruit_NeoPixel(WINDOW_LENGTH, STRIP_PIN_W1, STRIP_TYPE);
Adafruit_NeoPixel window2         = Adafruit_NeoPixel(WINDOW_LENGTH, STRIP_PIN_W2, STRIP_TYPE);
Adafruit_NeoPixel window3         = Adafruit_NeoPixel(WINDOW_LENGTH, STRIP_PIN_W3, STRIP_TYPE);
Adafruit_NeoPixel desk1           = Adafruit_NeoPixel(DESK1_LENGTH,  STRIP_PIN_DT, STRIP_TYPE);
Adafruit_NeoPixel desk2           = Adafruit_NeoPixel(DESK2_LENGTH,  STRIP_PIN_DB, STRIP_TYPE);

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

  for(int i = 0; i < DESK1_LENGTH; i++){
    if(i%3 == 0){
      desk1.setPixelColor(i, desk1.Color(0,0,0));
    }else{
      desk1.setPixelColor(i, desk1.Color(0,0,0));
    }
    //delay(20);
    desk1.show();
  }

  for(int i = 0; i < DESK2_LENGTH; i++){
    if(i%3 == 0){
      //desk2.setPixelColor(i, desk2.Color(75,45,25));
      desk2.setPixelColor(i, desk2.Color(0,0,0));
    }else{
      desk2.setPixelColor(i, desk2.Color(0,0,0));
    }
    //delay(20);
    desk2.show();
  }
  /*
  uint8_t red = window_generic.Color(172, 43, 55);
  uint8_t white = window_generic.Color(169, 176, 183);
  
  for(int i = 0; i < WINDOW_LENGTH; i++){
    window1.setPixelColor(i, window_generic.Color(255, 21, 27));
    if(i%2 == 0){
      window2.setPixelColor(i, window_generic.Color(169, 176, 183));
    }else{
      window2.setPixelColor(i, window_generic.Color(255, 21, 27));
    }
    
    int modified = WINDOW_LENGTH + 9 - 1 - i;
    if(modified >= WINDOW_LENGTH){
      modified -= WINDOW_LENGTH;
    }
    window3.setPixelColor(modified, window_generic.Color(255, 21, 27));
    //setAllWindowPixelColor(i, window_generic.Color(100, 20, 0));
    window1.show();
    window3.show();
    delay(10);
  }
  window2.show();
  
  /*
  for(int i = 0; i < WINDOW_LENGTH; i++){
    window1.setPixelColor(i, window_generic.Color(0, 0, 0));
    window2.setPixelColor(i, window_generic.Color(0, 0, 0));
    window3.setPixelColor(i, window_generic.Color(0, 0, 0));
    showAllWindowStrips();
    delay(2);
  }
  */
  /*
  for(int i = 0; i < WINDOW_LENGTH; i++){
    window1.setPixelColor(i, window_generic.Color(169, 176, 183));
    for(int j = 0; j < WINDOW_LENGTH; j++){
      if(i%2 != 0){
        window2.setPixelColor(i, window_generic.Color(169, 176, 183));
      }else{
        window2.setPixelColor(i, window_generic.Color(255, 21, 27));
      }
    }
    int modified = WINDOW_LENGTH + 9 - 1 - i;
    if(modified >= WINDOW_LENGTH){
      modified -= WINDOW_LENGTH;
    }
    window3.setPixelColor(modified, window_generic.Color(169, 176, 183));
    //setAllWindowPixelColor(i, window_generic.Color(100, 20, 0));
    window1.show();
    window3.show();
    delay(10);
  }
  window2.show();
  */
  /*
  for(int i = 0; i < WINDOW_LENGTH; i++){
    window1.setPixelColor(i, window_generic.Color(0, 0, 0));
    window2.setPixelColor(i, window_generic.Color(0, 0, 0));
    window3.setPixelColor(i, window_generic.Color(0, 0, 0));
    showAllWindowStrips();
    delay(2);
  }
  */
  /*
  for(int i = 0; i <= 150; i++){
    for(int x = 0; x < WINDOW_LENGTH; x++){
      setAllWindowPixelColor(x, window_generic.Color((int)(((float)i / 150.0) * 100), 0, i));
    }
    for(int y = 0; y < DESK1_LENGTH; y++){
      if(y%3 != 0){
        desk1.setPixelColor(y, desk1.Color((int)(((float)i / 150.0) * 100), 0, i));
      }
    }
    for(int z = 0; z < DESK2_LENGTH; z++){
      if(z%3 != 0){
        desk2.setPixelColor(z, desk2.Color((int)(((float)i / 150.0) * 100), 0, i));
      }
    }
    delay(10);
    desk1.show();
    desk2.show();
    showAllWindowStrips();
  }
  
  for(int i = 150; i >= 0; i--){
    for(int x = 0; x < WINDOW_LENGTH; x++){
      setAllWindowPixelColor(x, window_generic.Color((int)(((float)i / 150.0) * 100), 0, i));
    }
    for(int y = 0; y < DESK1_LENGTH; y++){
      if(y%3 != 0){
        desk1.setPixelColor(y, desk1.Color((int)(((float)i / 150.0) * 100), 0, i));
      }
    }
    for(int z = 0; z < DESK2_LENGTH; z++){
      if(z%3 != 0){
        desk2.setPixelColor(z, desk2.Color((int)(((float)i / 150.0) * 100), 0, i));
      }
    }
    delay(10);
    desk1.show();
    desk2.show();
    showAllWindowStrips();
  }
  */
  /*
  for(int i = 150; i >= 0; i--){
    for(int x = 0; x < WINDOW_LENGTH; x++){
      setAllWindowPixelColor(x, window_generic.Color((int)(((float)i /
      window2.setPixelColor(x, window_generic.Color(0, 0, 255-i));
      window3.setPixelColor(x, window_generic.Color(0, 0, i));
    }
    delay(2); 150.0) * 100), 0, i));
    }
    delay(10);
    showAllWindowStrips();
  }*/
  /*
  for(int i = 0; i <= 255; i+=1){
    for(int x = 0; x < WINDOW_LENGTH; x++){
      window1.setPixelColor(x, window_generic.Color(0, 0, i));
    showAllWindowStrips();
  }

  for(int i = 255; i >= 0; i-=1){
    for(int x = 0; x < WINDOW_LENGTH; x++){
      window1.setPixelColor(x, window_generic.Color(0, 0, i));
      window2.setPixelColor(x, window_generic.Color(0, 0, 255-i));
      window3.setPixelColor(x, window_generic.Color(0, 0, i));
    }
    delay(2);
    showAllWindowStrips();
  }
  */
  
  fulltest();

  //led_main_loop();
  //ctrl_main_loop();
}

