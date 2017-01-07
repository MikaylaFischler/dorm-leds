#include "Animation_Static.hpp"

/* ~~~ Generic Static ~~~ */

// define the generic static init
void Animation_Static::init() {
    Animation::init();
    this->updateRate = 60000;
    this->max_exec = -1;
}

/* ~~~ Animation Static: Desk Both Dim Ambient ~~~ */

void Animation_Static_DeskDimAmbient::init() {
    Animation_Static::init();
    this->name = F("Desk[all]: Dim Ambient");
    this->strips = FULL_DESK;
}

void Animation_Static_DeskDimAmbient::step() {
	for (int i = 0; i < DESK1_LENGTH; i++) {
		if (i%3 == 0) {
			desk1.setPixelColor(i, COLOR_DIM_OFF_WHITE);
		} else {
			desk1.setPixelColor(i, COLOR_OFF);
		}
	}

	for (int i = 0; i < DESK2_LENGTH; i++){
		if (i%3 == 0) {
			desk2.setPixelColor(i, COLOR_DIM_OFF_WHITE);
		} else {
			desk2.setPixelColor(i, COLOR_OFF);
		}
	}

	desk1.show();
	desk2.show();
}
