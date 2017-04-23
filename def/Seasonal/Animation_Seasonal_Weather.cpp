#include "Animation_Seasonal.hpp"

/* ~~~~~ PRECIPITATION ~~~~~ */

void Animation_Seasonal_Indiv_Weather::precipitation_init(int update_rate) {
 	Animation_Seasonal_Indiv::init();
	this->name = getNameOfStrip(this->strip);
	this->update_rate = update_rate;
	this->strips = getAsStripArray(this->strip);

	this->stack = new LocalStack();
	this->stack->push(new MemObj(new unsigned int(0)));
	this->stack->push(new MemObj(new bool(false)));
	this->stack->push(new MemObj(new unsigned short int(0)));
	this->stack->push(new MemObj(new unsigned short int(0)));
}

void Animation_Seasonal_Indiv_Weather::precipitation_step(int min_spacing, int max_spacing, long unsigned int color) {
	unsigned int& i = this->stack->get(0)->get<unsigned int>();
	bool& randomized_spacing = this->stack->get(1)->get<bool>();
	unsigned short int& left_spacing = this->stack->get(2)->get<unsigned short int>();
	unsigned short int& right_spacing = this->stack->get(3)->get<unsigned short int>();

	if (!randomized_spacing) {
		// randomize spacing
		left_spacing = random(min_spacing, max_spacing);
		right_spacing = random(min_spacing, max_spacing);
		randomized_spacing = true;
	}

	// precipitation fall
	// set each right pixel
	for (int x = WINDOW_BOTTOM_RIGHT; x <= WINDOW_TOP_RIGHT; x++) {
		int rel_index = x - WINDOW_BOTTOM_RIGHT;

		if (rel_index % right_spacing == (1000 - i) % right_spacing) {
			this->strip->setPixelColor(x, color);
		} else {
			this->strip->setPixelColor(x, COLOR_OFF);
		}
	}

	// set each left pixel
	for (int x = WINDOW_TOP_LEFT; x <= WINDOW_BOTTOM_LEFT; x++){
		int rel_index = x - WINDOW_TOP_LEFT;

		if (rel_index % left_spacing == i % left_spacing) {
			this->strip->setPixelColor(x, color);
		} else {
			this->strip->setPixelColor(x, COLOR_OFF);
		}
	}

	this->strip->show();

	if (randomized_spacing) {
		i++;

		if (i == 800) {
			// 40 for a loop one direction, 80 for a full forwards and backwards
			i = 0;
			randomized_spacing = false;
			this->current_exec++;
		}
	}
}

void Animation_Seasonal_Indiv_Weather::precipitation_clean() {
	this->stack->get(0)->destroy<unsigned int>();
	this->stack->get(1)->destroy<bool>();
	this->stack->get(2)->destroy<unsigned short int>();
	this->stack->get(3)->destroy<unsigned short int>();

	delete this->stack;
}

/* ~~~~~ RAIN ~~~~~ */

/* ~~~ Animation Seasonal Individual Weather: Randomized Window Light Rain */

Animation_Seasonal_Indiv_Weather_WindowLightRain::Animation_Seasonal_Indiv_Weather_WindowLightRain(Adafruit_NeoPixel* strip) {
	this->strip = strip;
}

void Animation_Seasonal_Indiv_Weather_WindowLightRain::init() {
	precipitation_init(50);
 	this->name += F(": Light Rain");
}

void Animation_Seasonal_Indiv_Weather_WindowLightRain::step() {
	precipitation_step(7, 10, COLOR_RAINY_BLUE);
}

void Animation_Seasonal_Indiv_Weather_WindowLightRain::clean() {
	precipitation_clean();
}

/* ~~~ Animation Seasonal Individual Weather: Randomized Window Rain */

Animation_Seasonal_Indiv_Weather_WindowRain::Animation_Seasonal_Indiv_Weather_WindowRain(Adafruit_NeoPixel* strip) {
	this->strip = strip;
}

void Animation_Seasonal_Indiv_Weather_WindowRain::init() {
	precipitation_init(40);
 	this->name += F(": Rain");
}

void Animation_Seasonal_Indiv_Weather_WindowRain::step() {
	precipitation_step(5, 8, COLOR_RAINY_BLUE);
}

void Animation_Seasonal_Indiv_Weather_WindowRain::clean() {
	precipitation_clean();
}

/* ~~~ Animation Seasonal Individual Weather: Randomized Heavy Window Rain */

Animation_Seasonal_Indiv_Weather_WindowHeavyRain::Animation_Seasonal_Indiv_Weather_WindowHeavyRain(Adafruit_NeoPixel* strip) {
	this->strip = strip;
}

void Animation_Seasonal_Indiv_Weather_WindowHeavyRain::init() {
	precipitation_init(40);
 	this->name += F(": Heavy Rain");
}

void Animation_Seasonal_Indiv_Weather_WindowHeavyRain::step() {
	precipitation_step(4, 6, COLOR_RAINY_BLUE);
}

void Animation_Seasonal_Indiv_Weather_WindowHeavyRain::clean() {
	precipitation_clean();
}

/* ~~~~~ SNOW ~~~~~ */

/* ~~~ Animation Seasonal Individual Weather: Randomized Light Snow */

Animation_Seasonal_Indiv_Weather_WindowLightSnow::Animation_Seasonal_Indiv_Weather_WindowLightSnow(Adafruit_NeoPixel* strip) {
	this->strip = strip;
}

void Animation_Seasonal_Indiv_Weather_WindowLightSnow::init() {
	precipitation_init(90);
 	this->name += F(": Light Snow");
}

void Animation_Seasonal_Indiv_Weather_WindowLightSnow::step() {
	precipitation_step(7, 10, COLOR_DIM_WHITE);
}

void Animation_Seasonal_Indiv_Weather_WindowLightSnow::clean() {
	precipitation_clean();
}

/* ~~~ Animation Seasonal Individual Weather: Randomized Snow */

Animation_Seasonal_Indiv_Weather_WindowSnow::Animation_Seasonal_Indiv_Weather_WindowSnow(Adafruit_NeoPixel* strip) {
	this->strip = strip;
}

void Animation_Seasonal_Indiv_Weather_WindowSnow::init() {
	precipitation_init(80);
 	this->name += F(": Snow");
}

void Animation_Seasonal_Indiv_Weather_WindowSnow::step() {
	precipitation_step(4, 8, COLOR_DIM_WHITE);
}

void Animation_Seasonal_Indiv_Weather_WindowSnow::clean() {
	precipitation_clean();
}

/* ~~~ Animation Seasonal Individual Weather: Randomized Heavy Snow */

Animation_Seasonal_Indiv_Weather_WindowHeavySnow::Animation_Seasonal_Indiv_Weather_WindowHeavySnow(Adafruit_NeoPixel* strip) {
	this->strip = strip;
}

void Animation_Seasonal_Indiv_Weather_WindowHeavySnow::init() {
	precipitation_init(60);
 	this->name += F(": Heavy Snow");
}

void Animation_Seasonal_Indiv_Weather_WindowHeavySnow::step() {
	precipitation_step(3, 5, COLOR_DIM_WHITE);
}

void Animation_Seasonal_Indiv_Weather_WindowHeavySnow::clean() {
	precipitation_clean();
}
