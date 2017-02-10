#include "Animation_Simple.hpp"

/* ~~~ Animation Simple Individual: Rainbow ~~~ */

Animation_Simple_Indiv_Rainbow::Animation_Simple_Indiv_Rainbow(Adafruit_NeoPixel* strip) {
	this->strip = strip;
}

void Animation_Simple_Indiv_Rainbow::init() {
	Animation_Simple_Indiv::init();
	this->name = getNameOfStrip(this->strip);
	this->name += F(": Rainbow");
    this->update_rate = 50;
	this->strips = getAsStripArray(this->strip);

	this->stack = new LocalStack();
	this->stack->push(new MemObj(new unsigned short int(0)));
}

void Animation_Simple_Indiv_Rainbow::step() {
	unsigned short int& i = this->stack->get(0)->get<unsigned short int>();

	// set each led to the proper color
	for (unsigned int j = 0; j < this->strip->numPixels(); j++) {
		this->strip->setPixelColor(j, ColorWheel((i + j) & 255));
	}

	this->strip->show();

	if (i == 255) {
		i = 0;
		this->current_exec++;
	} else {
		i++;
	}
}

void Animation_Simple_Indiv_Rainbow::clean() {
	this->stack->get(0)->destroy<unsigned short int>();

	delete this->stack;
}

/* ~~~ Animation Simple Individual: Rainbow Cycle ~~~ */

Animation_Simple_Indiv_RainbowCycle::Animation_Simple_Indiv_RainbowCycle(Adafruit_NeoPixel* strip) {
	this->strip = strip;
}

void Animation_Simple_Indiv_RainbowCycle::init() {
	Animation_Simple_Indiv::init();
	this->name = getNameOfStrip(this->strip);
	this->name += F(": Rainbow Cycle");
    this->update_rate = 50;
	this->strips = getAsStripArray(this->strip);

	this->stack = new LocalStack();
	this->stack->push(new MemObj(new unsigned short int(0)));
}

void Animation_Simple_Indiv_RainbowCycle::step() {
	unsigned short int& i = this->stack->get(0)->get<unsigned short int>();

	// set each led to the proper color
	for (unsigned int j = 0; j < this->strip->numPixels(); j++) {
		this->strip->setPixelColor(j, ColorWheel(((j * 256 / this->strip->numPixels()) + i) & 255));
	}

	this->strip->show();

	if (i == 255) {
		i = 0;
		this->current_exec++;
	} else {
		i++;
	}
}

void Animation_Simple_Indiv_RainbowCycle::clean() {
	this->stack->get(0)->destroy<unsigned short int>();

	delete this->stack;
}

/* ~~~ Animation Simple Individual: Rainbow Color Wipe ~~~ */

Animation_Simple_Indiv_RainbowWipe::Animation_Simple_Indiv_RainbowWipe(Adafruit_NeoPixel* strip) {
	this->strip = strip;
}

void Animation_Simple_Indiv_RainbowWipe::init() {
 	Animation_Simple_Indiv::init();
	this->name = getNameOfStrip(this->strip);
 	this->name += F(": Rainbow Color Wipe");
    this->update_rate = 50;
 	this->strips = getAsStripArray(this->strip);

	this->stack = new LocalStack();
	this->stack->push(new MemObj(new unsigned short int(0)));
	this->stack->push(new MemObj(new unsigned short int(0)));
}

void Animation_Simple_Indiv_RainbowWipe::step() {
	unsigned short int& i = this->stack->get(0)->get<unsigned short int>();
	unsigned short int& color_mode = this->stack->get(1)->get<unsigned short int>();

	// start wiping the current color
	if (color_mode % 2 != 0) {
		this->strip->setPixelColor(i, COLOR_OFF);
	} else if (color_mode == 0) {
		this->strip->setPixelColor(i, COLOR_RED);
	} else if (color_mode == 2) {
		this->strip->setPixelColor(i, COLOR_ORANGE);
	} else if (color_mode == 4) {
		this->strip->setPixelColor(i, COLOR_YELLOW);
	} else if (color_mode == 6) {
		this->strip->setPixelColor(i, COLOR_GREEN);
	} else if (color_mode == 8) {
		this->strip->setPixelColor(i, COLOR_LIGHT_BLUE_GREEN);
	} else if (color_mode == 10) {
		this->strip->setPixelColor(i, COLOR_BLUE);
	} else if (color_mode == 12) {
		this->strip->setPixelColor(i, COLOR_INDIGO);
	} else if (color_mode == 14) {
		this->strip->setPixelColor(i, COLOR_VIOLET);
	}

    this->strip->show();

    i++;

	if (i == this->strip->numPixels()) {
		color_mode++;
		i = 0;

		if (color_mode == 16) {
			color_mode = 0;
			this->current_exec++;
		}
	}
}

void Animation_Simple_Indiv_RainbowWipe::clean() {
	this->stack->get(0)->destroy<unsigned short int>();
	this->stack->get(1)->destroy<unsigned short int>();

	delete this->stack;
}

/* ~~~ Animation Simple Individual: Rainbow Theater Chase ~~~ */

Animation_Simple_Indiv_RainbowTheaterChase::Animation_Simple_Indiv_RainbowTheaterChase(Adafruit_NeoPixel* strip) {
	this->strip = strip;
}

void Animation_Simple_Indiv_RainbowTheaterChase::init() {
	Animation_Simple_Indiv::init();
	this->name = getNameOfStrip(this->strip);
	this->name += F(": Rainbow Theater Chase");
    this->update_rate = 35;
	this->strips = getAsStripArray(this->strip);

	this->stack = new LocalStack();
	this->stack->push(new MemObj(new unsigned short int(0)));
	this->stack->push(new MemObj(new unsigned short int(0)));
	this->stack->push(new MemObj(new bool(true)));
}

void Animation_Simple_Indiv_RainbowTheaterChase::step() {
	unsigned short int& q = this->stack->get(0)->get<unsigned short int>();
	unsigned short int& j = this->stack->get(1)->get<unsigned short int>();
	bool& alternate = this->stack->get(2)->get<bool>();

	if (alternate) {
		// set each led to the proper color
		for (unsigned int i = 0; i < this->strip->numPixels(); i = i + 3) {
			// turn every third pixel on
			this->strip->setPixelColor(i + q, ColorWheel((i + j) % 255));
		}

		this->strip->show();
	} else {
		for (unsigned int i = 0; i < this->strip->numPixels(); i = i + 3) {
			// turn every third pixel off
			this->strip->setPixelColor(i + q, COLOR_OFF);
		}
	}

	alternate = !alternate;

	if (j < 255 && alternate) {
		j++;
	} else if (j == 255 && alternate) {
		j = 0;
	}

	if (q < 2 && alternate) {
		q++;
	} else if (q == 2 && alternate) {
		q = 0;
		this->current_exec++;
	}
}

void Animation_Simple_Indiv_RainbowTheaterChase::clean() {
	this->stack->get(0)->destroy<unsigned short int>();
	this->stack->get(1)->destroy<bool>();

	delete this->stack;
}
