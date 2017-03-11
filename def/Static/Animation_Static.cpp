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
	this->num_strips = 2;
    this->strips = FULL_DESK;
}

void Animation_Static_DeskBrightWhite::step() {
	for (int i = 0; i < DESK1_LENGTH; i++) {
		desk1.setPixelColor(i, COLOR_WHITE);
	}

	for (int i = 0; i < DESK2_LENGTH; i++){
		desk2.setPixelColor(i, COLOR_WHITE);
	}

	desk1.show();
	desk2.show();
}

/* ~~~ Animation Static: Desk Both Third Dim Ambient ~~~ */

void Animation_Static_DeskThirdDimAmbient::init() {
    Animation_Static::init();
    this->name = F("Desk[all]: Third LED Dim Ambient");
	this->num_strips = 2;
    this->strips = FULL_DESK;
}

void Animation_Static_DeskThirdDimAmbient::step() {
	for (int i = 0; i < DESK1_LENGTH; i++) {
		if (i % 3 == 0) {
			desk1.setPixelColor(i, COLOR_DIM_OFF_WHITE);
		} else {
			desk1.setPixelColor(i, COLOR_OFF);
		}
	}

	for (int i = 0; i < DESK2_LENGTH; i++){
		if (i % 3 == 0) {
			desk2.setPixelColor(i, COLOR_DIM_OFF_WHITE);
		} else {
			desk2.setPixelColor(i, COLOR_OFF);
		}
	}

	desk1.show();
	desk2.show();
}

/* ~~~ Animation Static: Desk Both Dim Ambient ~~~ */

void Animation_Static_DeskDimAmbient::init() {
    Animation_Static::init();
    this->name = F("Desk[all]: Dim Ambient");
	this->num_strips = 2;
    this->strips = FULL_DESK;
}

void Animation_Static_DeskDimAmbient::step() {
	for (int i = 0; i < DESK1_LENGTH; i++) {
		desk1.setPixelColor(i, COLOR_DIM_OFF_WHITE);
	}

	for (int i = 0; i < DESK2_LENGTH; i++){
		desk2.setPixelColor(i, COLOR_DIM_OFF_WHITE);
	}

	desk1.show();
	desk2.show();
}
