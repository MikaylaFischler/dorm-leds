#include "Animation_Seasonal.hpp"

/* ~~~~~ RAIN ~~~~~ */

/* ~~~ Animation Seasonal Individual Weather: Randomized Window Light Rain */

Animation_Seasonal_Indiv_Weather_WindowLightRain::Animation_Seasonal_Indiv_Weather_WindowLightRain(Adafruit_NeoPixel* strip) {
	this->strip = strip;
}

void Animation_Seasonal_Indiv_Weather_WindowLightRain::init() {
 	Animation_Seasonal_Indiv::init();
	this->name = getNameOfStrip(this->strip);
 	this->name += F(": Light Rain");
	this->update_rate = 50;
	this->strips = getAsStripArray(this->strip);

	this->stack = new LocalStack();
	this->stack->push(new MemObj(new unsigned int(0)));
	this->stack->push(new MemObj(new bool(false)));
	this->stack->push(new MemObj(new unsigned short int(0)));
	this->stack->push(new MemObj(new unsigned short int(0)));
}

void Animation_Seasonal_Indiv_Weather_WindowLightRain::step() {
	unsigned int& i = this->stack->get(0)->get<unsigned int>();
	bool& randomized_spacing = this->stack->get(1)->get<bool>();
	unsigned short int& left_spacing = this->stack->get(2)->get<unsigned short int>();
	unsigned short int& right_spacing = this->stack->get(3)->get<unsigned short int>();

	if (!randomized_spacing) {
		// randomize spacing
		left_spacing = random(7,10);
		right_spacing = random(7,10);
		randomized_spacing = true;
	}

	// rain fall
	// set each right pixel
	for (int x = WINDOW_BOTTOM_RIGHT; x <= WINDOW_TOP_RIGHT; x++) {
		int rel_index = x - WINDOW_BOTTOM_RIGHT;

		if (rel_index % right_spacing == (1000 - i) % right_spacing) {
			this->strip->setPixelColor(x, COLOR_RAINY_BLUE);
		} else {
			this->strip->setPixelColor(x, COLOR_OFF);
		}
	}

	// set each left pixel
	for (int x = WINDOW_TOP_LEFT; x <= WINDOW_BOTTOM_LEFT; x++){
		int rel_index = x - WINDOW_TOP_LEFT;

		if (rel_index % left_spacing == i % left_spacing) {
			this->strip->setPixelColor(x, COLOR_RAINY_BLUE);
		} else {
			this->strip->setPixelColor(x, COLOR_OFF);
		}
	}

	this->strip->show();

	if (randomized_spacing) {
		i++;

		// 40 for a loop one direction, 80 for a full forwards and backwards
		if (i == 800) {
			i = 0;
			randomized_spacing = false;
			this->current_exec++;
		}
	}
}

void Animation_Seasonal_Indiv_Weather_WindowLightRain::clean() {
	this->stack->get(0)->destroy<unsigned int>();
	this->stack->get(1)->destroy<bool>();
	this->stack->get(2)->destroy<unsigned short int>();
	this->stack->get(3)->destroy<unsigned short int>();

	delete this->stack;
}

/* ~~~ Animation Seasonal Individual Weather: Randomized Window Rain */

Animation_Seasonal_Indiv_Weather_WindowRain::Animation_Seasonal_Indiv_Weather_WindowRain(Adafruit_NeoPixel* strip) {
	this->strip = strip;
}

void Animation_Seasonal_Indiv_Weather_WindowRain::init() {
 	Animation_Seasonal_Indiv::init();
	this->name = getNameOfStrip(this->strip);
 	this->name += F(": Heavy Rain");
	this->update_rate = 40;
	this->strips = getAsStripArray(this->strip);

	this->stack = new LocalStack();
	this->stack->push(new MemObj(new unsigned int(0)));
	this->stack->push(new MemObj(new bool(false)));
	this->stack->push(new MemObj(new unsigned short int(0)));
	this->stack->push(new MemObj(new unsigned short int(0)));
}

void Animation_Seasonal_Indiv_Weather_WindowRain::step() {
	unsigned int& i = this->stack->get(0)->get<unsigned int>();
	bool& randomized_spacing = this->stack->get(1)->get<bool>();
	unsigned short int& left_spacing = this->stack->get(2)->get<unsigned short int>();
	unsigned short int& right_spacing = this->stack->get(3)->get<unsigned short int>();

	if (!randomized_spacing) {
		// randomize spacing
		left_spacing = random(4,6);
		right_spacing = random(4,6);
		randomized_spacing = true;
	}

	// rain fall
	// set each right pixel
	for (int x = WINDOW_BOTTOM_RIGHT; x <= WINDOW_TOP_RIGHT; x++) {
		int rel_index = x - WINDOW_BOTTOM_RIGHT;

		if (rel_index % right_spacing == (1000 - i) % right_spacing) {
			this->strip->setPixelColor(x, COLOR_RAINY_BLUE);
		} else {
			this->strip->setPixelColor(x, COLOR_OFF);
		}
	}

	// set each left pixel
	for (int x = WINDOW_TOP_LEFT; x <= WINDOW_BOTTOM_LEFT; x++){
		int rel_index = x - WINDOW_TOP_LEFT;

		if (rel_index % left_spacing == i % left_spacing) {
			this->strip->setPixelColor(x, COLOR_RAINY_BLUE);
		} else {
			this->strip->setPixelColor(x, COLOR_OFF);
		}
	}

	this->strip->show();

	if (randomized_spacing) {
		i++;

		// 40 for a loop one direction, 80 for a full forwards and backwards
		if (i == 800) {
			i = 0;
			randomized_spacing = false;
			this->current_exec++;
		}
	}
}

void Animation_Seasonal_Indiv_Weather_WindowRain::clean() {
	this->stack->get(0)->destroy<unsigned int>();
	this->stack->get(1)->destroy<bool>();
	this->stack->get(2)->destroy<unsigned short int>();
	this->stack->get(3)->destroy<unsigned short int>();

	delete this->stack;
}

/* ~~~~~ SNOW ~~~~~ */

/* ~~~ Animation Seasonal Individual Weather: Randomized Light Snow */

Animation_Seasonal_Indiv_Weather_WindowLightSnow::Animation_Seasonal_Indiv_Weather_WindowLightSnow(Adafruit_NeoPixel* strip) {
	this->strip = strip;
}

void Animation_Seasonal_Indiv_Weather_WindowLightSnow::init() {
 	Animation_Seasonal_Indiv::init();
	this->name = getNameOfStrip(this->strip);
 	this->name += F(": Randomized Snow");
	this->update_rate = 90;
	this->strips = getAsStripArray(this->strip);

	this->stack = new LocalStack();
	this->stack->push(new MemObj(new unsigned int(0)));
	this->stack->push(new MemObj(new bool(false)));
	this->stack->push(new MemObj(new unsigned short int(0)));
	this->stack->push(new MemObj(new unsigned short int(0)));
}

void Animation_Seasonal_Indiv_Weather_WindowLightSnow::step() {
	unsigned int& i = this->stack->get(0)->get<unsigned int>();
	bool& randomized_spacing = this->stack->get(1)->get<bool>();
	unsigned short int& left_spacing = this->stack->get(2)->get<unsigned short int>();
	unsigned short int& right_spacing = this->stack->get(3)->get<unsigned short int>();

	if (!randomized_spacing) {
		// randomize spacing
		left_spacing = random(7,10);
		right_spacing = random(7,10);
		randomized_spacing = true;
	}

	// snow fall
	// set each right pixel
	for (int x = WINDOW_BOTTOM_RIGHT; x <= WINDOW_TOP_RIGHT; x++) {
		int rel_index = x - WINDOW_BOTTOM_RIGHT;

		if (rel_index % right_spacing == (1000 - i) % right_spacing) {
			this->strip->setPixelColor(x, COLOR_DIM_WHITE);
		} else {
			this->strip->setPixelColor(x, COLOR_OFF);
		}
	}

	// set each left pixel
	for (int x = WINDOW_TOP_LEFT; x <= WINDOW_BOTTOM_LEFT; x++){
		int rel_index = x - WINDOW_TOP_LEFT;

		if (rel_index % left_spacing == i % left_spacing) {
			this->strip->setPixelColor(x, COLOR_DIM_WHITE);
		} else {
			this->strip->setPixelColor(x, COLOR_OFF);
		}
	}

	this->strip->show();

	if (randomized_spacing) {
		i++;

		// 40 for a loop one direction, 80 for a full forwards and backwards
		if (i == 800) {
			i = 0;
			randomized_spacing = false;
			this->current_exec++;
		}
	}
}

void Animation_Seasonal_Indiv_Weather_WindowLightSnow::clean() {
	this->stack->get(0)->destroy<unsigned int>();
	this->stack->get(1)->destroy<bool>();
	this->stack->get(2)->destroy<unsigned short int>();
	this->stack->get(3)->destroy<unsigned short int>();

	delete this->stack;
}

/* ~~~ Animation Seasonal Individual Weather: Randomized Snow */

Animation_Seasonal_Indiv_Weather_WindowSnow::Animation_Seasonal_Indiv_Weather_WindowSnow(Adafruit_NeoPixel* strip) {
	this->strip = strip;
}

void Animation_Seasonal_Indiv_Weather_WindowSnow::init() {
 	Animation_Seasonal_Indiv::init();
	this->name = getNameOfStrip(this->strip);
 	this->name += F(": Randomized Snow");
	this->update_rate = 80;
	this->strips = getAsStripArray(this->strip);

	this->stack = new LocalStack();
	this->stack->push(new MemObj(new unsigned int(0)));
	this->stack->push(new MemObj(new bool(false)));
	this->stack->push(new MemObj(new unsigned short int(0)));
	this->stack->push(new MemObj(new unsigned short int(0)));
}

void Animation_Seasonal_Indiv_Weather_WindowSnow::step() {
	unsigned int& i = this->stack->get(0)->get<unsigned int>();
	bool& randomized_spacing = this->stack->get(1)->get<bool>();
	unsigned short int& left_spacing = this->stack->get(2)->get<unsigned short int>();
	unsigned short int& right_spacing = this->stack->get(3)->get<unsigned short int>();

	if (!randomized_spacing) {
		// randomize spacing
		left_spacing = random(3,8);
		right_spacing = random(3,8);
		randomized_spacing = true;
	}

	// snow fall
	// set each right pixel
	for (int x = WINDOW_BOTTOM_RIGHT; x <= WINDOW_TOP_RIGHT; x++) {
		int rel_index = x - WINDOW_BOTTOM_RIGHT;

		if (rel_index % right_spacing == (1000 - i) % right_spacing) {
			this->strip->setPixelColor(x, COLOR_DIM_WHITE);
		} else {
			this->strip->setPixelColor(x, COLOR_OFF);
		}
	}

	// set each left pixel
	for (int x = WINDOW_TOP_LEFT; x <= WINDOW_BOTTOM_LEFT; x++){
		int rel_index = x - WINDOW_TOP_LEFT;

		if (rel_index % left_spacing == i % left_spacing) {
			this->strip->setPixelColor(x, COLOR_DIM_WHITE);
		} else {
			this->strip->setPixelColor(x, COLOR_OFF);
		}
	}

	this->strip->show();

	if (randomized_spacing) {
		i++;

		// 40 for a loop one direction, 80 for a full forwards and backwards
		if (i == 800) {
			i = 0;
			randomized_spacing = false;
			this->current_exec++;
		}
	}
}

void Animation_Seasonal_Indiv_Weather_WindowSnow::clean() {
	this->stack->get(0)->destroy<unsigned int>();
	this->stack->get(1)->destroy<bool>();
	this->stack->get(2)->destroy<unsigned short int>();
	this->stack->get(3)->destroy<unsigned short int>();

	delete this->stack;
}
