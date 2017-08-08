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
 	this->name = F("Window[All]: Alternating Earth Day Fade");
    this->update_rate = 10;
	this->num_strips = 3;
 	this->strips = WINDOW_ALL;

	i = 0;
	mode = true;
	increasing = true;
}

void Animation_Holiday_EarthDay_WinAllFade::step() {
	if (mode) {
		// blue green blue
		for (int x = 0; x < WINDOW_LENGTH; x++) {
			window1.setPixelColor(x, 0, 0, i);
			window2.setPixelColor(x, 0, i, 0);
			window3.setPixelColor(x, 0, 0, i);
		}
	} else {
		// green blue green
		for (int x = 0; x < WINDOW_LENGTH; x++) {
			window1.setPixelColor(x, 0, i, 0);
			window2.setPixelColor(x, 0, 0, i);
			window3.setPixelColor(x, 0, i, 0);
		}
	}

	showAllWindowStrips();

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
