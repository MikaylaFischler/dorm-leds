#ifndef LED_C_
#define LED_C_

#include "../conf/strips.h"
#include "../lib/strip_id.h"

/*
  Dorm LED Project: led.c
  This file contains utility functions for dorm LEDs.

  Created by: Michael Fischler
  9/30/2016 @ WPI
*/

/* ~~~ General Utility Functions ~~~ */

String getNameOfStrip(Adafruit_NeoPixel* strip) {
	// compare actual memory address
	if (strip == &window1) {
		return F("Window[1]");
	} else if (strip == &window2) {
		return F("Window[2]");
	} else if (strip == &window3) {
		return F("Window[3]");
	} else if (strip == &desk1) {
		return F("Desk[1]");
	} else if (strip == &desk2) {
		return F("Desk[2]");
	}

	return "";
}

short int* getAsStripArray(Adafruit_NeoPixel* strip) {
	// compare actual memory address
	if (strip == &window1) {
		return WINDOW_1;
	} else if (strip == &window2) {
		return WINDOW_2;
	} else if (strip == &window3) {
		return WINDOW_3;
	} else if (strip == &desk1) {
		return DESK_BOTTOM;
	} else if (strip == &desk2) {
		return DESK_TOP;
	}

	return NULL;
}

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

/* ~~~ Window Functions ~~~ */

// set the color of all three windows at once
void setAllWindowPixelColor(uint16_t index, uint32_t color){
    window1.setPixelColor(index, color);
    window2.setPixelColor(index, color);
    window3.setPixelColor(index, color);
}

// shut off all window LEDs
void clearAllWindowLEDs(){
  for (int i = 0; i < WINDOW_LENGTH; i++) {
    setAllWindowPixelColor(i, Color(0, 0, 0));
  }
}

// show all window strips
void showAllWindowStrips(){
    window1.show();
    window2.show();
    window3.show();
}

#endif
