#include "Animation_Advanced.hpp"

/* ~~~ Animation Advanced Audio: Basic Equalizer ~~~ */

void Animation_Advanced_Audio_EQ_Window::init() {
 	Animation_Advanced_Audio::init();
 	this->name = F("Window Basic Audio Equalizer");
 	this->strips.push_back(ID_WINDOW_1);
 	this->strips.push_back(ID_WINDOW_2);
 	this->strips.push_back(ID_WINDOW_3);

	// clear these once, for efficency
	for (uint8_t i = 0; i < 9; i++) {
		npsm[ID_WINDOW_1]->setPixelColor(i, COLOR_OFF);
		npsm[ID_WINDOW_2]->setPixelColor(i, COLOR_OFF);
		npsm[ID_WINDOW_3]->setPixelColor(i, COLOR_OFF);
	}
}

void Animation_Advanced_Audio_EQ_Window::step() {
	// map is (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min
	val[0] = avg16((left_eq->get8Bit(0) * -30 / 255 + 80), (right_eq->get8Bit(0) * -30 / 255 + 80));
	val[1] = avg16((left_eq->get8Bit(1) * 31 / 255 + 9), (right_eq->get8Bit(1) * 31 / 255 + 9));
	val[2] = avg16((left_eq->get8Bit(2) * -30 / 255 + 80), (right_eq->get8Bit(2) * -30 / 255 + 80));
	val[3] = avg16((left_eq->get8Bit(3) * 31 / 255 + 9), (right_eq->get8Bit(3) * 31 / 255 + 9));
	val[4] = avg16((left_eq->get8Bit(4) * -30 / 255 + 80), (right_eq->get8Bit(4) * -30 / 255 + 80));
	val[5] = avg16((left_eq->get8Bit(5) * 31 / 255 + 9), (right_eq->get8Bit(5) * 31 / 255 + 9));

	// low eqs
	for (uint16_t x = 9; x < WINDOW_LENGTH; x++) {
		if (x <= val[1] && x >= 9) {
			npsm[ID_WINDOW_1]->setPixelColor(x, COLOR_ORANGE);
		} else if (x >= val[0] && x <= 80) {
			npsm[ID_WINDOW_1]->setPixelColor(x, COLOR_RED);
		} else {
			npsm[ID_WINDOW_1]->setPixelColor(x, COLOR_OFF);
		}
	}

	// mid eqs
	for (uint16_t x = 9; x < WINDOW_LENGTH; x++) {
		if (x <= val[3] && x >= 9) {
			npsm[ID_WINDOW_2]->setPixelColor(x, COLOR_GREEN);
		} else if (x >= val[2] && x <= 80) {
			npsm[ID_WINDOW_2]->setPixelColor(x, COLOR_YELLOW);
		} else {
			npsm[ID_WINDOW_2]->setPixelColor(x, COLOR_OFF);
		}
	}

	// high eqs
	for (uint16_t x = 9; x < WINDOW_LENGTH; x++) {
		if (x <= val[5] && x >= 9) {
			npsm[ID_WINDOW_3]->setPixelColor(x, COLOR_PURPLE);
		} else if (x >= val[4] && x <= 80) {
			npsm[ID_WINDOW_3]->setPixelColor(x, COLOR_BLUE);
		} else {
			npsm[ID_WINDOW_3]->setPixelColor(x, COLOR_OFF);
		}
	}

	npsm[ID_WINDOW_1]->show();
	npsm[ID_WINDOW_2]->show();
	npsm[ID_WINDOW_3]->show();

	this->current_exec++;
}

/* ~~~ Animation Advanced Audio: Circular Equalizer and Base Pulse Window ~~~ */

void Animation_Advanced_Audio_EQ_BasePulseCircularEQWindow::init() {
 	Animation_Advanced_Audio::init();
 	this->name = F("Window Audio Bass Pulse and Circular Equalizer");
 	this->strips.push_back(ID_WINDOW_1);
 	this->strips.push_back(ID_WINDOW_2);
 	this->strips.push_back(ID_WINDOW_3);
}

void Animation_Advanced_Audio_EQ_BasePulseCircularEQWindow::step() {
	low_sum = avg8(quadraticBrightness(left_eq->get8Bit(1)), quadraticBrightness(right_eq->get8Bit(1)));
	no_0 = no_1 = no_2 = no_3 = no_4 = no_5 = no_6 = true;

	// side windows (lows) (bottom 3)
	for (uint16_t x = 0; x < WINDOW_LENGTH; x++) {
		if (no_0 && x == left_eq->getInRange(0, 0, WINDOW_LENGTH)) {
			val = ColorWheel(left_eq->get8Bit(0));
			npsm[ID_WINDOW_1]->setPixelColor(x, val);
			npsm[ID_WINDOW_3]->setPixelColor(x, val);
			no_0 = false;
		} else if (no_1 && x == left_eq->getInRange(1, 0, WINDOW_LENGTH)) {
			val = ColorWheel(left_eq->get8Bit(1));
			npsm[ID_WINDOW_1]->setPixelColor(x, val);
			npsm[ID_WINDOW_3]->setPixelColor(x, val);
			no_1 = false;
		} else if (no_2 && x == left_eq->getInRange(2, 0, WINDOW_LENGTH)) {
			val = ColorWheel(left_eq->get8Bit(2));
			npsm[ID_WINDOW_1]->setPixelColor(x, val);
			npsm[ID_WINDOW_3]->setPixelColor(x, val);
			no_2 = false;
		} else if (no_3 && x == left_eq->getInRange(3, 0, WINDOW_LENGTH)) {
			val = ColorWheel(left_eq->get8Bit(3));
			npsm[ID_WINDOW_1]->setPixelColor(x, val);
			npsm[ID_WINDOW_3]->setPixelColor(x, val);
			no_3 = false;
		} else if (no_4 && x == left_eq->getInRange(4, 0, WINDOW_LENGTH)) {
			val = ColorWheel(left_eq->get8Bit(4));
			npsm[ID_WINDOW_1]->setPixelColor(x, val);
			npsm[ID_WINDOW_3]->setPixelColor(x, val);
			no_4 = false;
		} else if (no_5 && x == left_eq->getInRange(5, 0, WINDOW_LENGTH)) {
			val = ColorWheel(left_eq->get8Bit(5));
			npsm[ID_WINDOW_1]->setPixelColor(x, val);
			npsm[ID_WINDOW_3]->setPixelColor(x, val);
			no_5 = false;
		} else if (no_6 && x == left_eq->getInRange(6, 0, WINDOW_LENGTH)) {
			val = ColorWheel(left_eq->get8Bit(6));
			npsm[ID_WINDOW_1]->setPixelColor(x, val);
			npsm[ID_WINDOW_3]->setPixelColor(x, val);
			no_6 = false;
		} else {
			npsm[ID_WINDOW_1]->setPixelColor(x, COLOR_OFF);
			npsm[ID_WINDOW_3]->setPixelColor(x, COLOR_OFF);
		}
	}

	// center window (bass)
	for (uint16_t x = 0; x < WINDOW_LENGTH; x++) {
		npsm[ID_WINDOW_2]->setPixelColor(x, low_sum, low_sum, low_sum);
	}

	npsm[ID_WINDOW_1]->show();
	npsm[ID_WINDOW_2]->show();
	npsm[ID_WINDOW_3]->show();

	this->current_exec++;
}


/* ~~~ Animation Advanced Audio: Advanced Equalizer w/ Max ~~~ */

void Animation_Advanced_Audio_EQ_MaxWindow::init() {
 	Animation_Advanced_Audio::init();
 	this->name = F("Window Audio Equalizer With Max");
 	this->strips.push_back(ID_WINDOW_1);
 	this->strips.push_back(ID_WINDOW_2);
 	this->strips.push_back(ID_WINDOW_3);

	// initialize max vals
	max[0] = 80;
	max[1] = 9;
	max[2] = 80;
	max[3] = 9;
	max[4] = 80;
	max[5] = 9;

	count = 0;

	// clear these once, for efficency
	for (uint8_t i = 0; i < 9; i++) {
		npsm[ID_WINDOW_1]->setPixelColor(i, COLOR_OFF);
		npsm[ID_WINDOW_2]->setPixelColor(i, COLOR_OFF);
		npsm[ID_WINDOW_3]->setPixelColor(i, COLOR_OFF);
	}
}

void Animation_Advanced_Audio_EQ_MaxWindow::step() {
	// map is (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min
	val[0] = avg16((left_eq->get8Bit(0) * -30 / 255 + 80), (right_eq->get8Bit(0) * -30 / 255 + 80));
	val[1] = avg16((left_eq->get8Bit(1) * 31 / 255 + 9), (right_eq->get8Bit(1) * 31 / 255 + 9));
	val[2] = avg16((left_eq->get8Bit(2) * -30 / 255 + 80), (right_eq->get8Bit(2) * -30 / 255 + 80));
	val[3] = avg16((left_eq->get8Bit(3) * 31 / 255 + 9), (right_eq->get8Bit(3) * 31 / 255 + 9));
	val[4] = avg16((left_eq->get8Bit(4) * -30 / 255 + 80), (right_eq->get8Bit(4) * -30 / 255 + 80));
	val[5] = avg16((left_eq->get8Bit(5) * 31 / 255 + 9), (right_eq->get8Bit(5) * 31 / 255 + 9));

	// update max vals
	for (uint8_t i = 0; i < 6; i++) {
		if ((mod8(i, 2) == 0) && i != 6) {
			if (max[i] >= val[i]) { max[i] = val[i]; }
		} else {
			if (max[i] <= val[i]) { max[i] = val[i]; }
		}
	}

	// low eqs
	for (uint16_t x = 9; x < WINDOW_LENGTH; x++) {
		if (x <= val[1] && x >= 9) {
			npsm[ID_WINDOW_1]->setPixelColor(x, COLOR_ORANGE);
		} else if (x >= val[0] && x <= 80) {
			npsm[ID_WINDOW_1]->setPixelColor(x, COLOR_RED);
		} else {
			npsm[ID_WINDOW_1]->setPixelColor(x, COLOR_OFF);
		}

		if (x == max[0] || x == max[1]) { npsm[ID_WINDOW_1]->setPixelColor(x, COLOR_WHITE); }
	}

	// mid eqs
	for (uint16_t x = 9; x < WINDOW_LENGTH; x++) {
		if (x <= val[3] && x >= 9) {
			npsm[ID_WINDOW_2]->setPixelColor(x, COLOR_GREEN);
		} else if (x >= val[2] && x <= 80) {
			npsm[ID_WINDOW_2]->setPixelColor(x, COLOR_YELLOW);
		} else {
			npsm[ID_WINDOW_2]->setPixelColor(x, COLOR_OFF);
		}

		if (x == max[2] || x == max[3]) { npsm[ID_WINDOW_2]->setPixelColor(x, COLOR_WHITE); }
	}

	// high eqs
	for (uint16_t x = 9; x < WINDOW_LENGTH; x++) {
		if (x <= val[5] && x >= 9) {
			npsm[ID_WINDOW_3]->setPixelColor(x, COLOR_PURPLE);
		} else if (x >= val[4] && x <= 80) {
			npsm[ID_WINDOW_3]->setPixelColor(x, COLOR_BLUE);
		} else {
			npsm[ID_WINDOW_3]->setPixelColor(x, COLOR_OFF);
		}

		if (x == max[4] || x == max[5]) { npsm[ID_WINDOW_3]->setPixelColor(x, COLOR_WHITE); }
	}

	// update strips
	npsm[ID_WINDOW_1]->show();
	npsm[ID_WINDOW_2]->show();
	npsm[ID_WINDOW_3]->show();

	// slowly drift max vals back down if possible
	if (count >= 12) {
		count = 0;

		for (uint8_t i = 0; i < 6; i++) {
			if ((mod8(i, 2) == 0) && i != 6) {
				if (max[i] < val[i]) { max[i]++; }
				if (max[i] <= 50) {
					max[i] = 51; // it shouldn't be there
				} else if (max[i] > 80) {
					max[i] = 80;
				}
			} else {
				if (max[i] > val[i]) { max[i]--; }
				if (max[i] >= 41) {
					max[i] = 40; // it shouldn't be there
				} else if (max[i] < 9) {
					max[i] = 9;
				}
			}
		}
	} else {
		count++;
	}

	this->current_exec++;
}

/* ~~~ Animation Advanced Audio: Advanced Equalizer w/ Max ~~~ */

void Animation_Advanced_Audio_EQ_MaxBassCeiling::init() {
 	Animation_Advanced_Audio::init();
 	this->name = F("Ceiling Bass Eq. with Max");
 	this->strips.push_back(ID_CEILING_LEFT);
 	this->strips.push_back(ID_CEILING_RIGHT);

	// initialize max vals
	max[0] = 0;
	max[1] = 0;

	count = 0;

	for (uint16_t i = 0; i < CEILING_LEFT_LENGTH; i++) {
		npsm[ID_CEILING_LEFT]->setPixelColor(i, COLOR_OFF);
	}

	for (uint16_t i = 0; i < CEILING_RIGHT_LENGTH; i++) {
		npsm[ID_CEILING_RIGHT]->setPixelColor(i, COLOR_OFF);
	}
}

void Animation_Advanced_Audio_EQ_MaxBassCeiling::step() {
	// get EQ values
	val[0] = left_eq->getInRange(1, 0, CEILING_RIGHT_LENGTH);
	val[1] = right_eq->getInRange(1, 0, CEILING_RIGHT_LENGTH);

	// update max vals
	for (uint8_t i = 0; i < 2; i++) { if (max[i] <= val[i]) { max[i] = val[i]; } }

	// low eqs
	for (uint16_t x = 0; x < CEILING_LEFT_LENGTH; x++) {
		if (x <= val[0]) {
			npsm[ID_CEILING_LEFT]->setPixelColor(x, COLOR_ORANGE);
		} else {
			npsm[ID_CEILING_LEFT]->setPixelColor(x, COLOR_OFF);
		}

		if (x == max[0]) {
			npsm[ID_CEILING_LEFT]->setPixelColor(x, COLOR_WHITE);
		}
	}

	for (uint16_t x = 0; x < CEILING_RIGHT_LENGTH; x++) {
		if (x <= val[1]) {
			npsm[ID_CEILING_RIGHT]->setPixelColor(x, COLOR_ORANGE);
		} else {
			npsm[ID_CEILING_RIGHT]->setPixelColor(x, COLOR_OFF);
		}

		if (x == max[1]) {
			npsm[ID_CEILING_RIGHT]->setPixelColor(x, COLOR_WHITE);
		}
	}

	// update strips
	npsm[ID_CEILING_LEFT]->show();
	npsm[ID_CEILING_RIGHT]->show();

	// slowly drift max vals back down if possible
	if (count >= 8) {
		count = 0;

		for (uint8_t i = 0; i < 2; i++) { if (max[i] > val[i] && max[i] > 0) { max[i]--; } }

		if (max[0] >= CEILING_LEFT_LENGTH) {
			max[0] = CEILING_LEFT_LENGTH - 1; // it shouldn't be past here
		}

		if (max[1] >= CEILING_RIGHT_LENGTH) {
			max[1] = CEILING_RIGHT_LENGTH - 1; // it shouldn't be past here
		}
	} else {
		count++;
	}

	this->current_exec++;
}
