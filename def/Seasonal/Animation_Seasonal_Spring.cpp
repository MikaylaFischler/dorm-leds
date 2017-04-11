#include "Animation_Seasonal.hpp"

/* ~~~ Animation Seasonal Spring: Window Spring Colors */

void Animation_Seasonal_Spring_WindowColors::init() {
 	Animation_Seasonal::init();
	this->name = F("Window[all]: Spring Colors");
	this->update_rate = 5;
	this->num_strips = 3;
    this->strips = WINDOW_ALL;

	this->stack = new LocalStack();
	this->stack->push(new MemObj(new unsigned int(0)));
	this->stack->push(new MemObj(new unsigned short int[3]));
	this->stack->push(new MemObj(new bool(true)));

	// initialize values
	unsigned short int* colors = this->stack->get(1)->getpointer<unsigned short int>();
	colors[0] = random(0,3);
	colors[1] = random(0,3);
	colors[2] = random(0,3);
}

void Animation_Seasonal_Spring_WindowColors::step() {
	unsigned int& i = this->stack->get(0)->get<unsigned int>();
	unsigned short int* colors = this->stack->get(1)->getpointer<unsigned short int>();
	bool& increasing = this->stack->get(2)->get<bool>();

	// step animation
	for (unsigned int s = 0; s < 3; s++) {
		// update each window strip
		unsigned long int c = 0;

		switch (colors[s]) {
			case 0: // yellow
				c = Color(i, round(150.0 * (i / 255.0)), 0);
				break;
			case 1: // green
				c = Color(0, i, 0);
				break;
			case 2: // sky blue
				c = Color(0, i, round(230.0 * (i / 255.0)));
				break;
		}

		for (unsigned int x = 0; x < WINDOW_LENGTH; x++) {
			window[s]->setPixelColor(x, c);
		}
	}

	showAllWindowStrips();

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
			colors[0] = random(0,3);
			colors[1] = random(0,3);
			colors[2] = random(0,3);

      		this->current_exec++;
		} else {
			i--;
		}
	}
}

void Animation_Seasonal_Spring_WindowColors::clean() {
	this->stack->get(0)->destroy<unsigned int>();
	this->stack->get(1)->destroyarray<unsigned short int>();
	this->stack->get(2)->destroy<bool>();

	delete this->stack;
}

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
