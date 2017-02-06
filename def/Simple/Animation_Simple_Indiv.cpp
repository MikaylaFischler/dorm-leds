#include "Animation_Simple.hpp"

/* ~~~ Generic Individual ~~~ */

// define the generic individual init
void Animation_Simple_Indiv::init() {
  	Animation::init();
  	this->max_exec = -1;
	this->num_strips = 1;
}

/* ~~~ Animation Simple: Strip Color Fade ~~~ */

Animation_Simple_Indiv_ColorFade::Animation_Simple_Indiv_ColorFade(Adafruit_NeoPixel* strip, uint32_t color) {
	this->strip = strip;
	this->color = color;
}

void Animation_Simple_Indiv_ColorFade::init() {
	Animation_Simple_Indiv::init();
	this->name = getNameOfStrip(this->strip);
	this->name += F(": Color Fade");
    this->update_rate = 50;
	this->strips = getStripID(this->strip);

	this->stack = new LocalStack();
	this->stack->push(new MemObj(new unsigned short int(0)));
	this->stack->push(new MemObj(new bool(true)));
}

void Animation_Simple_Indiv_ColorFade::step() {
	unsigned short int& i = this->stack->get(0)->get<unsigned short int>();
	bool& increasing = this->stack->get(1)->get<bool>();

	// set each led to the proper color
	uint16_t red = redFromColor(this->color);
	uint16_t green = greenFromColor(this->color);
	uint16_t blue = blueFromColor(this->color);

	for (unsigned int j = 0; j < strip->numPixels(); j++) {
		strip->setPixelColor(j, (red * i/255), (green * i/255), (blue * i/255));
	}

	strip->show();

	if (increasing) {
		if (i == 255) {
			increasing = false;
		} else {
			i++;
		}
	} else {
		if (i == 0) {
			increasing = true;
			this->current_exec++;
		} else {
			i--;
		}
	}
}

void Animation_Simple_Indiv_ColorFade::clean() {
	this->stack->get(0)->destroy<unsigned short int>();
	this->stack->get(1)->destroy<bool>();

	delete this->stack;
}


/* ~~~ Animation Simple: Rainbow ~~~ */

Animation_Simple_Indiv_Rainbow::Animation_Simple_Indiv_Rainbow(Adafruit_NeoPixel* strip) {
	this->strip = strip;
}

void Animation_Simple_Indiv_Rainbow::init() {
	Animation_Simple_Indiv::init();
	this->name = getNameOfStrip(this->strip);
	this->name += F(": Rainbow");
    this->update_rate = 50;
	this->strips = getStripID(this->strip);

	this->stack = new LocalStack();
	this->stack->push(new MemObj(new unsigned short int(0)));
}

void Animation_Simple_Indiv_Rainbow::step() {
	unsigned short int& i = this->stack->get(0)->get<unsigned short int>();

	// set each led to the proper color
	for (unsigned int j = 0; j < strip->numPixels(); j++) {
		strip->setPixelColor(j, ColorWheel((i + j) & 255));
	}

	strip->show();

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

/* ~~~ Animation Simple: Rainbow Cycle ~~~ */

Animation_Simple_Indiv_RainbowCycle::Animation_Simple_Indiv_RainbowCycle(Adafruit_NeoPixel* strip) {
	this->strip = strip;
}

void Animation_Simple_Indiv_RainbowCycle::init() {
	Animation_Simple_Indiv::init();
	this->name = getNameOfStrip(this->strip);
	this->name += F(": Rainbow Cycle");
    this->update_rate = 50;
	this->strips = getStripID(this->strip);

	this->stack = new LocalStack();
	this->stack->push(new MemObj(new unsigned short int(0)));
}

void Animation_Simple_Indiv_RainbowCycle::step() {
	unsigned short int& i = this->stack->get(0)->get<unsigned short int>();

	// set each led to the proper color
	for (unsigned int j = 0; j < strip->numPixels(); j++) {
		strip->setPixelColor(j, ((i * 256 / strip->numPixels()) + j) & 255);
	}

	strip->show();

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
