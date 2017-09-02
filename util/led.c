#ifndef LED_C_
#define LED_C_

/*
  Dorm LED Project: led.c
  This file contains utility functions for dorm LEDs.

  Created by: Mikayla Fischler
  9/30/2016 @ WPI
*/

/* ~~~ Color Helper Functions ~~~ */

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

// make a color from r, g, b input (each input is 0 to 255)
uint32_t Color(uint8_t r, uint8_t g, uint8_t b) {
	return ((uint32_t) r << 16) | ((uint32_t) g <<  8) | b;
}

// Input a value 0 to 255 to get a color value.
// The colours are a transition r - g - b - back to r.
uint32_t ColorWheel(byte WheelPos) {
	WheelPos = 255 - WheelPos;

	if (WheelPos < 85) {
		return Color(255 - WheelPos * 3, 0, WheelPos * 3);
	}

	if (WheelPos < 170) {
		WheelPos -= 85;
		return Color(0, WheelPos * 3, 255 - WheelPos * 3);
	}

	WheelPos -= 170;
	return Color(WheelPos * 3, 255 - WheelPos * 3, 0);
}

#endif
