#include "Animation_Static.hpp"

/* ~~~ Generic Static ~~~ */

// define the generic static init
void Animation_Static::init() {
    Animation::init();
    this->update_rate = 60000;
    this->max_exec = -1;
}

/* ~~~ Animation Static: Trans Pride Flag using all Windows ~~~ */

void Animation_Static_TransColorWindows::init() {
    Animation_Static::init();
    this->name = F("Window Trans Pride Flag");
    this->strips.push_back(ID_WINDOW_1);
    this->strips.push_back(ID_WINDOW_2);
    this->strips.push_back(ID_WINDOW_3);
}

void Animation_Static_TransColorWindows::step() {
	for (uint16_t i = 0; i < WINDOW_LENGTH; i++) {
		npsm[ID_WINDOW_1]->setPixelColor(i, COLOR_WHITE);
		npsm[ID_WINDOW_2]->setPixelColor(i, COLOR_PINK);
		npsm[ID_WINDOW_3]->setPixelColor(i, COLOR_BABY_BLUE);
	}

	npsm[ID_WINDOW_1]->show();
	npsm[ID_WINDOW_2]->show();
	npsm[ID_WINDOW_3]->show();

	this->current_exec++;
}

/* ~~~ Animation Static: Trans Pride Flag using all Windows (striped, 2 stripes per window) ~~~ */

void Animation_Static_TransFlagStripedWindows::init() {
    Animation_Static::init();
    this->name = F("Window Striped Trans Pride Flag");
    this->strips.push_back(ID_WINDOW_1);
    this->strips.push_back(ID_WINDOW_2);
    this->strips.push_back(ID_WINDOW_3);
}

void Animation_Static_TransFlagStripedWindows::step() {
	for (uint16_t i = 0; i < WINDOW_LENGTH; i++) {
		if (i >= WINDOW_BOTTOM_RIGHT && i <= WINDOW_TOP_RIGHT) {
			npsm[ID_WINDOW_1]->setPixelColor(i, COLOR_PINK);
			npsm[ID_WINDOW_2]->setPixelColor(i, COLOR_WHITE);
			npsm[ID_WINDOW_3]->setPixelColor(i, COLOR_BABY_BLUE);
		} else if (i >= WINDOW_TOP_LEFT && i <= WINDOW_BOTTOM_LEFT) {
			npsm[ID_WINDOW_1]->setPixelColor(i, COLOR_BABY_BLUE);
			npsm[ID_WINDOW_2]->setPixelColor(i, COLOR_WHITE);
			npsm[ID_WINDOW_3]->setPixelColor(i, COLOR_PINK);
		} else {
			npsm[ID_WINDOW_1]->setPixelColor(i, COLOR_BLACK);
			npsm[ID_WINDOW_2]->setPixelColor(i, COLOR_BLACK);
			npsm[ID_WINDOW_3]->setPixelColor(i, COLOR_BLACK);
		}
	}

	npsm[ID_WINDOW_1]->show();
	npsm[ID_WINDOW_2]->show();
	npsm[ID_WINDOW_3]->show();

	this->current_exec++;
}
