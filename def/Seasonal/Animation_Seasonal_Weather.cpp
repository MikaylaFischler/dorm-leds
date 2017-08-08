#include "Animation_Seasonal.hpp"

/* ~~~~~ PRECIPITATION ~~~~~ */

void Animation_Seasonal_Indiv_Weather::precipitation_init(int update_rate) {
 	Animation_Seasonal_Indiv::init();
	this->name = getNameOfStrip(this->strip);
	this->update_rate = update_rate;
	this->strips = getAsStripArray(this->strip);

	i = 0;
	randomized_spacing = false;
	left_spacing = 0;
	right_spacing = 0;
}

void Animation_Seasonal_Indiv_Weather::precipitation_step(int min_spacing, int max_spacing, long unsigned int color) {
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

/* ~~~~~ RAIN ~~~~~ */

/* ~~~ Animation Seasonal Individual Weather: Randomized Window Light Rain */

void Animation_Seasonal_Indiv_Weather_WindowLightRain::init() {
	precipitation_init(50);
 	this->name += F(": Light Rain");
}

void Animation_Seasonal_Indiv_Weather_WindowLightRain::step() {
	precipitation_step(7, 10, COLOR_RAINY_BLUE);
}

/* ~~~ Animation Seasonal Individual Weather: Randomized Window Rain */

void Animation_Seasonal_Indiv_Weather_WindowRain::init() {
	precipitation_init(40);
 	this->name += F(": Rain");
}

void Animation_Seasonal_Indiv_Weather_WindowRain::step() {
	precipitation_step(5, 8, COLOR_RAINY_BLUE);
}

/* ~~~ Animation Seasonal Individual Weather: Randomized Heavy Window Rain */

void Animation_Seasonal_Indiv_Weather_WindowHeavyRain::init() {
	precipitation_init(40);
 	this->name += F(": Heavy Rain");
}

void Animation_Seasonal_Indiv_Weather_WindowHeavyRain::step() {
	precipitation_step(4, 6, COLOR_RAINY_BLUE);
}

/* ~~~~~ SNOW ~~~~~ */

/* ~~~ Animation Seasonal Individual Weather: Randomized Light Snow */

void Animation_Seasonal_Indiv_Weather_WindowLightSnow::init() {
	precipitation_init(90);
 	this->name += F(": Light Snow");
}

void Animation_Seasonal_Indiv_Weather_WindowLightSnow::step() {
	precipitation_step(7, 10, COLOR_DIM_WHITE);
}

/* ~~~ Animation Seasonal Individual Weather: Randomized Snow */

void Animation_Seasonal_Indiv_Weather_WindowSnow::init() {
	precipitation_init(80);
 	this->name += F(": Snow");
}

void Animation_Seasonal_Indiv_Weather_WindowSnow::step() {
	precipitation_step(4, 8, COLOR_DIM_WHITE);
}

/* ~~~ Animation Seasonal Individual Weather: Randomized Heavy Snow */

void Animation_Seasonal_Indiv_Weather_WindowHeavySnow::init() {
	precipitation_init(60);
 	this->name += F(": Heavy Snow");
}

void Animation_Seasonal_Indiv_Weather_WindowHeavySnow::step() {
	precipitation_step(3, 5, COLOR_DIM_WHITE);
}
