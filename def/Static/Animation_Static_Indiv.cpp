#include "Animation_Static.hpp"

/* ~~~ Generic Individual ~~~ */

// define the generic individual init
void Animation_Static_Indiv::init() {
  	Animation_Static::init();
	this->num_strips = 1;
}

/* ~~~ Animation Static Individual: Single Color ~~~ */

Animation_Static_Indiv_Color::Animation_Static_Indiv_Color(Adafruit_NeoPixel* strip, unsigned long int color) {
	this->strip = strip;
	this->color = color;
}

void Animation_Static_Indiv_Color::init() {
	Animation_Static_Indiv::init();
	this->name = getNameOfStrip(this->strip);
	this->name += F(": Single Color");
	this->strips = getAsStripArray(this->strip);
}

void Animation_Static_Indiv_Color::step() {
	for (unsigned int i = 0; i < this->strip->numPixels(); i++) {
		this->strip->setPixelColor(i, this->color);
	}

	this->strip->show();
	this->current_exec++;
}

/* ~~~ Animation Static Individual: Single Color ~~~ */

Animation_Static_Indiv_ThirdDimAmbient::Animation_Static_Indiv_ThirdDimAmbient(Adafruit_NeoPixel* strip) {
	this->strip = strip;
}

void Animation_Static_Indiv_ThirdDimAmbient::init() {
	Animation_Static_Indiv::init();
	this->name = getNameOfStrip(this->strip);
	this->name += F(": Third Dim Ambient");
	this->strips = getAsStripArray(this->strip);
}

void Animation_Static_Indiv_ThirdDimAmbient::step() {
	for (unsigned int i = 0; i < this->strip->numPixels(); i++) {
		if (i % 3 == 0) {
			this->strip->setPixelColor(i, COLOR_DIM_OFF_WHITE);
		} else {
			this->strip->setPixelColor(i, COLOR_OFF);
		}
	}

	this->strip->show();
	this->current_exec++;
}
