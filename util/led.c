#ifndef LED_C
#define LED_C

/*
  Dorm LED Project: led.c
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

// shut off all window LEDs
void clearAllWindowLEDs(){
  for (int i = 0; i < WINDOW_LENGTH; i++) {
    setAllWindowPixelColor(i, window_generic.Color(0, 0, 0));
  }
}

// show all window strips
void showAllWindowStrips(){
    window1.show();
    window2.show();
    window3.show();
}

// returns the Red component of a 32-bit color
uint8_t redFromColor(uint32_t color){
    return (color >> 16) & 0xFF;
}

// returns the Green component of a 32-bit color
uint8_t greenFromColor(uint32_t color){
    return (color >> 8) & 0xFF;
}

// returns the Blue component of a 32-bit color
uint8_t blueFromColor(uint32_t color){
    return color & 0xFF;
}

#endif
