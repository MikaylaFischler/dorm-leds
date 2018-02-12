#include "Animation_Static.hpp"

/* ~~~ Generic Individual ~~~ */

// define the generic individual init
void Animation_Static_Indiv::init() {
  	Animation_Static::init();
	this->strips.push_back(this->id);
}

/* ~~~ Animation Static Individual: Single Color ~~~ */

void Animation_Static_Indiv_Color::init() {
	Animation_Static_Indiv::init();
	this->name = F("Single Color");
}

void Animation_Static_Indiv_Color::step() {
	for (uint16_t i = 0; i < npsm[this->id]->numPixels(); i++) {
		npsm[this->id]->setPixelColor(i, this->color);
	}

	npsm[this->id]->show();
	this->current_exec++;
}

/* ~~~ Animation Static Individual: Third Dim Ambient ~~~ */

void Animation_Static_Indiv_ThirdDimAmbient::init() {
	Animation_Static_Indiv::init();
	this->name = F("Third Dim Ambient");
}

void Animation_Static_Indiv_ThirdDimAmbient::step() {
	for (uint16_t i = 0; i < npsm[this->id]->numPixels(); i++) {
		if (i % 3 == 0) {
			npsm[this->id]->setPixelColor(i, COLOR_DIM_OFF_WHITE);
		} else {
			npsm[this->id]->setPixelColor(i, COLOR_OFF);
		}
	}

	npsm[this->id]->show();
	this->current_exec++;
}

/* ~~~ Animation Static Individual: Third Dim Ambient (RGBW's White) ~~~ */

void Animation_Static_Indiv_ThirdDimAmbient_W::init() {
	Animation_Static_Indiv::init();
	this->name = F("Third Dim Ambient (RGBW)");

	if (!npsm.isRGBW(this->id)) { abort(); }
}

void Animation_Static_Indiv_ThirdDimAmbient_W::step() {
	for (uint16_t i = 0; i < npsm[this->id]->numPixels(); i++) {
		if (i % 3 == 0) {
			npsm[this->id]->setPixelColor(i, 0, 0, 0, 200);
		} else {
			npsm[this->id]->setPixelColor(i, 0, 0, 0, 200);
		}
	}

	npsm[this->id]->show();
	this->current_exec++;
}
