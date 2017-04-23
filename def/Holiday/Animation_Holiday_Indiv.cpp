#include "Animation_Holiday.hpp"

/* ~~~ Generic Individual ~~~ */

Animation_Holiday_Indiv::Animation_Holiday_Indiv(Adafruit_NeoPixel* strip) {
	this->strip = strip;
}

// define the generic individual init
void Animation_Holiday_Indiv::init() {
  	Animation_Holiday::init();
	this->num_strips = 1;
	this->name = getNameOfStrip(this->strip);
	this->strips = getAsStripArray(this->strip);
}

/* ~~~ Animation Holiday Earth Day: Single Strip Dual Color Alternating Fade ~~~ */

void Animation_Holiday_Indiv_EarthDay_Fade::init() {
 	Animation_Holiday_Indiv::init();
	this->name += F(": Earth Day Fade");
    this->update_rate = 10;

	this->stack = new LocalStack();
	this->stack->push(new MemObj(new unsigned short int(0)));
	this->stack->push(new MemObj(new bool(true)));
	this->stack->push(new MemObj(new bool(true)));
}

void Animation_Holiday_Indiv_EarthDay_Fade::step() {
	unsigned short int& i = this->stack->get(0)->get<unsigned short int>();
	bool& mode = this->stack->get(1)->get<bool>();
	bool& increasing = this->stack->get(2)->get<bool>();

	if (mode) {
		// green
		for (int x = 0; x < this->strip->numPixels(); x++) {
			this->strip->setPixelColor(x, 0, i, 0);
		}
	} else {
		// blue
		for (int x = 0; x < this->strip->numPixels(); x++) {
			this->strip->setPixelColor(x, 0, 0, i);
		}
	}

	this->strip->show();

	if (increasing) {
		if (i == 255) {
			increasing = false;
			i--;
		} else {
			i++;
		}
	} else {
		if (i == 0) {
			increasing = true;
			i++;
			mode = !mode;
			this->current_exec++;
		} else {
			i--;
		}
	}
}

void Animation_Holiday_Indiv_EarthDay_Fade::clean() {
	this->stack->get(0)->destroy<unsigned short int>();
	this->stack->get(1)->destroy<bool>();
	this->stack->get(2)->destroy<bool>();

	delete this->stack;
}
