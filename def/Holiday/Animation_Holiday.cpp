#include "Animation_Holiday.hpp"

/* ~~~ Generic Holiday ~~~ */

// define the generic holiday init
void Animation_Holiday::init() {
  	Animation::init();
  	this->max_exec = -1;
}

/* ~~~ Animation Holiday Earth Day: All Window Dual Color Alternating Fade ~~~ */

void Animation_Holiday_EarthDay_WinAllFade::init() {
 	Animation_Holiday::init();
 	this->name = F("Window Alternating Earth Day Fade");
    this->update_rate = 10;
 	this->strips.push_back(ID_WINDOW_1);
 	this->strips.push_back(ID_WINDOW_2);
 	this->strips.push_back(ID_WINDOW_3);

	i = 0;
	mode = true;
	increasing = true;
}

void Animation_Holiday_EarthDay_WinAllFade::step() {
	if (mode) {
		// blue green blue
		for (uint16_t x = 0; x < WINDOW_LENGTH; x++) {
			npsm[ID_WINDOW_1]->setPixelColor(x, 0, 0, i);
			npsm[ID_WINDOW_2]->setPixelColor(x, 0, i, 0);
			npsm[ID_WINDOW_3]->setPixelColor(x, 0, 0, i);
		}
	} else {
		// green blue green
		for (uint16_t x = 0; x < WINDOW_LENGTH; x++) {
			npsm[ID_WINDOW_1]->setPixelColor(x, 0, i, 0);
			npsm[ID_WINDOW_2]->setPixelColor(x, 0, 0, i);
			npsm[ID_WINDOW_3]->setPixelColor(x, 0, i, 0);
		}
	}

	npsm[ID_WINDOW_1]->show();
	npsm[ID_WINDOW_2]->show();
	npsm[ID_WINDOW_3]->show();

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
