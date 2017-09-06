#include "Animation_Advanced.hpp"

/* ~~~ Generic Advanced Pulse ~~~ */

// define the generic advanced pulse init
void Animation_Advanced_Pulse::init() {
  	Animation_Advanced::init();
    this->update_rate = 10;

	// get pulse monitor
	this->pulse_mon = device_manager.getDevice<PulseMonitor>(2);
}

/* ~~~ Animation Advanced Pulse: Ceiling Pulse ~~~ */

void Animation_Advanced_Pulse_CeilingPulse::init() {
 	Animation_Advanced_Pulse::init();
 	this->name = F("Ceiling[all]: Pulse");
 	this->strips.push_back(ID_CEILING_LEFT);
 	this->strips.push_back(ID_CEILING_RIGHT);

	for (int i = 0; i < CEILING_LEFT_LENGTH; i++) {
		npsm[ID_CEILING_LEFT]->setPixelColor(i, 0, 0, 0, 0);
	}

	for (int i = 0; i < CEILING_RIGHT_LENGTH; i++) {
		npsm[ID_CEILING_RIGHT]->setPixelColor(i, 0, 0, 0, 0);
	}

	npsm[ID_CEILING_LEFT]->show();
	npsm[ID_CEILING_RIGHT]->show();
}

void Animation_Advanced_Pulse_CeilingPulse::step() {
	int value = this->pulse_mon->read();

	Serial.println(value);

	int mapped_value = map(value, 400, 975, 0, 255);

	if (quarticScaleFilter) {
		mapped_value = round(pow((long double) mapped_value, 4) * 0.00000006); // agressive filter
	} else {
		mapped_value = round(pow((long double) mapped_value, 2) * 0.004); // less agressive filter
	}

	for (int i = 0; i < CEILING_LEFT_LENGTH; i++) {
		npsm[ID_CEILING_LEFT]->setPixelColor(i, mapped_value, 0, 0, 0);
	}

	for (int i = 0; i < CEILING_RIGHT_LENGTH; i++) {
		npsm[ID_CEILING_RIGHT]->setPixelColor(i, mapped_value, 0, 0, 0);
	}

	npsm[ID_CEILING_LEFT]->show();
	npsm[ID_CEILING_RIGHT]->show();

	this->current_exec++;
}

/* ~~~ Animation Advanced Pulse: Ceiling Pulse Chart ~~~ */

void Animation_Advanced_Pulse_CeilingChart::init() {
 	Animation_Advanced_Pulse::init();
 	this->name = F("Ceiling[all]: Pulse Chart");
 	this->strips.push_back(ID_CEILING_LEFT);
 	this->strips.push_back(ID_CEILING_RIGHT);

	for (int i = 0; i < CEILING_LEFT_LENGTH; i++) {
		npsm[ID_CEILING_LEFT]->setPixelColor(i, 0, 0, 0, 0);
	}

	for (int i = 0; i < CEILING_RIGHT_LENGTH; i++) {
		npsm[ID_CEILING_RIGHT]->setPixelColor(i, 0, 0, 0, 0);
	}

	npsm[ID_CEILING_LEFT]->show();
	npsm[ID_CEILING_RIGHT]->show();

	cur_pixel = 0;
}

void Animation_Advanced_Pulse_CeilingChart::step() {
	int value = this->pulse_mon->read();
	int mapped_pixel;

	Serial.println(value);

	int mapped_value = map(value, 400, 975, 0, 255);

	if (quarticScaleFilter) {
		mapped_value = round(pow((long double) mapped_value, 4) * 0.00000006); // agressive filter
	} else {
		mapped_value = round(pow((long double) mapped_value, 2) * 0.004); // less agressive filter
	}

	if (cur_pixel < CEILING_LEFT_LENGTH) {
		mapped_pixel = CEILING_LEFT_LENGTH - cur_pixel - 1;
		npsm[ID_CEILING_LEFT]->setPixelColor(mapped_pixel, mapped_value, 0, 0, 0);
		npsm[ID_CEILING_LEFT]->setPixelColor(mapped_pixel - 1, 0, 0, 0, 255);

		npsm[ID_CEILING_LEFT]->show();
	} else if (cur_pixel == CEILING_LEFT_LENGTH) {
		npsm[ID_CEILING_LEFT]->setPixelColor(0, mapped_value, 0, 0, 0);
		npsm[ID_CEILING_RIGHT]->setPixelColor(0, 0, 0, 0, 255);

		npsm[ID_CEILING_LEFT]->show();
		npsm[ID_CEILING_RIGHT]->show();
	} else if (cur_pixel < CEILING_LEFT_LENGTH + CEILING_RIGHT_LENGTH - 1) {
		mapped_pixel = cur_pixel - CEILING_LEFT_LENGTH - 1;
		npsm[ID_CEILING_RIGHT]->setPixelColor(mapped_pixel, mapped_value, 0, 0, 0);
		npsm[ID_CEILING_RIGHT]->setPixelColor(mapped_pixel + 1, 0, 0, 0, 255);

		npsm[ID_CEILING_RIGHT]->show();
	} else if (cur_pixel == CEILING_LEFT_LENGTH + CEILING_RIGHT_LENGTH - 1) {
		mapped_pixel = cur_pixel - CEILING_LEFT_LENGTH - 1;
		npsm[ID_CEILING_RIGHT]->setPixelColor(mapped_pixel, mapped_value, 0, 0, 0);

		npsm[ID_CEILING_RIGHT]->show();
	}

	if (cur_pixel == CEILING_LEFT_LENGTH + CEILING_RIGHT_LENGTH - 1) {
		cur_pixel = 0;
		this->current_exec++;
	} else {
		cur_pixel++;
	}
}
