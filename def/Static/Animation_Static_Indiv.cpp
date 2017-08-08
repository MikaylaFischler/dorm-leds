#include "Animation_Static.hpp"

/* ~~~ Generic Individual ~~~ */

// define the generic individual init
void Animation_Static_Indiv::init() {
  	Animation_Static::init();
	this->num_strips = 1;
	this->name = getNameOfStrip(this->strip);
	this->strips = getAsStripArray(this->strip);
}

/* ~~~ Animation Static Individual: Single Color ~~~ */

void Animation_Static_Indiv_Color::init() {
	Animation_Static_Indiv::init();
	this->name += F(": Single Color");
}

void Animation_Static_Indiv_Color::step() {
	for (unsigned int i = 0; i < this->strip->numPixels(); i++) {
		this->strip->setPixelColor(i, this->color);
	}

	this->strip->show();
	this->current_exec++;
}

/* ~~~ Animation Static Individual: Single Color ~~~ */

void Animation_Static_Indiv_ThirdDimAmbient::init() {
	Animation_Static_Indiv::init();
	this->name += F(": Third Dim Ambient");
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
