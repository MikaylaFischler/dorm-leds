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

/* ~~~ Animation Advanced Audio: Beat Pulse Window ~~~ */

void Animation_Advanced_Audio_BasePulseCircularEqWindow::init() {
 	Animation_Advanced_Audio::init();
 	this->name = F("Window[all]: Audio Bass Pulse and Circular Equalizer");
	this->num_strips = 3;
 	this->strips = WINDOW_ALL;
}

void Animation_Advanced_Audio_BasePulseCircularEqWindow::step() {
	int low_sum = (int) round((float) (quadraticBrightness(left_eq->get8Bit(1)) + quadraticBrightness(right_eq->get8Bit(1))) / 2.0);

	bool no_0 = true;
	bool no_1 = true;
	bool no_2 = true;
	bool no_3 = true;
	bool no_4 = true;
	bool no_5 = true;
	bool no_6 = true;

	// side windows (lows) (bottom 3)
	for (int x = 0; x < WINDOW_LENGTH; x++) {
		if (no_0 && x == left_eq->getInWindowRange(0)) {
			long unsigned int val = ColorWheel(left_eq->get8Bit(0));
			window1.setPixelColor(x, val);
			window3.setPixelColor(x, val);
			no_0 = false;
		} else if (no_1 && x == left_eq->getInWindowRange(1)) {
			long unsigned int val = ColorWheel(left_eq->get8Bit(1));
			window1.setPixelColor(x, val);
			window3.setPixelColor(x, val);
			no_1 = false;
		} else if (no_2 && x == left_eq->getInWindowRange(2)) {
			long unsigned int val = ColorWheel(left_eq->get8Bit(2));
			window1.setPixelColor(x, val);
			window3.setPixelColor(x, val);
			no_2 = false;
		} else if (no_3 && x == left_eq->getInWindowRange(3)) {
			long unsigned int val = ColorWheel(left_eq->get8Bit(3));
			window1.setPixelColor(x, val);
			window3.setPixelColor(x, val);
			no_3 = false;
		} else if (no_4 && x == left_eq->getInWindowRange(4)) {
			long unsigned int val = ColorWheel(left_eq->get8Bit(4));
			window1.setPixelColor(x, val);
			window3.setPixelColor(x, val);
			no_4 = false;
		} else if (no_5 && x == left_eq->getInWindowRange(5)) {
			long unsigned int val = ColorWheel(left_eq->get8Bit(5));
			window1.setPixelColor(x, val);
			window3.setPixelColor(x, val);
			no_5 = false;
		} else if (no_6 && x == left_eq->getInWindowRange(6)) {
			long unsigned int val = ColorWheel(left_eq->get8Bit(6));
			window1.setPixelColor(x, val);
			window3.setPixelColor(x, val);
			no_6 = false;
		} else {
			window1.setPixelColor(x, COLOR_OFF);
			window3.setPixelColor(x, COLOR_OFF);
		}
	}

	// center window (bass)
	for (int x = 0; x < WINDOW_LENGTH; x++) {
		window2.setPixelColor(x, low_sum, low_sum, low_sum);
	}

	window1.show();
	window2.show();
	window3.show();

	this->current_exec++;
}

/* ~~~ Animation Advanced Audio: Bass Window Pulse ~~~ */

void Animation_Advanced_Audio_BassPulseWindow::init() {
 	Animation_Advanced_Audio::init();
 	this->name = F("Window[all]: Audio Bass Beat Pulse");
	this->num_strips = 3;
 	this->strips = WINDOW_ALL;
}

void Animation_Advanced_Audio_BassPulseWindow::step() {
	int low_sum = (int) round(((float) quadraticBrightness(left_eq->get8Bit(1)) + (float) quadraticBrightness(right_eq->get8Bit(1))) / 2.0);
	int low2_sum = (int) round(((float) quadraticBrightness(left_eq->get8Bit(2)) + (float) quadraticBrightness(right_eq->get8Bit(2))) / 2.0);

	for (int x = 0; x < WINDOW_LENGTH; x++) {
		window1.setPixelColor(x, low_sum, 0, 0);
		window2.setPixelColor(x, 0, low2_sum, low2_sum);
		window3.setPixelColor(x, low_sum, 0, 0);
	}

	window1.show();
	window2.show();
	window3.show();

	this->current_exec++;
}

/* ~~~ Animation Advanced Audio: Bass and Mid Window Pulse ~~~ */

void Animation_Advanced_Audio_BassMidPulseWindow::init() {
 	Animation_Advanced_Audio::init();
 	this->name = F("Window[all]: Audio Bass and Mid Beat Pulse");
	this->num_strips = 3;
 	this->strips = WINDOW_ALL;
}

void Animation_Advanced_Audio_BassMidPulseWindow::step() {
	int low_sum_l = quadraticBrightness(left_eq->get8Bit(1));
	int low_sum_r = quadraticBrightness(right_eq->get8Bit(1));
	int mid_sum_l = (int) round(((float) quadraticBrightness(left_eq->get8Bit(3)) + (float) quadraticBrightness(left_eq->get8Bit(4)) * 0.75 + (float) quadraticBrightness(left_eq->get8Bit(5)) * 0.25) / 2.0);
	int mid_sum_r = (int) round(((float) quadraticBrightness(right_eq->get8Bit(3)) + (float) quadraticBrightness(right_eq->get8Bit(4)) * 0.75 + (float) quadraticBrightness(right_eq->get8Bit(5)) * 0.25) / 2.0);

	int low_sum = (int) round((float) (low_sum_l + low_sum_r) / 2.0);
	int mid_sum = (int) round((float) (mid_sum_l + mid_sum_r) / 2.0);

	for (int x = 0; x < WINDOW_LENGTH; x++) {
		window1.setPixelColor(x, low_sum, 0, low_sum);
		window2.setPixelColor(x, mid_sum, mid_sum, 0);
		window3.setPixelColor(x, low_sum, 0, low_sum);
	}

	window1.show();
	window2.show();
	window3.show();

	this->current_exec++;
}

/* ~~~ Animation Advanced Audio: Bass and Mid Window Pulse ~~~ */

void Animation_Advanced_Audio_BassPulseMidHueWindow::init() {
 	Animation_Advanced_Audio::init();
 	this->name = F("Window[all]: Audio Bass Beat Pulse and Mid Hue");
	this->num_strips = 3;
 	this->strips = WINDOW_ALL;
}

void Animation_Advanced_Audio_BassPulseMidHueWindow::step() {
	int low_sum_l = quadraticBrightness(left_eq->get8Bit(1));
	int low_sum_r = quadraticBrightness(right_eq->get8Bit(1));
	int mid_sum_l = (int) round(((float) quadraticBrightness(left_eq->get8Bit(3)) + (float) quadraticBrightness(left_eq->get8Bit(4)) * 0.65 + (float) quadraticBrightness(left_eq->get8Bit(5)) * 0.25) / 1.9);
	int mid_sum_r = (int) round(((float) quadraticBrightness(right_eq->get8Bit(3)) + (float) quadraticBrightness(right_eq->get8Bit(4)) * 0.65 + (float) quadraticBrightness(right_eq->get8Bit(5)) * 0.25) / 1.9);

	int low_sum = (int) round((float) (low_sum_l + low_sum_r) / 2.0);
	int mid_sum = (int) round((float) (mid_sum_l + mid_sum_r) / 2.0);
	long unsigned int hue = ColorWheel(mid_sum);

	// center window (bass)
	for (int x = 0; x < WINDOW_LENGTH; x++) {
		window2.setPixelColor(x, low_sum, low_sum, low_sum);
	}

	// side windows (mid hue)
	for (int x = 0; x < WINDOW_LENGTH; x++) {
		window1.setPixelColor(x, hue);
		window3.setPixelColor(x, hue);
	}

	window1.show();
	window2.show();
	window3.show();

	this->current_exec++;
}

/* ~~~ Animation Advanced Audio: Basic Equalizer ~~~ */

void Animation_Advanced_Audio_EqualizerWindow::init() {
 	Animation_Advanced_Audio::init();
 	this->name = F("Window[all]: Basic Audio Equalizer");
	this->num_strips = 3;
 	this->strips = WINDOW_ALL;

	// clear these once, for efficency
	for (int i = 0; i < 9; i++) {
		window1.setPixelColor(i, COLOR_OFF);
		window2.setPixelColor(i, COLOR_OFF);
		window3.setPixelColor(i, COLOR_OFF);
	}
}

void Animation_Advanced_Audio_EqualizerWindow::step() {
	unsigned int val[7];

	// map is (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min
	val[0] = (int) round(((float) (left_eq->get8Bit(0) * -30 / 255 + 80) + (float) (right_eq->get8Bit(0) * -30 / 255 + 80)) / 2.0);
	val[1] = (int) round(((float) (left_eq->get8Bit(1) * 31 / 255 + 9) + (float) (right_eq->get8Bit(1) * 31 / 255 + 9)) / 2.0);
	val[2] = (int) round(((float) (left_eq->get8Bit(2) * -30 / 255 + 80) + (float) (right_eq->get8Bit(2) * -30 / 255 + 80)) / 2.0);
	val[3] = (int) round(((float) (left_eq->get8Bit(3) * 31 / 255 + 9) + (float) (right_eq->get8Bit(3) * 31 / 255 + 9)) / 2.0);
	val[4] = (int) round(((float) (left_eq->get8Bit(4) * -30 / 255 + 80) + (float) (right_eq->get8Bit(4) * -30 / 255 + 80)) / 2.0);
	val[5] = (int) round(((float) (left_eq->get8Bit(5) * 31 / 255 + 9) + (float) (right_eq->get8Bit(5) * 31 / 255 + 9)) / 2.0);
	// val[6] = left_eq->get8Bit(5) * 29 / 255;

	// low eqs
	for (unsigned int x = 9; x < WINDOW_LENGTH; x++) {
		if (x <= val[1] && x >= 9) {
			window1.setPixelColor(x, COLOR_ORANGE);
		} else if (x >= val[0] && x <= 80) {
			window1.setPixelColor(x, COLOR_RED);
		} else {
			window1.setPixelColor(x, COLOR_OFF);
		}
	}

	// mid eqs
	for (unsigned int x = 9; x < WINDOW_LENGTH; x++) {
		if (x <= val[3] && x >= 9) {
			window2.setPixelColor(x, COLOR_GREEN);
		} else if (x >= val[2] && x <= 80) {
			window2.setPixelColor(x, COLOR_YELLOW);
		} else {
			window2.setPixelColor(x, COLOR_OFF);
		}
	}

	// high eqs
	for (unsigned int x = 9; x < WINDOW_LENGTH; x++) {
		if (x <= val[5] && x >= 9) {
			window3.setPixelColor(x, COLOR_VIOLET);
		} else if (x >= val[4] && x <= 80) {
			window3.setPixelColor(x, COLOR_BLUE);
		} else {
			window3.setPixelColor(x, COLOR_OFF);
		}
	}

	// 16khz eq
	// for (unsigned int x = 0; x < DESK2_LENGTH; x++) {
	// 	if (x <= val[6]) {
	// 		desk2.setPixelColor(x, COLOR_WHITE);
	// 	} else {
	// 		desk2.setPixelColor(x, COLOR_OFF);
	// 	}
	// }

	window1.show();
	window2.show();
	window3.show();
	// desk2.show();

	this->current_exec++;
}

/* ~~~ Animation Advanced Audio: Advanced Equalizer w/ Max ~~~ */

void Animation_Advanced_Audio_MaxEqualizerWindow::init() {
 	Animation_Advanced_Audio::init();
 	this->name = F("Window[all]: Audio Equalizer With Max");
	this->num_strips = 3;
 	this->strips = WINDOW_ALL;

	this->stack = new LocalStack();
	this->stack->push(new MemObj(new unsigned short int[6]));
	this->stack->push(new MemObj(new unsigned int(0)));

	// initialize max vals
	unsigned short int* max = this->stack->get(0)->getpointer<unsigned short int>();
	max[0] = 80;
	max[1] = 9;
	max[2] = 80;
	max[3] = 9;
	max[4] = 80;
	max[5] = 9;
	// max[6] = 0;

	// clear these once, for efficency
	for (int i = 0; i < 9; i++) {
		window1.setPixelColor(i, COLOR_OFF);
		window2.setPixelColor(i, COLOR_OFF);
		window3.setPixelColor(i, COLOR_OFF);
	}
}

void Animation_Advanced_Audio_MaxEqualizerWindow::step() {
	unsigned short int* max = this->stack->get(0)->getpointer<unsigned short int>();
	unsigned int& count = this->stack->get(1)->get<unsigned int>();
	unsigned int val[6];

	// map is (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min
	val[0] = (int) round(((float) (left_eq->get8Bit(0) * -30 / 255 + 80) + (float) (right_eq->get8Bit(0) * -30 / 255 + 80)) / 2.0);
	val[1] = (int) round(((float) (left_eq->get8Bit(1) * 31 / 255 + 9) + (float) (right_eq->get8Bit(1) * 31 / 255 + 9)) / 2.0);
	val[2] = (int) round(((float) (left_eq->get8Bit(2) * -30 / 255 + 80) + (float) (right_eq->get8Bit(2) * -30 / 255 + 80)) / 2.0);
	val[3] = (int) round(((float) (left_eq->get8Bit(3) * 31 / 255 + 9) + (float) (right_eq->get8Bit(3) * 31 / 255 + 9)) / 2.0);
	val[4] = (int) round(((float) (left_eq->get8Bit(4) * -30 / 255 + 80) + (float) (right_eq->get8Bit(4) * -30 / 255 + 80)) / 2.0);
	val[5] = (int) round(((float) (left_eq->get8Bit(5) * 31 / 255 + 9) + (float) (right_eq->get8Bit(5) * 31 / 255 + 9)) / 2.0);
	// val[6] = left_eq->get8Bit(5) * 29 / 255;

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
			window1.setPixelColor(x, COLOR_ORANGE);
		} else if (x >= val[0] && x <= 80) {
			window1.setPixelColor(x, COLOR_RED);
		} else {
			window1.setPixelColor(x, COLOR_OFF);
		}

		if (x == max[0] || x == max[1]) {
			window1.setPixelColor(x, COLOR_WHITE);
		}
	}

	// mid eqs
	for (unsigned int x = 9; x < WINDOW_LENGTH; x++) {
		if (x <= val[3] && x >= 9) {
			window2.setPixelColor(x, COLOR_GREEN);
		} else if (x >= val[2] && x <= 80) {
			window2.setPixelColor(x, COLOR_YELLOW);
		} else {
			window2.setPixelColor(x, COLOR_OFF);
		}

		if (x == max[2] || x == max[3]) {
			window2.setPixelColor(x, COLOR_WHITE);
		}
	}

	// high eqs
	for (unsigned int x = 9; x < WINDOW_LENGTH; x++) {
		if (x <= val[5] && x >= 9) {
			window3.setPixelColor(x, COLOR_VIOLET);
		} else if (x >= val[4] && x <= 80) {
			window3.setPixelColor(x, COLOR_BLUE);
		} else {
			window3.setPixelColor(x, COLOR_OFF);
		}

		if (x == max[4] || x == max[5]) {
			window3.setPixelColor(x, COLOR_WHITE);
		}
	}

	// 16khz eq
	// for (unsigned int x = 0; x < 29; x++) {
	// 	if (x <= val[6]) {
	// 		desk2.setPixelColor(x, COLOR_WHITE);
	// 	} else {
	// 		desk2.setPixelColor(x, COLOR_OFF);
	// 	}
	//
	// 	if (x == max[6]) {
	// 		desk2.setPixelColor(x, COLOR_RED);
	// 	}
	// }

	// update strips
	window1.show();
	window2.show();
	window3.show();
	// desk2.show();

	// slowly drift max vals back down if possible
	if (count >= 15) {
		count = 0;

		for (int i = 0; i < 6; i++) {
			if ((i % 2 == 0) && i != 6) {
				if (max[i] < val[i]) {
					max[i]++;
				}
			} else {
				if (max[i] > val[i]) {
					max[i]--;
				}
			}
		}
	} else {
		count++;
	}

	this->current_exec++;
}

void Animation_Advanced_Audio_MaxEqualizerWindow::clean() {
	this->stack->get(0)->destroyarray<unsigned short int>();
	this->stack->get(1)->destroy<unsigned int>();

	delete this->stack;
}
