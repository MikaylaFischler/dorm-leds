#include "Animation_Seasonal.hpp"

/* ~~~ Animation Seasonal Spring: Clear Sky Blue Color Fade */

Animation_Seasonal_Spring_ClearSkyFade::Animation_Seasonal_Spring_ClearSkyFade(Adafruit_NeoPixel* strip) {
	this->strip = strip;
}

void Animation_Seasonal_Spring_ClearSkyFade::init() {
 	Animation_Seasonal::init();
	this->name = getNameOfStrip(this->strip);
 	this->name += F(": Clear Skies");
	this->num_strips = 1;
	this->update_rate = 50;
	this->strips = getAsStripArray(this->strip);

	this->stack = new LocalStack();
	this->stack->push(new MemObj(new unsigned int(0)));
	this->stack->push(new MemObj(new bool(true)));
	this->stack->push(new MemObj(new unsigned short int(0)));
	this->stack->push(new MemObj(new unsigned short int(0)));
}

void Animation_Seasonal_Spring_ClearSkyFade::step() {
	static const int MAX_RED = 200;
	static const int MAX_GREEN = 180;
	static const int BLUE = 255;

	unsigned int& i = this->stack->get(0)->get<unsigned int>();
	bool& increasing = this->stack->get(1)->get<bool>();
	unsigned short int& red = this->stack->get(2)->get<unsigned short int>();
	unsigned short int& green = this->stack->get(3)->get<unsigned short int>();

	// step animation
	for (unsigned int x = 0; x < this->strip->numPixels(); x++) {
		this->strip->setPixelColor(x, MAX_RED - i, MAX_GREEN - i, BLUE);
	}

	if (increasing) {
		if (i >= 50) {
			i--;
			increasing = false;
		} else {
			i++;
		}
	} else {
		if (i <= 0) {
			i++;
			increasing = true;
		} else {
			i--;
		}
	}

}

void Animation_Seasonal_Spring_ClearSkyFade::clean() {
	this->stack->get(0)->destroy<unsigned int>();
	this->stack->get(1)->destroy<bool>();
	this->stack->get(2)->destroy<unsigned short int>();
	this->stack->get(3)->destroy<unsigned short int>();

	delete this->stack;
}
