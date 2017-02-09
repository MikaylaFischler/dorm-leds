#include "Animation_Simple.hpp"

/* ~~~ Generic Individual ~~~ */

// define the generic individual init
void Animation_Simple_Indiv::init() {
  	Animation::init();
  	this->max_exec = -1;
	this->num_strips = 1;
}

/* ~~~ Animation Simple: Strip Color Flash ~~~ */

Animation_Simple_Indiv_ColorFlash::Animation_Simple_Indiv_ColorFlash(Adafruit_NeoPixel* strip, uint32_t color) {
	this->strip = strip;
	this->color = color;
	this->rate = 200;
}

Animation_Simple_Indiv_ColorFlash::Animation_Simple_Indiv_ColorFlash(Adafruit_NeoPixel* strip, uint32_t color, int rate) {
	this->strip = strip;
	this->color = color;
	this->rate = rate;
}

void Animation_Simple_Indiv_ColorFlash::init() {
	Animation_Simple_Indiv::init();
	this->name = getNameOfStrip(this->strip);
	this->name += F(": Color Flash");
    this->update_rate = this->rate;
	this->strips = getAsStripArray(this->strip);

	this->stack = new LocalStack();
	this->stack->push(new MemObj(new bool(true)));
}

void Animation_Simple_Indiv_ColorFlash::step() {
	bool& mode = this->stack->get(0)->get<bool>();

	// set each led to the proper color
	for (unsigned int j = 0; j < strip->numPixels(); j++) {
		if (mode) {
			strip->setPixelColor(j, this->color);
		} else {
			strip->setPixelColor(j, COLOR_OFF);
		}
	}

	strip->show();

	if (mode) {
		mode = false;
	} else {
		mode = true;
		this->current_exec++;
	}
}

void Animation_Simple_Indiv_ColorFlash::clean() {
	this->stack->get(0)->destroy<bool>();

	delete this->stack;
}

/* ~~~ Animation Simple: Strip Color Flash ~~~ */

Animation_Simple_Indiv_AlternatingColorFlash::Animation_Simple_Indiv_AlternatingColorFlash(Adafruit_NeoPixel* strip, uint32_t color_a, uint32_t color_b) {
	this->strip = strip;
	this->color_a = color_a;
	this->color_b = color_b;
	this->rate = 200;
}

Animation_Simple_Indiv_AlternatingColorFlash::Animation_Simple_Indiv_AlternatingColorFlash(Adafruit_NeoPixel* strip, uint32_t color_a, uint32_t color_b, int rate) {
	this->strip = strip;
	this->color_a = color_a;
	this->color_b = color_b;
	this->rate = rate;
}

void Animation_Simple_Indiv_AlternatingColorFlash::init() {
	Animation_Simple_Indiv::init();
	this->name = getNameOfStrip(this->strip);
	this->name += F(": Color Flash");
    this->update_rate = this->rate;
	this->strips = getAsStripArray(this->strip);

	this->stack = new LocalStack();
	this->stack->push(new MemObj(new bool(true)));
	this->stack->push(new MemObj(new bool(true)));
}

void Animation_Simple_Indiv_AlternatingColorFlash::step() {
	bool& mode = this->stack->get(0)->get<bool>();
	bool& c = this->stack->get(1)->get<bool>();

	// set each led to the proper color
	for (unsigned int j = 0; j < strip->numPixels(); j++) {
		if (mode) {
			if (c) {
				strip->setPixelColor(j, this->color_a);
			} else {
				strip->setPixelColor(j, this->color_b);
			}
		} else {
			strip->setPixelColor(j, COLOR_OFF);
		}
	}

	strip->show();

	if (mode) {
		mode = false;
		c = !c;
	} else {
		mode = true;
		this->current_exec++;
	}
}

void Animation_Simple_Indiv_AlternatingColorFlash::clean() {
	this->stack->get(0)->destroy<bool>();
	this->stack->get(1)->destroy<bool>();

	delete this->stack;
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
	this->strips = getAsStripArray(this->strip);

	this->stack = new LocalStack();
	this->stack->push(new MemObj(new unsigned short int(0)));
	this->stack->push(new MemObj(new bool(true)));
}

void Animation_Simple_Indiv_ColorFade::step() {
	unsigned short int& i = this->stack->get(0)->get<unsigned short int>();
	bool& increasing = this->stack->get(1)->get<bool>();

	// set each led to the proper color
	for (unsigned int j = 0; j < strip->numPixels(); j++) {
		strip->setPixelColor(j, (redFromColor(this->color) * i/255), (greenFromColor(this->color) * i/255), (blueFromColor(this->color) * i/255));
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
	this->strips = getAsStripArray(this->strip);

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
	this->strips = getAsStripArray(this->strip);

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
