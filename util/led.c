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

/* ~~~ Window Functions ~~~ */

// set three individual colors (1 per window strip) per LED by index
void setWindowPixelColor(uint16_t index, uint32_t win1_c, uint32_t win2_c, uint32_t win3_c){
    window1.setPixelColor(index, win1_c);
    window2.setPixelColor(index, win2_c);
    window3.setPixelColor(index, win3_c);
}

// set the color of all three windows at once per LED by index
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
