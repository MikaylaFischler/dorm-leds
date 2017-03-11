#include "Animation_Advanced.hpp"

/* ~~~ Generic Advanced Audio ~~~ */

// define the generic advanced audio init
void Animation_Advanced_Audio::init() {
  	Animation_Advanced::init();
    this->update_rate = 1; // at rate of audio update
}

/* ~~~ Animation Advanced Audio: Beat Window Pulse ~~~ */

void Animation_Advanced_Audio_BeatWindowPulse::init() {
 	Animation_Advanced_Audio::init();
 	this->name = F("Window[all]: Audio Beat Pulse");
	this->num_strips = 3;
 	this->strips = WINDOW_ALL;

	this->left_eq = device_manager.getDevice<MSGEQ7>(0);
}

void Animation_Advanced_Audio_BeatWindowPulse::step() {
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
	//window1.show();
	//window3.show();

	// center window (highs) (top 4)
	for (int x = 0; x < WINDOW_LENGTH; x++) {
		window2.setPixelColor(x, high_sum, high_sum, high_sum);
	}
	//window2.show();

}

void Animation_Advanced_Audio_BeatWindowPulse::clean() {}
