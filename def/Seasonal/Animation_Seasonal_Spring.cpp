#include "Animation_Seasonal.hpp"

/* ~~~ Animation Seasonal Individual Spring: Clear Sky Blue Color Fade */

Animation_Seasonal_Indiv_Spring_ClearSkyFade::Animation_Seasonal_Indiv_Spring_ClearSkyFade(Adafruit_NeoPixel* strip) {
	this->strip = strip;
}

void Animation_Seasonal_Indiv_Spring_ClearSkyFade::init() {
 	Animation_Seasonal_Indiv::init();
	this->name = getNameOfStrip(this->strip);
 	this->name += F(": Clear Skies");
	this->update_rate = 50;
	this->strips = getAsStripArray(this->strip);

	this->stack = new LocalStack();
	this->stack->push(new MemObj(new unsigned int(0)));
	this->stack->push(new MemObj(new bool(true)));
}

void Animation_Seasonal_Indiv_Spring_ClearSkyFade::step() {
	static const int MAX_RED = 200;
	static const int MAX_GREEN = 180;
	static const int BLUE = 255;

	unsigned int& i = this->stack->get(0)->get<unsigned int>();
	bool& increasing = this->stack->get(1)->get<bool>();

	// step animation
	for (unsigned int x = 0; x < this->strip->numPixels(); x++) {
		this->strip->setPixelColor(x, MAX_RED - i, MAX_GREEN - i, BLUE);
	}

	this->strip->show();

	if (increasing) {
		if (i >= 150) {
			i--;
			increasing = false;
		} else {
			i++;
		}
	} else {
		if (i <= 0) {
			i++;
			increasing = true;
      		this->current_exec++;
		} else {
			i--;
		}
	}

}

void Animation_Seasonal_Indiv_Spring_ClearSkyFade::clean() {
	this->stack->get(0)->destroy<unsigned int>();
	this->stack->get(1)->destroy<bool>();

	delete this->stack;
}

/* ~~~ Animation Seasonal Spring: Window Spring Colors */

Animation_Seasonal_Indiv_Spring_WindowColors::Animation_Seasonal_Indiv_Spring_WindowColors(Adafruit_NeoPixel* strip) {
	this->strip = strip;
}

void Animation_Seasonal_Indiv_Spring_WindowColors::init() {
 	Animation_Seasonal_Indiv::init();
	this->name = getNameOfStrip(this->strip);
 	this->name += F(": Spring Colors");
	this->update_rate = 5;
	this->strips = getAsStripArray(this->strip);

	this->stack = new LocalStack();
	this->stack->push(new MemObj(new unsigned int(0)));
	this->stack->push(new MemObj(new unsigned short int(random(0,4))));
	this->stack->push(new MemObj(new bool(true)));
}

void Animation_Seasonal_Indiv_Spring_WindowColors::step() {
	unsigned int& i = this->stack->get(0)->get<unsigned int>();
	unsigned short int& color = this->stack->get(1)->get<unsigned short int>();
	bool& increasing = this->stack->get(2)->get<bool>();

	// step animation
	unsigned long int c = 0;

	switch (color) {
		case 0: // violet
			c = Color(round(175.0 * (i / 255.0)), 0, i);
			break;
		case 1: // yellow
			c = Color(i, round(150.0 * (i / 255.0)), 0);
			break;
		case 2: // green
			c = Color(0, i, 0);
			break;
		case 3: // sky blue
			c = Color(0, i, round(230.0 * (i / 255.0)));
			break;
	}

	for (unsigned int x = 0; x < WINDOW_LENGTH; x++) {
		this->strip->setPixelColor(x, c);
	}

	this->strip->show();

	if (increasing) {
		if (i >= 255) {
			i--;
			increasing = false;
		} else {
			i++;
		}
	} else {
		if (i <= 0) {
			i++;
			increasing = true;

			// re-randomize
			color = random(0,4);

      		this->current_exec++;
		} else {
			i--;
		}
	}
}

void Animation_Seasonal_Indiv_Spring_WindowColors::clean() {
	this->stack->get(0)->destroy<unsigned int>();
	this->stack->get(1)->destroy<unsigned short int>();
	this->stack->get(2)->destroy<bool>();

	delete this->stack;
}

/* ~~~ Animation Seasonal Individual Spring: Spring Color Chase */

Animation_Seasonal_Indiv_Spring_ColorWipe::Animation_Seasonal_Indiv_Spring_ColorWipe(Adafruit_NeoPixel* strip) {
	this->strip = strip;
}

void Animation_Seasonal_Indiv_Spring_ColorWipe::init() {
 	Animation_Seasonal_Indiv::init();
	this->name = getNameOfStrip(this->strip);
 	this->name += F(": Spring Color Fade");
	this->update_rate = 35;
	this->strips = getAsStripArray(this->strip);

	this->stack = new LocalStack();
	this->stack->push(new MemObj(new unsigned short int(0)));
	this->stack->push(new MemObj(new unsigned short int(0)));
}

void Animation_Seasonal_Indiv_Spring_ColorWipe::step() {
	unsigned short int& i = this->stack->get(0)->get<unsigned short int>();
	unsigned short int& color_mode = this->stack->get(1)->get<unsigned short int>();

	// start wiping the current color
	if (color_mode == 0) {
		this->strip->setPixelColor(i, COLOR_VIOLET);
	} else if (color_mode == 1) {
		this->strip->setPixelColor(i, COLOR_YELLOW);
	} else if (color_mode == 2) {
		this->strip->setPixelColor(i, COLOR_GREEN);
	} else if (color_mode == 3) {
		this->strip->setPixelColor(i, COLOR_LIGHT_BLUE_GREEN);
	}

    this->strip->show();

    i++;

	if (i == this->strip->numPixels()) {
		color_mode++;
		i = 0;

		if (color_mode == 4) {
			color_mode = 0;
			this->current_exec++;
		}
	}
}

void Animation_Seasonal_Indiv_Spring_ColorWipe::clean() {
	this->stack->get(0)->destroy<unsigned short int>();
	this->stack->get(1)->destroy<unsigned short int>();

	delete this->stack;
}
