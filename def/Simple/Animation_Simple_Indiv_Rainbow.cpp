#include "Animation_Simple.hpp"

/* ~~~ Animation Simple: Rainbow ~~~ */

Animation_Simple_Indiv_Rainbow::Animation_Simple_Indiv_Rainbow(Adafruit_NeoPixel* strip) {
	this->strip = strip;
}

void Animation_Simple_Indiv_Rainbow::init() {
	Animation_Simple_Indiv::init();
	this->name = getNameOfStrip(this->strip);
	this->name += F(": Rainbow");
    this->update_rate = 50;
	this->strips = getAsStripArray(this->strip);

	this->stack = new LocalStack();
	this->stack->push(new MemObj(new unsigned short int(0)));
}

void Animation_Simple_Indiv_Rainbow::step() {
	unsigned short int& i = this->stack->get(0)->get<unsigned short int>();

	// set each led to the proper color
	for (unsigned int j = 0; j < this->strip->numPixels(); j++) {
		this->strip->setPixelColor(j, ColorWheel((i + j) & 255));
	}

	this->strip->show();

	if (i == 255) {
		i = 0;
		this->current_exec++;
	} else {
		i++;
	}
}

void Animation_Simple_Indiv_Rainbow::clean() {
	this->stack->get(0)->destroy<unsigned short int>();

	delete this->stack;
}

/* ~~~ Animation Simple: Rainbow Cycle ~~~ */

Animation_Simple_Indiv_RainbowCycle::Animation_Simple_Indiv_RainbowCycle(Adafruit_NeoPixel* strip) {
	this->strip = strip;
}

void Animation_Simple_Indiv_RainbowCycle::init() {
	Animation_Simple_Indiv::init();
	this->name = getNameOfStrip(this->strip);
	this->name += F(": Rainbow Cycle");
    this->update_rate = 50;
	this->strips = getAsStripArray(this->strip);

	this->stack = new LocalStack();
	this->stack->push(new MemObj(new unsigned short int(0)));
}

void Animation_Simple_Indiv_RainbowCycle::step() {
	unsigned short int& i = this->stack->get(0)->get<unsigned short int>();

	// set each led to the proper color
	for (unsigned int j = 0; j < this->strip->numPixels(); j++) {
		this->strip->setPixelColor(j, ColorWheel(((j * 256 / this->strip->numPixels()) + i) & 255));
	}

	this->strip->show();

	if (i == 255) {
		i = 0;
		this->current_exec++;
	} else {
		i++;
	}
}

void Animation_Simple_Indiv_RainbowCycle::clean() {
	this->stack->get(0)->destroy<unsigned short int>();

	delete this->stack;
}
