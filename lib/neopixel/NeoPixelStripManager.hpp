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
	NeoPixelStripManager();
	~NeoPixelStripManager();

	void pushStrip(String name, bool rgbw, Adafruit_NeoPixel* strip);
	void dropStrip(int id);

	String name(int id);
	bool isRGBW(int id);
	bool inUse(int id);
	Animation* usedBy(int id);

	void use(int id, Animation* anim);
	void release(int id);

	Adafruit_NeoPixel* strip(int id);
};

#endif
