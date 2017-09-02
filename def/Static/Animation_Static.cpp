#include "Animation_Static.hpp"

/* ~~~ Generic Static ~~~ */

// define the generic static init
void Animation_Static::init() {
    Animation::init();
    this->update_rate = 60000;
    this->max_exec = -1;
}

/* ~~~ Animation Static: Desk Both Bright White ~~~ */

void Animation_Static_DeskBrightWhite::init() {
    Animation_Static::init();
    this->name = F("Desk[all]: Bright White");
    this->strips.push_back(ID_DESK_1);
    this->strips.push_back(ID_DESK_2);
}

void Animation_Static_DeskBrightWhite::step() {
	for (int i = 0; i < DESK1_LENGTH; i++) {
		npsm[ID_DESK_1]->setPixelColor(i, COLOR_WHITE);
	}

	for (int i = 0; i < DESK2_LENGTH; i++){
		npsm[ID_DESK_2]->setPixelColor(i, COLOR_WHITE);
	}

	npsm[ID_DESK_1]->show();
	npsm[ID_DESK_2]->show();

	this->current_exec++;
}

/* ~~~ Animation Static: Desk Both Dim Ambient ~~~ */

void Animation_Static_DeskDimAmbient::init() {
    Animation_Static::init();
    this->name = F("Desk[all]: Dim Ambient");
    this->strips.push_back(ID_DESK_1);
    this->strips.push_back(ID_DESK_2);
}

void Animation_Static_DeskDimAmbient::step() {
	for (int i = 0; i < DESK1_LENGTH; i++) {
		npsm[ID_DESK_1]->setPixelColor(i, COLOR_DIM_OFF_WHITE);
	}

	for (int i = 0; i < DESK2_LENGTH; i++){
		npsm[ID_DESK_2]->setPixelColor(i, COLOR_DIM_OFF_WHITE);
	}

	npsm[ID_DESK_1]->show();
	npsm[ID_DESK_2]->show();

	this->current_exec++;
}

/* ~~~ Animation Static: Trans Pride Flag using all Windows ~~~ */

void Animation_Static_TransFlagWindows::init() {
    Animation_Static::init();
    this->name = F("Window[all]: Trans Pride Flag");
    this->strips.push_back(ID_WINDOW_1);
    this->strips.push_back(ID_WINDOW_2);
    this->strips.push_back(ID_WINDOW_3);
}

void Animation_Static_TransFlagWindows::step() {
	for (int i = 0; i < WINDOW_LENGTH; i++) {
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
    this->name = F("Window[all]: Striped Trans Pride Flag");
    this->strips.push_back(ID_WINDOW_1);
    this->strips.push_back(ID_WINDOW_2);
    this->strips.push_back(ID_WINDOW_3);
}

void Animation_Static_TransFlagStripedWindows::step() {
	for (int i = 0; i < WINDOW_LENGTH; i++) {
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
