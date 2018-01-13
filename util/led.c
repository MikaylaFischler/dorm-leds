#ifndef LED_C_
#define LED_C_

/*!
	@file led.c
  	@brief This file contains utility functions for the LEDs.
	This includes breaking RGB colors into their components and a color wheel function.
*/

/* ~~~ Color Helper Functions ~~~ */

/*!
	@brief Produces Red component of 32-bit RGB
	@param color 32-bit RGB color
	@return the Red component (8-bit) of a 32-bit color
*/
uint8_t redFromColor(uint32_t color){
    return (color >> 16) & 0xFF;
}

/*!
	@brief Produces Green component of 32-bit RGB
	@param color 32-bit RGB color
	@return the Green component (8-bit) of a 32-bit color
*/
uint8_t greenFromColor(uint32_t color){
    return (color >> 8) & 0xFF;
}

/*!
	@brief Produces Blue component of 32-bit RGB
	@param color 32-bit RGB color
	@return the Blue component (8-bit) of a 32-bit color
*/
uint8_t blueFromColor(uint32_t color){
    return color & 0xFF;
}

/*!
	@brief Produce 32-bit RGB from 8-bit components
	@param r red component
	@param g green component
	@param b blue component
	@return 32-bit RGB color
*/
// make a color from r, g, b input (each input is 0 to 255)
uint32_t Color(uint8_t r, uint8_t g, uint8_t b) {
	return ((uint32_t) r << 16) | ((uint32_t) g <<  8) | b;
}

/*!
	@brief Continuous color wheel function.
	Input a value 0 to 255 to get a color value.
	The colours are a transition r - g - b - back to r.
	@param WheelPos a number from 0 to 255 giving a position in the color wheel
	@return 32-bit RGB color
*/
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
