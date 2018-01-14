#include "Animation_Simple.hpp"

/* ~~~ Animation Simple Individual: Rainbow ~~~ */

void Animation_Simple_Indiv_Rainbow::init() {
	Animation_Simple_Indiv::init();
	this->name = F("Rainbow");
    this->update_rate = 50;

	i = 0;
}

void Animation_Simple_Indiv_Rainbow::step() {
	// set each led to the proper color
	for (uint16_t j = 0; j < npsm[this->id]->numPixels(); j++) {
		npsm[this->id]->setPixelColor(j, ColorWheel((i + j) & 255));
	}

	npsm[this->id]->show();

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
	this->name = F("Rainbow Cycle");
    this->update_rate = 50;

	i = 0;
}

void Animation_Simple_Indiv_RainbowCycle::step() {
	// set each led to the proper color
	for (uint16_t j = 0; j < npsm[this->id]->numPixels(); j++) {
		npsm[this->id]->setPixelColor(j, ColorWheel(((j * 256 / npsm[this->id]->numPixels()) + i) & 255));
	}

	npsm[this->id]->show();

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
 	this->name = F("Rainbow Color Wipe");
    this->update_rate = 50;

	i = 0;
	cur_color = 0;
}

void Animation_Simple_Indiv_RainbowWipe::step() {
	// start wiping the current color
	if (cur_color % 2 != 0) {
		npsm[this->id]->setPixelColor(i, COLOR_OFF);
	} else if (cur_color == 0) {
		npsm[this->id]->setPixelColor(i, COLOR_RED);
	} else if (cur_color == 2) {
		npsm[this->id]->setPixelColor(i, COLOR_ORANGE);
	} else if (cur_color == 4) {
		npsm[this->id]->setPixelColor(i, COLOR_YELLOW);
	} else if (cur_color == 6) {
		npsm[this->id]->setPixelColor(i, COLOR_GREEN);
	} else if (cur_color == 8) {
		npsm[this->id]->setPixelColor(i, COLOR_LIGHT_BLUE_GREEN);
	} else if (cur_color == 10) {
		npsm[this->id]->setPixelColor(i, COLOR_BLUE);
	} else if (cur_color == 12) {
		npsm[this->id]->setPixelColor(i, COLOR_INDIGO);
	} else if (cur_color == 14) {
		npsm[this->id]->setPixelColor(i, COLOR_PURPLE);
	}

    npsm[this->id]->show();

    i++;

	if (i == npsm[this->id]->numPixels()) {
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
	this->name = F("Rainbow Theater Chase");
    this->update_rate = 35;

	i = 0;
	j = 0;
	alternate = true;
}

void Animation_Simple_Indiv_RainbowTheaterChase::step() {
	if (alternate) {
		// set each led to the proper color
		for (unsigned int k = 0; k < npsm[this->id]->numPixels(); k += 3) {
			// turn every third pixel on
			npsm[this->id]->setPixelColor(k + i, ColorWheel((k + j) % 255));
		}

		npsm[this->id]->show();
	} else {
		for (unsigned int k = 0; k < npsm[this->id]->numPixels(); k += 3) {
			// turn every third pixel off
			npsm[this->id]->setPixelColor(k + i, COLOR_OFF);
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

/* ~~~ Animation Simple Individual: Rainbow with White Theater Chase ~~~ */

void Animation_Simple_Indiv_RainbowWhiteTheaterChase::init() {
	Animation_Simple_Indiv::init();
	this->name = F("Rainbow White Theater Chase");
    this->update_rate = 35;

	i = 0;
	j = 0;
	alternate = true;
}

void Animation_Simple_Indiv_RainbowWhiteTheaterChase::step() {
	if (alternate) {
		// set each led to the proper color
		for (unsigned int k = 0; k < npsm[this->id]->numPixels(); k += 3) {
			// turn every third pixel on
			npsm[this->id]->setPixelColor(k + i, ColorWheel((k + j) % 255));
		}

		npsm[this->id]->show();
	} else {
		for (unsigned int k = 0; k < npsm[this->id]->numPixels(); k += 3) {
			// turn every third pixel off (or white if RGBW)
			if (npsm.isRGBW(this->id)) {
				npsm[this->id]->setPixelColor(k + i, 0, 0, 0, 20);
			} else {
				npsm[this->id]->setPixelColor(k + i, COLOR_OFF);
			}
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
