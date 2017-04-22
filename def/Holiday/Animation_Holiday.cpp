#include "Animation_Holiday.hpp"

/* ~~~ Generic Holiday ~~~ */

// define the generic holiday init
void Animation_Holiday::init() {
  	Animation::init();
  	this->max_exec = -1;
}

/* ~~~ Animation Holiday Earth Day: Dual Color Alternating Fade ~~~ */

void Animation_Holiday_EarthDay_WinAllFade::init() {
 	Animation_Holiday::init();
 	this->name = F("Window[All]: Alternating Earth Day Fade");
    this->update_rate = 20;
	this->num_strips = 3;
 	this->strips = WINDOW_ALL;

	this->stack = new LocalStack();
	this->stack->push(new MemObj(new unsigned short int(0)));
	this->stack->push(new MemObj(new bool(true)));
	this->stack->push(new MemObj(new bool(true)));
}

void Animation_Holiday_EarthDay_WinAllFade::step() {
	unsigned short int& i = this->stack->get(0)->get<unsigned short int>();
	bool& mode = this->stack->get(1)->get<bool>();
	bool& increasing = this->stack->get(2)->get<bool>();

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

void Animation_Holiday_EarthDay_WinAllFade::clean() {
	this->stack->get(0)->destroy<unsigned short int>();
	this->stack->get(1)->destroy<bool>();
	this->stack->get(2)->destroy<bool>();

	delete this->stack;
}
