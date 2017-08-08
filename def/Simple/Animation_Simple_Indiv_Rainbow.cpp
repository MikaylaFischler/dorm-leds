#include "Animation_Simple.hpp"

/* ~~~ Animation Simple Individual: Rainbow ~~~ */

void Animation_Simple_Indiv_Rainbow::init() {
	Animation_Simple_Indiv::init();
	this->name += F(": Rainbow");
    this->update_rate = 50;

	i = 0;
}

void Animation_Simple_Indiv_Rainbow::step() {
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

/* ~~~ Animation Simple Individual: Rainbow Cycle ~~~ */

void Animation_Simple_Indiv_RainbowCycle::init() {
	Animation_Simple_Indiv::init();
	this->name += F(": Rainbow Cycle");
    this->update_rate = 50;

	i = 0;
}

void Animation_Simple_Indiv_RainbowCycle::step() {
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

/* ~~~ Animation Simple Individual: Rainbow Color Wipe ~~~ */

void Animation_Simple_Indiv_RainbowWipe::init() {
 	Animation_Simple_Indiv::init();
 	this->name += F(": Rainbow Color Wipe");
    this->update_rate = 50;

	i = 0;
	cur_color = 0;
}

void Animation_Simple_Indiv_RainbowWipe::step() {
	// start wiping the current color
	if (cur_color % 2 != 0) {
		this->strip->setPixelColor(i, COLOR_OFF);
	} else if (cur_color == 0) {
		this->strip->setPixelColor(i, COLOR_RED);
	} else if (cur_color == 2) {
		this->strip->setPixelColor(i, COLOR_ORANGE);
	} else if (cur_color == 4) {
		this->strip->setPixelColor(i, COLOR_YELLOW);
	} else if (cur_color == 6) {
		this->strip->setPixelColor(i, COLOR_GREEN);
	} else if (cur_color == 8) {
		this->strip->setPixelColor(i, COLOR_LIGHT_BLUE_GREEN);
	} else if (cur_color == 10) {
		this->strip->setPixelColor(i, COLOR_BLUE);
	} else if (cur_color == 12) {
		this->strip->setPixelColor(i, COLOR_INDIGO);
	} else if (cur_color == 14) {
		this->strip->setPixelColor(i, COLOR_PURPLE);
	}

    this->strip->show();

    i++;

	if (i == this->strip->numPixels()) {
		cur_color++;
		i = 0;

		if (cur_color == 16) {
			cur_color = 0;
			this->current_exec++;
		}
	}
}

/* ~~~ Animation Simple Individual: Rainbow Theater Chase ~~~ */

void Animation_Simple_Indiv_RainbowTheaterChase::init() {
	Animation_Simple_Indiv::init();
	this->name += F(": Rainbow Theater Chase");
    this->update_rate = 35;

	i = 0;
	j = 0;
	alternate = true;
}

void Animation_Simple_Indiv_RainbowTheaterChase::step() {
	if (alternate) {
		// set each led to the proper color
		for (unsigned int k = 0; k < this->strip->numPixels(); k += 3) {
			// turn every third pixel on
			this->strip->setPixelColor(k + i, ColorWheel((k + j) % 255));
		}

		this->strip->show();
	} else {
		for (unsigned int k = 0; k < this->strip->numPixels(); k += 3) {
			// turn every third pixel off
			this->strip->setPixelColor(k + i, COLOR_OFF);
		}
	}

	alternate = !alternate;

	if (j < 255 && alternate) {
		j++;
	} else if (j == 255 && alternate) {
		j = 0;
	}

	if (i < 2 && alternate) {
		i++;
	} else if (i == 2 && alternate) {
		i = 0;
		this->current_exec++;
	}
}
