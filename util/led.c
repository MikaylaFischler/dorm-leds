#ifndef LED_C
#define LED_C

#include "../conf/strips.h"

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

// Input a value 0 to 255 to get a color value.
// The colours are a transition r - g - b - back to r.
uint32_t Wheel(byte WheelPos) {
	WheelPos = 255 - WheelPos;

	if (WheelPos < 85) {
		return window_generic.Color(255 - WheelPos * 3, 0, WheelPos * 3);
	}

	if (WheelPos < 170) {
		WheelPos -= 85;
		return window_generic.Color(0, WheelPos * 3, 255 - WheelPos * 3);
	}

	WheelPos -= 170;
	return window_generic.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
}

#endif
