/*
  Dorm LED Project: led_util.c
  This file contains utility functions for dorm LEDs.

  Created by: Michael Fischler
  9/30/2016 @ WPI
*/

// set the color of all three windows at once
void setAllWindowPixelColor(uint16_t index, uint32_t color){
    window1.setPixelColor(index, color);
    window2.setPixelColor(index, color);
    window3.setPixelColor(index, color);
}

// show all window strips
void showAllWindowStrips(){
    window1.show();
    window2.show();
    window3.show();
}
