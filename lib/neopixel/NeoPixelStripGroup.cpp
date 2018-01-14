/*!
	@file NeoPixelStripGroup.cpp
  	@brief This code allows control of multiple LED strips as one
	@details This class supports jagged groups. This means that the strips can
		be different lengths, though if a strip doesn't have a pixel at an index
		that pixel will be skipped/ignored using the Adafruit_NeoPixel library.
*/

#include "NeoPixelStripGroup.hpp"

/*!
	@brief Add a new strip to the group
	@details Strips can be of different lengths but all must be of the same
		color type.
	@param[in] strip The NeoPixel strip to add to the group
*/
void NeoPixelStripGroup::addStrip(Adafruit_NeoPixel* strip) {
	if (longestStripLength == 0) {
		longestStrip = strips.size();
		longestStripLength = strip->numPixels();
	} else if (strip->numPixels() > longestStripLength) {
			longestStrip = strips.size();
			longestStripLength = strip->numPixels();
		}
	}

	this->strips.push_back(strip);
}

/*!
	@brief Get the number of strips
	@return The number of strips in the group
*/
int NeoPixelStripGroup::numStrips() const { return this->strips.size(); };

/*!
	@brief Show all of the member strips
*/
void NeoPixelStripGroup::show() {
	for (unsigned int i = 0; i < strips.size(); i++) {
		strips[i].show();
	}
}

/*!
	@brief Set the pixel color
	@param[in] n Index of pixel
	@param[in] r Red component
	@param[in] g Blue component
	@param[in] b Green component
*/
void NeoPixelStripGroup::setPixelColor(uint16_t n, uint8_t r, uint8_t g, uint8_t b) {
	for (unsigned int i = 0; i < strips.size(); i++) {
		strips[i].setPixelColor(n, r, g, b);
	}
}

/*!
	@brief Set the pixel color
	@details Validates RGBW support before executing.
	@param[in] n Index of pixel
	@param[in] r Red component
	@param[in] g Blue component
	@param[in] b Green component
	@param[in] w White component
*/
void NeoPixelStripGroup::setPixelColor(uint16_t n, uint8_t r, uint8_t g, uint8_t b, uint8_t w) {
	if (rgbw) {
		for (unsigned int i = 0; i < strips.size(); i++) {
			strips[i].setPixelColor(n, r, g, b, w);
		}
	}
}

/*!
	@brief Set the pixel color
	@param[in] n Index of pixel
	@param[in] c 32-bit color
*/
void NeoPixelStripGroup::setPixelColor(uint16_t n, uint32_t c) {
	for (unsigned int i = 0; i < strips.size(); i++) {
		strips[i].setPixelColor(n, c);
	}
}

/*!
	@brief Get the pixel color at pixel n
	@details If strips are not of the same length, the function will attempt to
		find a strip with a pixel at that position, otherwise it will return 0.
	@param[in] The index of the pixel
	@return The pixel color
*/
uint32_t NeoPixelStripGroup::getPixelColor(uint16_t n) {
	if (n >= longestStripLength) {
		return 0;
	} else {
		return strips[longestStrip]->getPixelColor(n);
	}
}
