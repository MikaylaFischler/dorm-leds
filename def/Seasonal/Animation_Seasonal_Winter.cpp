#include "Animation_Seasonal.hpp"

/* ~~~ Animation Seasonal Winter: Generic Functions */

void Animation_Seasonal_Winter_Snow::init() {
	this->stack = new LocalStack();
	this->stack->push(new MemObj(new unsigned short int(0)));
	this->stack->push(new MemObj(new bool(true)));
	this->stack->push(new MemObj(new unsigned short int(0)));
	this->stack->push(new MemObj(new unsigned short int(0)));
}

void Animation_Seasonal_Winter_Snow::snow_step(Adafruit_NeoPixel& strip) {
	unsigned short int& i = this->stack->get(0)->get<unsigned short int>();
	bool& mode = this->stack->get(1)->get<bool>();
	unsigned short int& left = this->stack->get(2)->get<unsigned short int>();
	unsigned short int& right = this->stack->get(3)->get<unsigned short int>();

	if (mode == 0) {
		// randomize
		left = random(3,8);
		right = random(3,8);

		// snow fall
		this->snow(strip, i, left, right);

		mode = 1;
	} else if (mode == 1) {
		// snow fall
		this->snow(strip, i, left, right);

		i++;

		// 40 for a loop one direction, 80 for a full forwards and backwards
		if (i == 800) {
			i = 0;
			mode = 0;
			this->current_exec++;
		}
	}
}

void Animation_Seasonal_Winter_Snow::snow(Adafruit_NeoPixel& strip, unsigned int i, unsigned short int left_spacing, unsigned short int right_spacing) {
	// let it snooww
	// let it snowwwww
	// let it snowwwwwwwwww
	int rightBottom = 9;
	int rightTop = 40;
	int leftTop = 50;
	int leftBottom = 80;

	unsigned long int on  = window_generic.Color(100,100,100);

	// set each right pixel
	for (int x = rightBottom; x <= rightTop; x++) {
		int rel_index = x - rightBottom;

		if (rel_index % right_spacing == (1000 - i) % right_spacing) {
			strip.setPixelColor(x, on);
		} else {
			strip.setPixelColor(x, COLOR_OFF);
		}
	}

	// set each left pixel
	for (int x = leftTop; x <= leftBottom; x++){
		int rel_index = x - leftTop;

		if (rel_index % left_spacing == i % left_spacing) {
			strip.setPixelColor(x, on);
		} else {
			strip.setPixelColor(x, COLOR_OFF);
		}
	}

	strip.show();
}

void Animation_Seasonal_Winter_Snow::clean() {
	this->stack->get(0)->destroy<unsigned short int>();
	this->stack->get(1)->destroy<bool>();
	this->stack->get(2)->destroy<unsigned short int>();
	this->stack->get(3)->destroy<unsigned short int>();

	delete this->stack;
}

/* ~~~ Animation Seasonal Winter: Window 1 Randomized Snow Animation ~~~ */

void Animation_Seasonal_Winter_Snow_Win1::init() {
 	Animation_Seasonal_Winter_Snow::init();
 	this->name = F("Window[1]: Randomized Snow");
	this->num_strips = 1;
 	this->strips = WINDOW_1;
}

void Animation_Seasonal_Winter_Snow_Win1::step() {
	this->snow_step(window1);
}

/* ~~~ Animation Seasonal Winter: Window 2 Randomized Snow Animation ~~~ */

void Animation_Seasonal_Winter_Snow_Win2::init() {
 	Animation_Seasonal_Winter_Snow::init();
 	this->name = F("Window[2]: Randomized Snow");
	this->num_strips = 1;
 	this->strips = WINDOW_2;
}

void Animation_Seasonal_Winter_Snow_Win2::step() {
	this->snow_step(window2);
}

/* ~~~ Animation Seasonal Winter: Window 3 Randomized Snow Animation ~~~ */

void Animation_Seasonal_Winter_Snow_Win3::init() {
 	Animation_Seasonal_Winter_Snow::init();
 	this->name = F("Window[3]: Randomized Snow");
	this->num_strips = 1;
 	this->strips = WINDOW_3;
}

void Animation_Seasonal_Winter_Snow_Win3::step() {
	this->snow_step(window3);
}
