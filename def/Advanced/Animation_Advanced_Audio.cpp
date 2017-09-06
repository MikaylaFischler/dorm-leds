#include "Animation_Advanced.hpp"

/* ~~~ Generic Advanced Audio ~~~ */

// define the generic advanced audio init
void Animation_Advanced_Audio::init() {
  	Animation_Advanced::init();
    this->update_rate = 1; // at rate of audio update

	// get equalizer chips
	this->left_eq = device_manager.getDevice<MSGEQ7>(0);
	this->right_eq = device_manager.getDevice<MSGEQ7>(1);
}

/* ~~~ Animation Advanced Audio: Bass Pulse w/ Left and Right ~~~ */

void Animation_Advanced_Audio_BassPulseLR::init() {
 	Animation_Advanced_Audio::init();
	// TODO make it not say ceiling inherently
 	this->name = F("Ceiling[all]: Audio Bass Beat Pulse L/R");
 	this->strips.push_back(strip1);
 	this->strips.push_back(strip2);
}

void Animation_Advanced_Audio_BassPulseLR::step() {
	low_L = quadraticBrightness(left_eq->get8Bit(1));
	low_R = quadraticBrightness(right_eq->get8Bit(1));

	for (int x = 0; x < npsm[strip1]->numPixels(); x++) {
		npsm[strip1]->setPixelColor(x, low_L, 0, 0);
	}

	for (int x = 0; x < npsm[strip2]->numPixels(); x++) {
		npsm[strip2]->setPixelColor(x, low_R, 0, 0);
	}

	npsm[strip1]->show();
	npsm[strip2]->show();

	this->current_exec++;
}

/* ~~~ Animation Advanced Audio: Bass Pulse w/ Left and Right ~~~ */

void Animation_Advanced_Audio_BassPulseNestedLR::init() {
 	Animation_Advanced_Audio::init();
	// TODO make it not say ceiling inherently
 	this->name = F("Ceiling[all]: Audio Bass Beat Pulse Nested L/R");
 	this->strips.push_back(strip1);
 	this->strips.push_back(strip2);
}

void Animation_Advanced_Audio_BassPulseNestedLR::step() {
	low_L = quadraticBrightness(left_eq->get8Bit(1));
	low_R = quadraticBrightness(right_eq->get8Bit(1));
	low2_L = quadraticBrightness(left_eq->get8Bit(2));
	low2_R = quadraticBrightness(right_eq->get8Bit(2));

	for (int x = 0; x < npsm[strip1]->numPixels(); x++) {
		mid = ((npsm[strip1]->numPixels()) / 2);
		if (x > mid - (mid / 3) && x < mid + (mid / 3)) {
			npsm[strip1]->setPixelColor(x, low2_L, (int) round(low2_L * 50.0/255.0), 0);
		} else {
			npsm[strip1]->setPixelColor(x, low_L, 0, 0);
		}
	}

	for (int x = 0; x < npsm[strip2]->numPixels(); x++) {
		mid = ((npsm[strip2]->numPixels()) / 2);
		if (x > mid - (mid / 3) && x < mid + (mid / 3)) {
			npsm[strip2]->setPixelColor(x, low2_R, (int) round(low2_R * 50.0/255.0), 0);
		} else {
			npsm[strip2]->setPixelColor(x, low_R, 0, 0);
		}
	}

	npsm[strip1]->show();
	npsm[strip2]->show();

	this->current_exec++;
}

/* ~~~ Animation Advanced Audio: Pulse w/ Left and Right ~~~ */

void Animation_Advanced_Audio_PulseNestedLR::init() {
 	Animation_Advanced_Audio::init();
	// TODO make it not say ceiling inherently
 	this->name = F("Ceiling[all]: Audio Pulse Nested L/R");
 	this->strips.push_back(strip1);
 	this->strips.push_back(strip2);
}

void Animation_Advanced_Audio_PulseNestedLR::step() {
	l0 = quadraticBrightness(left_eq->get8Bit(0));
	r0 = quadraticBrightness(right_eq->get8Bit(0));
	l1 = quadraticBrightness(left_eq->get8Bit(1));
	r1 = quadraticBrightness(right_eq->get8Bit(1));
	l2 = quadraticBrightness(left_eq->get8Bit(2));
	r2 = quadraticBrightness(right_eq->get8Bit(2));
	l3 = quadraticBrightness(left_eq->get8Bit(3));
	r3 = quadraticBrightness(right_eq->get8Bit(3));
	l4 = quadraticBrightness(left_eq->get8Bit(4));
	r4 = quadraticBrightness(right_eq->get8Bit(4));
	l5 = quadraticBrightness(left_eq->get8Bit(5));
	r5 = quadraticBrightness(right_eq->get8Bit(5));
	l6 = quadraticBrightness(left_eq->get8Bit(6));
	r6 = quadraticBrightness(right_eq->get8Bit(6));

	if (mode == true) {
		// split as a whole
		len = npsm[strip1]->numPixels();

		for (int x = 0; x < npsm[strip1]->numPixels(); x++) {
			if (x > len - (len / 7)) {
				npsm[strip1]->setPixelColor(x, (int) round(l6 * 175.0/255.0), 0, l6);
			} else if (x > len - (2 * len / 7)) {
				npsm[strip1]->setPixelColor(x, (int) round(l5 * 100.0/255.0), 0, l5);
			} else if (x > len - (3 * len / 7)) {
				npsm[strip1]->setPixelColor(x, 0, 0, l4);
			} else if (x > len - (4 * len / 7)) {
				npsm[strip1]->setPixelColor(x, 0, l3, 0);
			} else if (x > len - (5 * len / 7)) {
				npsm[strip1]->setPixelColor(x, l2, (int) round(l2 * 150.0/255.0), 0);
			} else if (x > len - (6 * len / 7)) {
				npsm[strip1]->setPixelColor(x, l1, (int) round(l1 * 50.0/255.0), 0);
			} else {
				npsm[strip1]->setPixelColor(x, l0, 0, 0);
			}
		}

		len = npsm[strip2]->numPixels();

		for (int x = 0; x < npsm[strip2]->numPixels(); x++) {
			if (x > len - (len / 7)) {
				npsm[strip2]->setPixelColor(x, (int) round(r6 * 175.0/255.0), 0, r6);
			} else if (x > len - (2 * len / 7)) {
				npsm[strip2]->setPixelColor(x, (int) round(r5 * 100.0/255.0), 0, r5);
			} else if (x > len - (3 * len / 7)) {
				npsm[strip2]->setPixelColor(x, 0, 0, r4);
			} else if (x > len - (4 * len / 7)) {
				npsm[strip2]->setPixelColor(x, 0, r3, 0);
			} else if (x > len - (5 * len / 7)) {
				npsm[strip2]->setPixelColor(x, r2, (int) round(r2 * 150.0/255.0), 0);
			} else if (x > len - (6 * len / 7)) {
				npsm[strip2]->setPixelColor(x, r1, (int) round(r1 * 50.0/255.0), 0);
			} else {
				npsm[strip2]->setPixelColor(x, r0, 0, 0);
			}
		}
	} else {
		// individually split up
		len = npsm[strip1]->numPixels();
		mid = len / 2;

		for (int x = 0; x < npsm[strip1]->numPixels(); x++) {
			if (x > mid - (mid / 7) && x < mid + (mid / 7)) {
				npsm[strip1]->setPixelColor(x, (int) round(l6 * 175.0/255.0), 0, l6);
			} else if (x > mid - (2 * mid / 7) && x < mid + (2 * mid / 7)) {
				npsm[strip1]->setPixelColor(x, (int) round(l5 * 100.0/255.0), 0, l5);
			} else if (x > mid - (3 * mid / 7) && x < mid + (3 * mid / 7)) {
				npsm[strip1]->setPixelColor(x, 0, 0, l4);
			} else if (x > mid - (4 * mid / 7) && x < mid + (4 * mid / 7)) {
				npsm[strip1]->setPixelColor(x, 0, l3, 0);
			} else if (x > mid - (5 * mid / 7) && x < mid + (5 * mid / 7)) {
				npsm[strip1]->setPixelColor(x, l2, (int) round(l2 * 150.0/255.0), 0);
			} else if (x > mid - (6 * mid / 7) && x < mid + (6 * mid / 7)) {
				npsm[strip1]->setPixelColor(x, l1, (int) round(l1 * 50.0/255.0), 0);
			} else {
				npsm[strip1]->setPixelColor(x, l0, 0, 0);
			}
		}

		len = npsm[strip2]->numPixels();
		mid = len / 2;

		for (int x = 0; x < npsm[strip2]->numPixels(); x++) {
			if (x > mid - (mid / 7) && x < mid + (mid / 7)) {
				npsm[strip2]->setPixelColor(x, (int) round(r6 * 175.0/255.0), 0, r6);
			} else if (x > mid - (2 * mid / 7) && x < mid + (2 * mid / 7)) {
				npsm[strip2]->setPixelColor(x, (int) round(r5 * 100.0/255.0), 0, r5);
			} else if (x > mid - (3 * mid / 7) && x < mid + (3 * mid / 7)) {
				npsm[strip2]->setPixelColor(x, 0, 0, r4);
			} else if (x > mid - (4 * mid / 7) && x < mid + (4 * mid / 7)) {
				npsm[strip2]->setPixelColor(x, 0, r3, 0);
			} else if (x > mid - (5 * mid / 7) && x < mid + (5 * mid / 7)) {
				npsm[strip2]->setPixelColor(x, r2, (int) round(r2 * 150.0/255.0), 0);
			} else if (x > mid - (6 * mid / 7) && x < mid + (6 * mid / 7)) {
				npsm[strip2]->setPixelColor(x, r1, (int) round(r1 * 50.0/255.0), 0);
			} else {
				npsm[strip2]->setPixelColor(x, r0, 0, 0);
			}
		}
	}

	npsm[strip1]->show();
	npsm[strip2]->show();

	this->current_exec++;
}

/* ~~~ Animation Advanced Audio: Bass Window Pulse ~~~ */

void Animation_Advanced_Audio_BassPulseWindow::init() {
 	Animation_Advanced_Audio::init();
 	this->name = F("Window[all]: Audio Bass Beat Pulse");
 	this->strips.push_back(ID_WINDOW_1);
 	this->strips.push_back(ID_WINDOW_2);
 	this->strips.push_back(ID_WINDOW_3);
}

void Animation_Advanced_Audio_BassPulseWindow::step() {
	low_sum = (int) round(((float) quadraticBrightness(left_eq->get8Bit(1)) + (float) quadraticBrightness(right_eq->get8Bit(1))) / 2.0);
	low2_sum = (int) round(((float) quadraticBrightness(left_eq->get8Bit(2)) + (float) quadraticBrightness(right_eq->get8Bit(2))) / 2.0);

	for (int x = 0; x < WINDOW_LENGTH; x++) {
		npsm[ID_WINDOW_1]->setPixelColor(x, low_sum, 0, 0);
		npsm[ID_WINDOW_2]->setPixelColor(x, 0, low2_sum, low2_sum);
		npsm[ID_WINDOW_3]->setPixelColor(x, low_sum, 0, 0);
	}

	npsm[ID_WINDOW_1]->show();
	npsm[ID_WINDOW_2]->show();
	npsm[ID_WINDOW_3]->show();

	this->current_exec++;
}

/* ~~~ Animation Advanced Audio: Bass and Mid Window Pulse ~~~ */

void Animation_Advanced_Audio_BassMidPulseWindow::init() {
 	Animation_Advanced_Audio::init();
 	this->name = F("Window[all]: Audio Bass and Mid Beat Pulse");
 	this->strips.push_back(ID_WINDOW_1);
 	this->strips.push_back(ID_WINDOW_2);
 	this->strips.push_back(ID_WINDOW_3);
}

void Animation_Advanced_Audio_BassMidPulseWindow::step() {
	low_sum_l = quadraticBrightness(left_eq->get8Bit(1));
	low_sum_r = quadraticBrightness(right_eq->get8Bit(1));
	mid_sum_l = (int) round(((float) quadraticBrightness(left_eq->get8Bit(3)) + (float) quadraticBrightness(left_eq->get8Bit(4)) * 0.75 + (float) quadraticBrightness(left_eq->get8Bit(5)) * 0.25) / 2.0);
	mid_sum_r = (int) round(((float) quadraticBrightness(right_eq->get8Bit(3)) + (float) quadraticBrightness(right_eq->get8Bit(4)) * 0.75 + (float) quadraticBrightness(right_eq->get8Bit(5)) * 0.25) / 2.0);

	low_sum = (int) round((float) (low_sum_l + low_sum_r) / 2.0);
	mid_sum = (int) round((float) (mid_sum_l + mid_sum_r) / 2.0);

	for (int x = 0; x < WINDOW_LENGTH; x++) {
		npsm[ID_WINDOW_1]->setPixelColor(x, low_sum, 0, low_sum);
		npsm[ID_WINDOW_2]->setPixelColor(x, mid_sum, mid_sum, 0);
		npsm[ID_WINDOW_3]->setPixelColor(x, low_sum, 0, low_sum);
	}

	npsm[ID_WINDOW_1]->show();
	npsm[ID_WINDOW_2]->show();
	npsm[ID_WINDOW_3]->show();

	this->current_exec++;
}

/* ~~~ Animation Advanced Audio: Bass and Mid Window Pulse ~~~ */

void Animation_Advanced_Audio_BassPulseMidHueWindow::init() {
 	Animation_Advanced_Audio::init();
 	this->name = F("Window[all]: Audio Bass Beat Pulse and Mid Hue");
 	this->strips.push_back(ID_WINDOW_1);
 	this->strips.push_back(ID_WINDOW_2);
 	this->strips.push_back(ID_WINDOW_3);
}

void Animation_Advanced_Audio_BassPulseMidHueWindow::step() {
	low_sum_l = quadraticBrightness(left_eq->get8Bit(1));
	low_sum_r = quadraticBrightness(right_eq->get8Bit(1));
	mid_sum_l = (int) round(((float) quadraticBrightness(left_eq->get8Bit(3)) + (float) quadraticBrightness(left_eq->get8Bit(4)) * 0.65 + (float) quadraticBrightness(left_eq->get8Bit(5)) * 0.25) / 1.9);
	mid_sum_r = (int) round(((float) quadraticBrightness(right_eq->get8Bit(3)) + (float) quadraticBrightness(right_eq->get8Bit(4)) * 0.65 + (float) quadraticBrightness(right_eq->get8Bit(5)) * 0.25) / 1.9);

	low_sum = (int) round((float) (low_sum_l + low_sum_r) / 2.0);
	mid_sum = (int) round((float) (mid_sum_l + mid_sum_r) / 2.0);
	hue = ColorWheel(mid_sum);

	// center window (bass)
	for (int x = 0; x < WINDOW_LENGTH; x++) {
		npsm[ID_WINDOW_2]->setPixelColor(x, low_sum, low_sum, low_sum);
	}

	// side windows (mid hue)
	for (int x = 0; x < WINDOW_LENGTH; x++) {
		npsm[ID_WINDOW_1]->setPixelColor(x, hue);
		npsm[ID_WINDOW_3]->setPixelColor(x, hue);
	}

	npsm[ID_WINDOW_1]->show();
	npsm[ID_WINDOW_2]->show();
	npsm[ID_WINDOW_3]->show();

	this->current_exec++;
}

/* ~~~ Animation Advanced Audio: Circular Equalizer and Base Pulse Window ~~~ */

void Animation_Advanced_Audio_BasePulseCircularEqWindow::init() {
 	Animation_Advanced_Audio::init();
 	this->name = F("Window[all]: Audio Bass Pulse and Circular Equalizer");
 	this->strips.push_back(ID_WINDOW_1);
 	this->strips.push_back(ID_WINDOW_2);
 	this->strips.push_back(ID_WINDOW_3);
}

void Animation_Advanced_Audio_BasePulseCircularEqWindow::step() {
	low_sum = (int) round((float) (quadraticBrightness(left_eq->get8Bit(1)) + quadraticBrightness(right_eq->get8Bit(1))) / 2.0);

	no_0 = true;
	no_1 = true;
	no_2 = true;
	no_3 = true;
	no_4 = true;
	no_5 = true;
	no_6 = true;

	// side windows (lows) (bottom 3)
	for (int x = 0; x < WINDOW_LENGTH; x++) {
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
	for (int x = 0; x < WINDOW_LENGTH; x++) {
		npsm[ID_WINDOW_2]->setPixelColor(x, low_sum, low_sum, low_sum);
	}

	npsm[ID_WINDOW_1]->show();
	npsm[ID_WINDOW_2]->show();
	npsm[ID_WINDOW_3]->show();

	this->current_exec++;
}

/* ~~~ Animation Advanced Audio: Basic Equalizer ~~~ */

void Animation_Advanced_Audio_EqualizerWindow::init() {
 	Animation_Advanced_Audio::init();
 	this->name = F("Window[all]: Basic Audio Equalizer");
 	this->strips.push_back(ID_WINDOW_1);
 	this->strips.push_back(ID_WINDOW_2);
 	this->strips.push_back(ID_WINDOW_3);

	// clear these once, for efficency
	for (int i = 0; i < 9; i++) {
		npsm[ID_WINDOW_1]->setPixelColor(i, COLOR_OFF);
		npsm[ID_WINDOW_2]->setPixelColor(i, COLOR_OFF);
		npsm[ID_WINDOW_3]->setPixelColor(i, COLOR_OFF);
	}
}

void Animation_Advanced_Audio_EqualizerWindow::step() {
	// map is (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min
	val[0] = (int) round(((float) (left_eq->get8Bit(0) * -30 / 255 + 80) + (float) (right_eq->get8Bit(0) * -30 / 255 + 80)) / 2.0);
	val[1] = (int) round(((float) (left_eq->get8Bit(1) * 31 / 255 + 9) + (float) (right_eq->get8Bit(1) * 31 / 255 + 9)) / 2.0);
	val[2] = (int) round(((float) (left_eq->get8Bit(2) * -30 / 255 + 80) + (float) (right_eq->get8Bit(2) * -30 / 255 + 80)) / 2.0);
	val[3] = (int) round(((float) (left_eq->get8Bit(3) * 31 / 255 + 9) + (float) (right_eq->get8Bit(3) * 31 / 255 + 9)) / 2.0);
	val[4] = (int) round(((float) (left_eq->get8Bit(4) * -30 / 255 + 80) + (float) (right_eq->get8Bit(4) * -30 / 255 + 80)) / 2.0);
	val[5] = (int) round(((float) (left_eq->get8Bit(5) * 31 / 255 + 9) + (float) (right_eq->get8Bit(5) * 31 / 255 + 9)) / 2.0);
	// val[6] = left_eq->get8Bit(6) * 29 / 255;

	// low eqs
	for (unsigned int x = 9; x < WINDOW_LENGTH; x++) {
		if (x <= val[1] && x >= 9) {
			npsm[ID_WINDOW_1]->setPixelColor(x, COLOR_ORANGE);
		} else if (x >= val[0] && x <= 80) {
			npsm[ID_WINDOW_1]->setPixelColor(x, COLOR_RED);
		} else {
			npsm[ID_WINDOW_1]->setPixelColor(x, COLOR_OFF);
		}
	}

	// mid eqs
	for (unsigned int x = 9; x < WINDOW_LENGTH; x++) {
		if (x <= val[3] && x >= 9) {
			npsm[ID_WINDOW_2]->setPixelColor(x, COLOR_GREEN);
		} else if (x >= val[2] && x <= 80) {
			npsm[ID_WINDOW_2]->setPixelColor(x, COLOR_YELLOW);
		} else {
			npsm[ID_WINDOW_2]->setPixelColor(x, COLOR_OFF);
		}
	}

	// high eqs
	for (unsigned int x = 9; x < WINDOW_LENGTH; x++) {
		if (x <= val[5] && x >= 9) {
			npsm[ID_WINDOW_3]->setPixelColor(x, COLOR_PURPLE);
		} else if (x >= val[4] && x <= 80) {
			npsm[ID_WINDOW_3]->setPixelColor(x, COLOR_BLUE);
		} else {
			npsm[ID_WINDOW_3]->setPixelColor(x, COLOR_OFF);
		}
	}

	// 16khz eq
	// for (unsigned int x = 0; x < DESK2_LENGTH; x++) {
	// 	if (x <= val[6]) {
	// 		npsm[ID_DESK_2]->setPixelColor(x, COLOR_WHITE);
	// 	} else {
	// 		npsm[ID_DESK_2]->setPixelColor(x, COLOR_OFF);
	// 	}
	// }

	npsm[ID_WINDOW_1]->show();
	npsm[ID_WINDOW_2]->show();
	npsm[ID_WINDOW_3]->show();
	// npsm[ID_DESK_2]->show();

	this->current_exec++;
}

/* ~~~ Animation Advanced Audio: Advanced Equalizer w/ Max ~~~ */

void Animation_Advanced_Audio_MaxEqualizerWindow::init() {
 	Animation_Advanced_Audio::init();
 	this->name = F("Window[all]: Audio Equalizer With Max");
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
	// max[6] = 0;

	count = 0;

	// clear these once, for efficency
	for (int i = 0; i < 9; i++) {
		npsm[ID_WINDOW_1]->setPixelColor(i, COLOR_OFF);
		npsm[ID_WINDOW_2]->setPixelColor(i, COLOR_OFF);
		npsm[ID_WINDOW_3]->setPixelColor(i, COLOR_OFF);
	}
}

void Animation_Advanced_Audio_MaxEqualizerWindow::step() {
	// map is (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min
	val[0] = (int) round(((float) (left_eq->get8Bit(0) * -30 / 255 + 80) + (float) (right_eq->get8Bit(0) * -30 / 255 + 80)) / 2.0);
	val[1] = (int) round(((float) (left_eq->get8Bit(1) * 31 / 255 + 9) + (float) (right_eq->get8Bit(1) * 31 / 255 + 9)) / 2.0);
	val[2] = (int) round(((float) (left_eq->get8Bit(2) * -30 / 255 + 80) + (float) (right_eq->get8Bit(2) * -30 / 255 + 80)) / 2.0);
	val[3] = (int) round(((float) (left_eq->get8Bit(3) * 31 / 255 + 9) + (float) (right_eq->get8Bit(3) * 31 / 255 + 9)) / 2.0);
	val[4] = (int) round(((float) (left_eq->get8Bit(4) * -30 / 255 + 80) + (float) (right_eq->get8Bit(4) * -30 / 255 + 80)) / 2.0);
	val[5] = (int) round(((float) (left_eq->get8Bit(5) * 31 / 255 + 9) + (float) (right_eq->get8Bit(5) * 31 / 255 + 9)) / 2.0);

	// update max vals
	for (int i = 0; i < 6; i++) {
		if ((i % 2 == 0) && i != 6) {
			if (max[i] >= val[i]) {
				max[i] = val[i];
			}
		} else {
			if (max[i] <= val[i]) {
				max[i] = val[i];
			}
		}
	}

	// low eqs
	for (unsigned int x = 9; x < WINDOW_LENGTH; x++) {
		if (x <= val[1] && x >= 9) {
			npsm[ID_WINDOW_1]->setPixelColor(x, COLOR_ORANGE);
		} else if (x >= val[0] && x <= 80) {
			npsm[ID_WINDOW_1]->setPixelColor(x, COLOR_RED);
		} else {
			npsm[ID_WINDOW_1]->setPixelColor(x, COLOR_OFF);
		}

		if (x == max[0] || x == max[1]) {
			npsm[ID_WINDOW_1]->setPixelColor(x, COLOR_WHITE);
		}
	}

	// mid eqs
	for (unsigned int x = 9; x < WINDOW_LENGTH; x++) {
		if (x <= val[3] && x >= 9) {
			npsm[ID_WINDOW_2]->setPixelColor(x, COLOR_GREEN);
		} else if (x >= val[2] && x <= 80) {
			npsm[ID_WINDOW_2]->setPixelColor(x, COLOR_YELLOW);
		} else {
			npsm[ID_WINDOW_2]->setPixelColor(x, COLOR_OFF);
		}

		if (x == max[2] || x == max[3]) {
			npsm[ID_WINDOW_2]->setPixelColor(x, COLOR_WHITE);
		}
	}

	// high eqs
	for (unsigned int x = 9; x < WINDOW_LENGTH; x++) {
		if (x <= val[5] && x >= 9) {
			npsm[ID_WINDOW_3]->setPixelColor(x, COLOR_PURPLE);
		} else if (x >= val[4] && x <= 80) {
			npsm[ID_WINDOW_3]->setPixelColor(x, COLOR_BLUE);
		} else {
			npsm[ID_WINDOW_3]->setPixelColor(x, COLOR_OFF);
		}

		if (x == max[4] || x == max[5]) {
			npsm[ID_WINDOW_3]->setPixelColor(x, COLOR_WHITE);
		}
	}

	// 16khz eq
	// for (unsigned int x = 0; x < 29; x++) {
	// 	if (x <= val[6]) {
	// 		npsm[ID_DESK_2]->setPixelColor(x, COLOR_WHITE);
	// 	} else {
	// 		npsm[ID_DESK_2]->setPixelColor(x, COLOR_OFF);
	// 	}
	//
	// 	if (x == max[6]) {
	// 		npsm[ID_DESK_2]->setPixelColor(x, COLOR_RED);
	// 	}
	// }

	// update strips
	npsm[ID_WINDOW_1]->show();
	npsm[ID_WINDOW_2]->show();
	npsm[ID_WINDOW_3]->show();
	// npsm[ID_DESK_2]->show();

	// slowly drift max vals back down if possible
	if (count >= 12) {
		count = 0;

		for (int i = 0; i < 6; i++) {
			if ((i % 2 == 0) && i != 6) {
				if (max[i] < val[i]) {
					max[i]++;
				}

				if (max[i] <= 50) {
					max[i] = 51; // it shouldn't be there
				} else if (max[i] > 80) {
					max[i] = 80;
				}
			} else {
				if (max[i] > val[i]) {
					max[i]--;
				}

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

void Animation_Advanced_Audio_MaxBassEqualizerCeiling::init() {
 	Animation_Advanced_Audio::init();
 	this->name = F("Window[all]: Horiz. Audio Eq. w/ Max");
 	this->strips.push_back(ID_CEILING_LEFT);
 	this->strips.push_back(ID_CEILING_RIGHT);

	// initialize max vals
	max[0] = 0;
	max[1] = 0;

	count = 0;

	for (int i = 0; i < CEILING_LEFT_LENGTH; i++) {
		npsm[ID_CEILING_LEFT]->setPixelColor(i, COLOR_OFF);
	}

	for (int i = 0; i < CEILING_RIGHT_LENGTH; i++) {
		npsm[ID_CEILING_RIGHT]->setPixelColor(i, COLOR_OFF);
	}
}

void Animation_Advanced_Audio_MaxBassEqualizerCeiling::step() {
	// get EQ values
	val[0] = left_eq->getInRange(1, 0, CEILING_RIGHT_LENGTH);
	val[1] = right_eq->getInRange(1, 0, CEILING_RIGHT_LENGTH);

	// update max vals
	for (int i = 0; i < 2; i++) {
		if (max[i] <= val[i]) {
			max[i] = val[i];
		}
	}

	// low eqs
	for (unsigned int x = 0; x < CEILING_LEFT_LENGTH; x++) {
		if (x <= val[0]) {
			npsm[ID_CEILING_LEFT]->setPixelColor(x, COLOR_ORANGE);
		} else {
			npsm[ID_CEILING_LEFT]->setPixelColor(x, COLOR_OFF);
		}

		if (x == max[0]) {
			npsm[ID_CEILING_LEFT]->setPixelColor(x, COLOR_WHITE);
		}
	}

	for (unsigned int x = 0; x < CEILING_RIGHT_LENGTH; x++) {
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
	if (count >= 10) {
		count = 0;

		for (int i = 0; i < 2; i++) {
			if (max[i] > val[i] && max[i] > 0) {
				max[i]--;
			}
		}

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
