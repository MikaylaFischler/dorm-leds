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
 	this->name = F("Audio Bass Beat Pulse L/R");
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
 	this->name = F("Audio Bass Beat Pulse Nested L/R");
 	this->strips.push_back(strip1);
 	this->strips.push_back(strip2);
}

void Animation_Advanced_Audio_BassPulseNestedLR::step() {
	low_L = quadraticBrightness(left_eq->get8Bit(1));
	low_R = quadraticBrightness(right_eq->get8Bit(1));
	low2_L = quadraticBrightness(left_eq->get8Bit(2));
	low2_R = quadraticBrightness(right_eq->get8Bit(2));

	mid = ((npsm[strip1]->numPixels()) / 2);
	for (int x = 0; x < npsm[strip1]->numPixels(); x++) {
		if (x > mid - (mid / 3) && x < mid + (mid / 3)) {
			npsm[strip1]->setPixelColor(x, low2_L, (int) round(low2_L * 50.0/255.0), 0);
		} else {
			npsm[strip1]->setPixelColor(x, low_L, 0, 0);
		}
	}

	mid = ((npsm[strip2]->numPixels()) / 2);
	for (int x = 0; x < npsm[strip2]->numPixels(); x++) {
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

/* ~~~ Animation Advanced Audio: Pulse Nested w/ Left and Right ~~~ */

void Animation_Advanced_Audio_PulseNestedLR::init() {
 	Animation_Advanced_Audio::init();
 	this->name = F("Audio Pulse Nested L/R");
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

		for (int x = 0; x < len; x++) {
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

		for (int x = 0; x < len; x++) {
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

		for (int x = 0; x < len; x++) {
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

		for (int x = 0; x < len; x++) {
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

// given strip
Animation_Advanced_Audio_BassPulseStrip::Animation_Advanced_Audio_BassPulseStrip(int strip) : fadeFunctionOrder(4), color(COLOR_WHITE) { this->strip_ids.push_back(strip); }
Animation_Advanced_Audio_BassPulseStrip::Animation_Advanced_Audio_BassPulseStrip(vector<int> strip_ids) : fadeFunctionOrder(4), color(COLOR_WHITE) { this->strip_ids = strip_ids; }

// give strip and fade function order
Animation_Advanced_Audio_BassPulseStrip::Animation_Advanced_Audio_BassPulseStrip(int strip, short unsigned int _fadeFO) : fadeFunctionOrder(_fadeFO), color(COLOR_WHITE) { this->strip_ids.push_back(strip); }
Animation_Advanced_Audio_BassPulseStrip::Animation_Advanced_Audio_BassPulseStrip(vector<int> strip_ids, short unsigned int _fadeFO) : fadeFunctionOrder(_fadeFO), color(COLOR_WHITE) { this->strip_ids = strip_ids; }

// given strip, fade function order, and color
Animation_Advanced_Audio_BassPulseStrip::Animation_Advanced_Audio_BassPulseStrip(int strip, short unsigned int _fadeFO, long unsigned int _color) : fadeFunctionOrder(_fadeFO), color(_color) { this->strip_ids.push_back(strip); }
Animation_Advanced_Audio_BassPulseStrip::Animation_Advanced_Audio_BassPulseStrip(vector<int> strip_ids, short unsigned int _fadeFO, long unsigned int _color) : fadeFunctionOrder(_fadeFO), color(_color) { this->strip_ids = strip_ids; }

void Animation_Advanced_Audio_BassPulseStrip::init() {
 	Animation_Advanced_Audio::init();
	this->name = F("Audio Bass Pulse Strip");

	for (uint16_t i = 0; i < this->strip_ids.size(); i++) {
		this->strips.push_back(this->strip_ids[i]);
	}
}

void Animation_Advanced_Audio_BassPulseStrip::step() {
	switch (this->fadeFunctionOrder) {
		case 4: // quartic
			freq_range_0_sum = avg16(quarticBrightness(left_eq->get8Bit(0)), quarticBrightness(right_eq->get8Bit(0)));
			freq_range_1_sum = avg16(quarticBrightness(left_eq->get8Bit(1)), quarticBrightness(right_eq->get8Bit(1)));
			break;
		case 3: // cubic
			freq_range_0_sum = avg16(cubicBrightness(left_eq->get8Bit(0)), cubicBrightness(right_eq->get8Bit(0)));
			freq_range_1_sum = avg16(cubicBrightness(left_eq->get8Bit(1)), cubicBrightness(right_eq->get8Bit(1)));
			break;
		case 2: // quadratic
		default:
			freq_range_0_sum = avg16(quadraticBrightness(left_eq->get8Bit(0)), quadraticBrightness(right_eq->get8Bit(0)));
			freq_range_1_sum = avg16(quadraticBrightness(left_eq->get8Bit(1)), quadraticBrightness(right_eq->get8Bit(1)));
	}

	// get most significant value
	if (freq_range_0_sum > freq_range_1_sum) {
		result = freq_range_0_sum;
	} else {
		result = freq_range_1_sum;
	}

	for (uint16_t i = 0; i < this->strip_ids.size(); i++) {
		for (uint16_t x = 0; x < npsm[this->strip_ids[i]]->numPixels(); x++) {
			npsm[this->strip_ids[i]]->setPixelColor(x, result * redFromColor(this->color) / 255,
								      					result * greenFromColor(this->color) / 255,
								      					result * blueFromColor(this->color) / 255
													);
		}
	}

	for (uint16_t i = 0; i < this->strip_ids.size(); i++) {
		npsm[this->strip_ids[i]]->show();
	}

	this->current_exec++;
}

/* ~~~ Animation Advanced Audio: Bass and Mid Window Pulse ~~~ */

void Animation_Advanced_Audio_BassMidPulseWindow::init() {
 	Animation_Advanced_Audio::init();
 	this->name = F("Window Audio Bass and Mid Beat Pulse");
 	this->strips.push_back(ID_WINDOW_1);
 	this->strips.push_back(ID_WINDOW_2);
 	this->strips.push_back(ID_WINDOW_3);
}

void Animation_Advanced_Audio_BassMidPulseWindow::step() {
	low_sum_l = quadraticBrightness(left_eq->get8Bit(1));
	low_sum_r = quadraticBrightness(right_eq->get8Bit(1));
	mid_sum_l = (int) round(((float) quadraticBrightness(left_eq->get8Bit(3)) + (float) quadraticBrightness(left_eq->get8Bit(4)) * 0.75 + (float) quadraticBrightness(left_eq->get8Bit(5)) * 0.25) / 2.0);
	mid_sum_r = (int) round(((float) quadraticBrightness(right_eq->get8Bit(3)) + (float) quadraticBrightness(right_eq->get8Bit(4)) * 0.75 + (float) quadraticBrightness(right_eq->get8Bit(5)) * 0.25) / 2.0);

	low_sum = avg16(low_sum_l + low_sum_r);
	mid_sum = avg16(mid_sum_l + mid_sum_r);

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
 	this->name = F("Window Audio Bass Beat Pulse and Mid Hue");
 	this->strips.push_back(ID_WINDOW_1);
 	this->strips.push_back(ID_WINDOW_2);
 	this->strips.push_back(ID_WINDOW_3);
}

void Animation_Advanced_Audio_BassPulseMidHueWindow::step() {
	low_sum_l = quadraticBrightness(left_eq->get8Bit(1));
	low_sum_r = quadraticBrightness(right_eq->get8Bit(1));
	mid_sum_l = (int) round(((float) quadraticBrightness(left_eq->get8Bit(3)) + (float) quadraticBrightness(left_eq->get8Bit(4)) * 0.65 + (float) quadraticBrightness(left_eq->get8Bit(5)) * 0.25) / 1.9);
	mid_sum_r = (int) round(((float) quadraticBrightness(right_eq->get8Bit(3)) + (float) quadraticBrightness(right_eq->get8Bit(4)) * 0.65 + (float) quadraticBrightness(right_eq->get8Bit(5)) * 0.25) / 1.9);

	low_sum = avg16(low_sum_l + low_sum_r);
	mid_sum = avg16(mid_sum_l + mid_sum_r);
	hue = ColorWheel(mid_sum);

	// center window (bass)
	for (uint16_t x = 0; x < WINDOW_LENGTH; x++) {
		npsm[ID_WINDOW_2]->setPixelColor(x, low_sum, low_sum, low_sum);
	}

	// side windows (mid hue)
	for (uint16_t x = 0; x < WINDOW_LENGTH; x++) {
		npsm[ID_WINDOW_1]->setPixelColor(x, hue);
		npsm[ID_WINDOW_3]->setPixelColor(x, hue);
	}

	npsm[ID_WINDOW_1]->show();
	npsm[ID_WINDOW_2]->show();
	npsm[ID_WINDOW_3]->show();

	this->current_exec++;
}
