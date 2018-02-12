#include "Animation_Holiday.hpp"

/* ~~~ Animation Holiday Christmas: Christmas with Snow (Outer Windows, 1 and 3) ~~~ */

void Animation_Holiday_Christmas_Win13Snow::init() {
 	Animation_Holiday::init();
 	this->name = F("Window[1,3]: Christmas with Snow");
    this->update_rate = 50;
 	this->strips.push_back(ID_WINDOW_1);
 	this->strips.push_back(ID_WINDOW_3);

	i = 0;
	left = 0;
	right = 0;
	mode = false;
}

void Animation_Holiday_Christmas_Win13Snow::step() {
	if (mode == false) {
		// randomize
		left = random(3,8);
		right = random(3,8);

		// snow fall
		this->christmas_snow(i, left, right);

		mode = true;
	} else {
		// snow fall
		this->christmas_snow(i, left, right);

		i++;

		// 40 for a loop one direction, 80 for a full forwards and backwards
		if (i == 800) {
			i = 0;
			mode = false;
			this->current_exec++;
		}
	}
}

void Animation_Holiday_Christmas_Win13Snow::christmas_snow(int i, int left_spacing, int right_spacing) {
	unsigned long int on  = Color(150,150,150);
	unsigned long int red = Color(150,0,0);
	unsigned long int green = Color(0,150,0);

	int a = 40 - abs(40 - i % 80);

	// handle top and bottom for christmas
	// left top
	for (int16_t x = LEFT_TOP - 4; x < LEFT_TOP; x++) {
		int rel_index = x - LEFT_TOP + 4;

		if (rel_index < a % LEFT_FULL_LENGTH) {
			npsm[ID_WINDOW_1]->setPixelColor(x, red);
			npsm[ID_WINDOW_3]->setPixelColor(x, green);
		} else {
			npsm[ID_WINDOW_1]->setPixelColor(x, COLOR_OFF);
			npsm[ID_WINDOW_3]->setPixelColor(x, COLOR_OFF);
		}
	}

	// right top
	for (int16_t x = RIGHT_TOP + 1; x <= RIGHT_TOP + 5; x++) {
		int rel_index = x - 6;

		if (rel_index < a % RIGHT_FULL_LENGTH) {
			npsm[ID_WINDOW_1]->setPixelColor(x, green);
			npsm[ID_WINDOW_3]->setPixelColor(x, red);
		} else {
			npsm[ID_WINDOW_1]->setPixelColor(x, COLOR_OFF);
			npsm[ID_WINDOW_3]->setPixelColor(x, COLOR_OFF);
		}
	}

	// left bottom
	for (int16_t x = 4; x >= 0; x--) {
		int rel_index = x + 35;

		if (rel_index < a % RIGHT_FULL_LENGTH) {
			npsm[ID_WINDOW_1]->setPixelColor(x, red);
			npsm[ID_WINDOW_3]->setPixelColor(x, green);
		} else {
			npsm[ID_WINDOW_1]->setPixelColor(x, COLOR_OFF);
			npsm[ID_WINDOW_3]->setPixelColor(x, COLOR_OFF);
		}
	}

	// right bottom
	for (int16_t x = 5; x < RIGHT_BOTTOM; x++) {
		int rel_index = x - 5;

		if (rel_index < a % RIGHT_FULL_LENGTH) {
			npsm[ID_WINDOW_1]->setPixelColor(x, green);
			npsm[ID_WINDOW_3]->setPixelColor(x, red);
		} else {
			npsm[ID_WINDOW_1]->setPixelColor(x, COLOR_OFF);
			npsm[ID_WINDOW_3]->setPixelColor(x, COLOR_OFF);
		}
	}

	// set each right pixel
	for (int16_t x = RIGHT_BOTTOM; x <= RIGHT_TOP; x++) {
		int rel_index = x - RIGHT_BOTTOM;

		if (rel_index % right_spacing == (800 - i) % right_spacing) {
			npsm[ID_WINDOW_1]->setPixelColor(x, on);
			npsm[ID_WINDOW_3]->setPixelColor(x, on);
		} else {
			if (x - 4 < a % RIGHT_FULL_LENGTH) {
				npsm[ID_WINDOW_1]->setPixelColor(x, green);
				npsm[ID_WINDOW_3]->setPixelColor(x, red);
			} else {
				npsm[ID_WINDOW_1]->setPixelColor(x, COLOR_OFF);
				npsm[ID_WINDOW_3]->setPixelColor(x, COLOR_OFF);
			}
		}
	}

	// set each left pixel
	for (int16_t x = LEFT_TOP; x <= LEFT_BOTTOM; x++){
		int rel_index = x - LEFT_TOP;

		if (rel_index % left_spacing == i % left_spacing) {
			npsm[ID_WINDOW_1]->setPixelColor(x, on);
			npsm[ID_WINDOW_3]->setPixelColor(x, on);
		} else {
			if (rel_index + 4 < a % LEFT_FULL_LENGTH) {
				npsm[ID_WINDOW_1]->setPixelColor(x, red);
				npsm[ID_WINDOW_3]->setPixelColor(x, green);
			} else {
				npsm[ID_WINDOW_1]->setPixelColor(x, COLOR_OFF);
				npsm[ID_WINDOW_3]->setPixelColor(x, COLOR_OFF);
			}
		}
	}

	npsm[ID_WINDOW_1]->show();
	npsm[ID_WINDOW_3]->show();
}
