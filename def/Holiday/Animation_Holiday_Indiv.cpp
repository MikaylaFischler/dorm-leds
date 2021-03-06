#include "Animation_Holiday.hpp"

/* ~~~ Generic Individual ~~~ */

// define the generic individual init
void Animation_Holiday_Indiv::init() {
  	Animation_Holiday::init();
	this->strips.push_back(this->id);
}

/* ~~~ Animation Holiday Earth Day: Single Strip Dual Color Alternating Fade ~~~ */

void Animation_Holiday_Indiv_EarthDay_Fade::init() {
 	Animation_Holiday_Indiv::init();
	this->name = F("Earth Day Fade");
    this->update_rate = 10;

	i = 0;
	mode = true;
	increasing = true;
}

void Animation_Holiday_Indiv_EarthDay_Fade::step() {
	if (mode) {
		// green
		for (uint16_t x = 0; x < this->strip->numPixels(); x++) {
			npsm[this->id]->setPixelColor(x, 0, i, 0);
		}
	} else {
		// blue
		for (uint16_t x = 0; x < this->strip->numPixels(); x++) {
			npsm[this->id]->setPixelColor(x, 0, 0, i);
		}
	}

	npsm[this->id]->show();

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
