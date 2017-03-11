#include "Animation_Seasonal.hpp"

/* ~~~ Animation Seasonal Winter: Individual Window Randomized Snow */

Animation_Seasonal_Winter_WindowSnow::Animation_Seasonal_Winter_WindowSnow(Adafruit_NeoPixel* strip) {
	this->strip = strip;
}

void Animation_Seasonal_Winter_WindowSnow::init() {
 	Animation_Seasonal::init();
	this->name = getNameOfStrip(this->strip);
 	this->name += F(": Randomized Snow");
	this->num_strips = 1;
	this->update_rate = 50;
	this->strips = getAsStripArray(this->strip);

	this->stack = new LocalStack();
	this->stack->push(new MemObj(new unsigned int(0)));
	this->stack->push(new MemObj(new bool(false)));
	this->stack->push(new MemObj(new unsigned short int(0)));
	this->stack->push(new MemObj(new unsigned short int(0)));
}


void Animation_Seasonal_Winter_WindowSnow::step() {
	const int rightBottom = 9;
	const int rightTop = 40;
	const int leftTop = 50;
	const int leftBottom = 80;

	const unsigned long int on  = Color(100,100,100);

	unsigned int& i = this->stack->get(0)->get<unsigned int>();
	bool& mode = this->stack->get(1)->get<bool>();
	unsigned short int& left_spacing = this->stack->get(2)->get<unsigned short int>();
	unsigned short int& right_spacing = this->stack->get(3)->get<unsigned short int>();

	if (mode == false) {
		// randomize
		left_spacing = random(3,8);
		right_spacing = random(3,8);

		// snow fall
		// set each right pixel
		for (int x = rightBottom; x <= rightTop; x++) {
			int rel_index = x - rightBottom;

			if (rel_index % right_spacing == (1000 - i) % right_spacing) {
				this->strip->setPixelColor(x, on);
			} else {
				this->strip->setPixelColor(x, COLOR_OFF);
			}
		}

		// set each left pixel
		for (int x = leftTop; x <= leftBottom; x++){
			int rel_index = x - leftTop;

			if (rel_index % left_spacing == i % left_spacing) {
				this->strip->setPixelColor(x, on);
			} else {
				this->strip->setPixelColor(x, COLOR_OFF);
			}
		}

		this->strip->show();

		mode = true;
	} else {
		// snow fall
		// set each right pixel
		for (int x = rightBottom; x <= rightTop; x++) {
			int rel_index = x - rightBottom;

			if (rel_index % right_spacing == (1000 - i) % right_spacing) {
				this->strip->setPixelColor(x, on);
			} else {
				this->strip->setPixelColor(x, COLOR_OFF);
			}
		}

		// set each left pixel
		for (int x = leftTop; x <= leftBottom; x++){
			int rel_index = x - leftTop;

			if (rel_index % left_spacing == i % left_spacing) {
				this->strip->setPixelColor(x, on);
			} else {
				this->strip->setPixelColor(x, COLOR_OFF);
			}
		}

		this->strip->show();

		i++;

		// 40 for a loop one direction, 80 for a full forwards and backwards
		if (i == 800) {
			i = 0;
			mode = false;
			this->current_exec++;
		}
	}
}

void Animation_Seasonal_Winter_WindowSnow::clean() {
	this->stack->get(0)->destroy<unsigned int>();
	this->stack->get(1)->destroy<bool>();
	this->stack->get(2)->destroy<unsigned short int>();
	this->stack->get(3)->destroy<unsigned short int>();

	delete this->stack;
}
