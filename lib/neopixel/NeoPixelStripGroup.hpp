/*!
	@file NeoPixelStripGroup.hpp
  	@brief This code allows control of multiple LED strips as one
*/

#ifndef NEOPIXELSTRIPGROUP_HPP_
#define NEOPIXELSTRIPGROUP_HPP_

#include <Arduino.h>
#include <Adafruit_NeoPixel.h>
#include <ArduinoSTL.h>
#include <vector>

using std::vector;

/*!
	@class This class supports jagged groups. This means that the strips can
		be different lengths, though if a strip doesn't have a pixel at an index
		that pixel will be skipped/ignored.
*/
class NeoPixelStripGroup {
private:
	bool rgbw;
	uint32_t longestStrip;
	uint16_t longestStripLength;

	vector<Adafruit_NeoPixel*> strips;
public:
	NeoPixelStripGroup(bool _rgbw) : rgbw(_rgbw), longestStripLength(0) {}
	NeoPixelStripGroup() : rgbw(false), longestStripLength(0) {}
	~NeoPiexlStripGroup() {}

	void addStrip(Adafruit_NeoPixel* strip);
	int numStrips() const;

	void show();
	void setPixelColor(uint16_t n, uint8_t r, uint8_t g, uint8_t b);
    void setPixelColor(uint16_t n, uint8_t r, uint8_t g, uint8_t b, uint8_t w);
    void setPixelColor(uint16_t n, uint32_t c);

	uint32_t getPixelColor(uint16_t n) const;
};

#endif
