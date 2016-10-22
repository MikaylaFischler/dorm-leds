/*
  Dorm LED Project: led_anim_basic.ino
  This file contains the initialization code for the dorm LED system.
  Base source from strandtest.ino from the AdafruitNeopixel examples.

  Created by: Michael Fischler
  9/30/2016 @ WPI
*/

void set_pin_modes() {
 //set pin modes here
}

void init_strips() {
  // Window Strips
  window1.begin();
  window1.show();
  
  window2.begin();
  window2.show();
  
  window3.begin();
  window3.show();

  // Desk Strips
  desk1.begin();
  desk1.show();
  
  desk2.begin();
  desk2.show();
}

void init_timing() {
  prev_time = millis();
}

