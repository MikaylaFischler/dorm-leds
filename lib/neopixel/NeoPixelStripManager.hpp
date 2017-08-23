#ifndef NEOPIXELSTRIPMANAGER_HPP_
#define NEOPIXELSTRIPMANAGER_HPP_

#include <Arduino.h>
#include <Adafruit_NeoPixel.h>
#include <ArduinoSTL.h>
#include <vector>

#include "../exe/Animation.hpp"

using std::vector;

class NeoPixelStripManager {
private:
	typedef struct {
		String name;
		bool rgbw;
		bool in_use;
		Animation* used_by;
	} strip_data;

	vector<Adafruit_NeoPixel*> strips;
	vector<strip_data*> data;
public:
	NeoPixelStripManager() {}
	~NeoPixelStripManager() {}

	void addStrip(String name, bool rgbw, Adafruit_NeoPixel* strip);
	void dropStrip(int id);
	int numStrips() const;

	String name(int id) const;
	bool isRGBW(int id) const;
	bool inUse(int id) const;
	Animation* usedBy(int id) const;

	Adafruit_NeoPixel* strip(int id);

	Adafruit_NeoPixel* operator[] (int id);

	void use(int id, Animation* anim);
	void release(int id);
};

#endif
