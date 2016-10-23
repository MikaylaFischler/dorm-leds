/*
  Dorm LED Project: main.ino
  Main file for the LED project.

  Created by: Michael Fischler
  9/20/2016 @ WPI
*/

// Standard C++ Library
#include <unwind-cxx.h>
#include <StandardCplusplus.h>
#include <system_configuration.h>
#include <utility.h>

// Threading System
#include "lib/Strip.h"
#include "lib/Command.cpp"
#include "lib/ThreadHandler.cpp"

// LED Library
#include <Adafruit_NeoPixel.h>

// Configuration
#include "conf/config.h"
#include "conf/strips.h"

// Commands
#include "def/led_desk_anim_cmds.cpp"
#include "def/led_window_anim_cmds.cpp"
#include "def/led_commands.cpp"

// Timing
unsigned long int prev_time = millis();
unsigned long int cur_time = millis();

// the setup function runs once when you press reset or power the board
void setup() {
  Serial.begin(38400);
  Serial.println("init");
  
  // initialize pins
  set_pin_modes();

  // initialize LED strips and set them to off
  init_strips();

  // initialize timing
  init_timing();

  // manual queue
  led_man_queue();
}
  
// the loop function runs over and over again forever
void loop() {
  // Run multithreaded system code
  led_main_loop();

  /* WPI SPIRIT CODE
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
  */
  
  /* SET EACH WINDOW CODE
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
  
  /* PURPLE FADE
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
  
  /* SOMETHING?
  for(int i = 150; i >= 0; i--){
    for(int x = 0; x < WINDOW_LENGTH; x++){
      setAllWindowPixelColor(x, window_generic.Color((int)(((float)i / 150.0) * 100), 0, i));
      window2.setPixelColor(x, window_generic.Color(0, 0, 255-i));
      window3.setPixelColor(x, window_generic.Color(0, 0, i));
      delay(2);
    }
    delay(10);
    showAllWindowStrips();
  }*/
  
  /* SINGLE COLOR FADE
  for(int i = 0; i <= 255; i+=1){
    for(int x = 0; x < WINDOW_LENGTH; x++){
      window1.setPixelColor(x, window_generic.Color(0, 0, i));
      window2.setPixelColor(x, window_generic.Color(0, 0, 255-i));
      window3.setPixelColor(x, window_generic.Color(0, 0, i));
    }
    delay(2);
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
  
  //fulltest();
  //ctrl_main_loop();
}

