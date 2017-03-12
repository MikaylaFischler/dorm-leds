#include "Animation_Advanced.hpp"

/* ~~~ Generic Advanced Audio ~~~ */

// define the generic advanced audio init
void Animation_Advanced_Audio::init() {
  	Animation_Advanced::init();
    this->update_rate = 1; // at rate of audio update
}

/* ~~~ Animation Advanced Audio: Beat Pulse Window ~~~ */

void Animation_Advanced_Audio_BeatPulseWindow::init() {
 	Animation_Advanced_Audio::init();
 	this->name = F("Window[all]: Audio Beat Pulse");
	this->num_strips = 3;
 	this->strips = WINDOW_ALL;

	this->left_eq = device_manager.getDevice<MSGEQ7>(0);
}

void Animation_Advanced_Audio_BeatPulseWindow::step() {
	int low_sum = left_eq->get8Bit(1);//round((float) (left_eq->get8Bit(0) + left_eq->get8Bit(1)) / 2.0);
	int high_sum = left_eq->get8Bit(1);//round(((float) (left_eq->get8Bit(4) + left_eq->get8Bit(4) + left_eq->get8Bit(5) + left_eq->get8Bit(6))) / 4.0);



	// side windows (lows) (bottom 3)
	for (int x = 0; x < WINDOW_LENGTH; x++) {
		if (true) {
			long int val = ColorWheel(left_eq->get8Bit(3));
			window1.setPixelColor(x, val);
			window3.setPixelColor(x, val);
		}
		/*if (x == round(left_eq->get8Bit(0) * 0.31)) {
			int val = ColorWheel(left_eq->get8Bit(0));
			window1.setPixelColor(x, val);
			window3.setPixelColor(x, val);
		} else if (x == round(left_eq->get8Bit(1) * 0.31)) {
			int val = ColorWheel(left_eq->get8Bit(1));
			window1.setPixelColor(x, val);
			window3.setPixelColor(x, val);
		} else if (x == round(left_eq->get8Bit(2) * 0.31)) {
			int val = ColorWheel(left_eq->get8Bit(2));
			window1.setPixelColor(x, val);
			window3.setPixelColor(x, val);
		} else if (x == round(left_eq->get8Bit(3) * 0.31)) {
			int val = ColorWheel(left_eq->get8Bit(3));
			window1.setPixelColor(x, val);
			window3.setPixelColor(x, val);
		} else if (x == round(left_eq->get8Bit(4) * 0.31)) {
			int val = ColorWheel(left_eq->get8Bit(4));
			window1.setPixelColor(x, val);
			window3.setPixelColor(x, val);
		} else if (x == round(left_eq->get8Bit(5) * 0.31)) {
			int val = ColorWheel(left_eq->get8Bit(5));
			window1.setPixelColor(x, ColorWheel(val));
			window3.setPixelColor(x, ColorWheel(val));
		} else if (x == round(left_eq->get8Bit(6) * 0.31)) {
			int val = ColorWheel(left_eq->get8Bit(6));
			window1.setPixelColor(x, ColorWheel(val));
			window3.setPixelColor(x, ColorWheel(val));
		}*/ else {
			window1.setPixelColor(x, COLOR_OFF);
			window3.setPixelColor(x, COLOR_OFF);
		}

		/*if (x == round(low_sum * 0.31)) {
			window1.setPixelColor(x, low_sum, low_sum, low_sum);
			window3.setPixelColor(x, low_sum, low_sum, low_sum);
		} else {
			window1.setPixelColor(x, COLOR_OFF);
			window3.setPixelColor(x, COLOR_OFF);
		}*/
	}

	window1.show();
	window3.show();

	// center window (highs) (top 4)
	for (int x = 0; x < WINDOW_LENGTH; x++) {
		window2.setPixelColor(x, high_sum, high_sum, high_sum);
	}

	window2.show();

}

void Animation_Advanced_Audio_BeatPulseWindow::clean() {}

/* ~~~ Animation Advanced Audio: Base Window Pulse ~~~ */

void Animation_Advanced_Audio_BasePulseWindow::init() {
 	Animation_Advanced_Audio::init();
 	this->name = F("Window[all]: Audio Rainbow and Beat Pulse");
	this->num_strips = 3;
 	this->strips = WINDOW_ALL;

	this->left_eq = device_manager.getDevice<MSGEQ7>(0);
}

void Animation_Advanced_Audio_BasePulseWindow::step() {
	int low_sum = (int) (0.0039215686 * (double) pow(left_eq->get8Bit(1), 2));
	int high_sum = (int) (0.0039215686 * (double) pow(left_eq->get8Bit(2), 2));

	long int val = ColorWheel(high_sum);

	// side windows
	for (int x = 0; x < WINDOW_LENGTH; x++) {
		window1.setPixelColor(x, val);
		window3.setPixelColor(x, val);
	}

	//window1.show();
	//window3.show();

	// center window
	for (int x = 0; x < WINDOW_LENGTH; x++) {
		window1.setPixelColor(x, low_sum, 0, 0);
		window2.setPixelColor(x, high_sum, high_sum, high_sum);
		window3.setPixelColor(x, low_sum, 0, 0);
	}

	window2.show();
	window1.show();
	window3.show();
}

void Animation_Advanced_Audio_BasePulseWindow::clean() {}

/* ~~~ Animation Advanced Audio: Basic Equalizer ~~~ */

void Animation_Advanced_Audio_EqualizerWindow::init() {
 	Animation_Advanced_Audio::init();
 	this->name = F("Window[all]: Basic Audio Equalizer");
	this->num_strips = 3;
 	this->strips = WINDOW_ALL;

	this->left_eq = device_manager.getDevice<MSGEQ7>(0);
}

void Animation_Advanced_Audio_EqualizerWindow::step() {
	unsigned int val[7];

	val[0] = map(left_eq->get8Bit(0), 0, 255, 80, 50);
	val[1] = map(left_eq->get8Bit(1), 0, 255, 9, 40);
	val[2] = map(left_eq->get8Bit(2), 0, 255, 80, 50);
	val[3] = map(left_eq->get8Bit(3), 0, 255, 9, 40);
	val[4] = map(left_eq->get8Bit(4), 0, 255, 80, 50);
	val[5] = map(left_eq->get8Bit(5), 0, 255, 9, 40);
	val[6] = map(left_eq->get8Bit(6), 0, 255, 0, 29);

	for (unsigned int x = 0; x < WINDOW_LENGTH; x++) {
		if (x <= val[1] && x >= 9) {
			window1.setPixelColor(x, COLOR_ORANGE);
		} else if (x >= val[0] && x <= 80) {
			window1.setPixelColor(x, COLOR_RED);
		} else {
			window1.setPixelColor(x, COLOR_OFF);
		}
	}

	for (unsigned int x = 0; x < WINDOW_LENGTH; x++) {
		if (x <= val[3] && x >= 9) {
			window2.setPixelColor(x, COLOR_GREEN);
		} else if (x >= val[2] && x <= 80) {
			window2.setPixelColor(x, COLOR_YELLOW);
		} else {
			window2.setPixelColor(x, COLOR_OFF);
		}
	}

	for (unsigned int x = 0; x < WINDOW_LENGTH; x++) {
		if (x <= val[5] && x >= 9) {
			window3.setPixelColor(x, COLOR_VIOLET);
		} else if (x >= val[4] && x <= 80) {
			window3.setPixelColor(x, COLOR_BLUE);
		} else {
			window3.setPixelColor(x, COLOR_OFF);
		}
	}

	for (unsigned int x = 0; x < DESK2_LENGTH; x++) {
		if (x <= val[6]) {
			desk2.setPixelColor(x, COLOR_WHITE);
		} else {
			desk2.setPixelColor(x, COLOR_OFF);
		}
	}

	window1.show();
	window2.show();
	window3.show();
	desk2.show();
}

void Animation_Advanced_Audio_EqualizerWindow::clean() {}

/* ~~~ Animation Advanced Audio: Advanced Equalizer w/ Max ~~~ */

void Animation_Advanced_Audio_MaxEqualizerWindow::init() {
 	Animation_Advanced_Audio::init();
 	this->name = F("Window[all]: Audio Equalizer With Max");
	this->num_strips = 3;
 	this->strips = WINDOW_ALL;

	this->left_eq = device_manager.getDevice<MSGEQ7>(0);

	this->stack = new LocalStack();
	this->stack->push(new MemObj(new unsigned short int[7]));
	this->stack->push(new MemObj(new unsigned int(0)));

	unsigned short int* max = this->stack->get(0)->getpointer<unsigned short int>();

	max[0] = 80;
	max[1] = 9;
	max[2] = 80;
	max[3] = 9;
	max[4] = 80;
	max[5] = 9;
	max[6] = 0;
}

void Animation_Advanced_Audio_MaxEqualizerWindow::step() {
	unsigned short int* max = this->stack->get(0)->getpointer<unsigned short int>();
	unsigned int& count = this->stack->get(1)->get<unsigned int>();
	int val[7];

	val[0] = map(left_eq->get8Bit(0), 0, 255, 80, 50);
	val[1] = map(left_eq->get8Bit(1), 0, 255, 9, 40);
	val[2] = map(left_eq->get8Bit(2), 0, 255, 80, 50);
	val[3] = map(left_eq->get8Bit(3), 0, 255, 9, 40);
	val[4] = map(left_eq->get8Bit(4), 0, 255, 80, 50);
	val[5] = map(left_eq->get8Bit(5), 0, 255, 9, 40);
	val[6] = map(left_eq->get8Bit(6), 0, 255, 0, 29);

	for (int i = 0; i < 7; i++) {
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

	for (int x = 0; x < WINDOW_LENGTH; x++) {
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

	for (int x = 0; x < WINDOW_LENGTH; x++) {
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

	for (int x = 0; x < WINDOW_LENGTH; x++) {
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

	for (int x = 0; x < 29; x++) {
		if (x <= val[6]) {
			desk2.setPixelColor(x, COLOR_WHITE);
		} else {
			desk2.setPixelColor(x, COLOR_OFF);
		}

		if (x == max[6]) {
			desk2.setPixelColor(x, COLOR_RED);
		}
	}

	if (count >= 15) {
		count = 0;

		for (int i = 0; i < 7; i++) {
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

	window1.show();
	window2.show();
	window3.show();
	desk2.show();
}

void Animation_Advanced_Audio_MaxEqualizerWindow::clean() {
	this->stack->get(0)->destroyarray<unsigned short int>();
	this->stack->get(1)->destroy<unsigned int>();

	delete this->stack;
}
