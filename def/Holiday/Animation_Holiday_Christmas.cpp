#include "Animation_Holiday.cpp"

/* ~~~ Animation Holiday Christmas: Christmas with Snow (Outer Windows, 1 and 3) ~~~ */

void Animation_Holiday_Christmas_Win13Snow::init() {
 	Animation_Holiday::init();
 	this->name = F("Window[1,3]: Christmas with Snow");
	this->num_strips = 2;
 	this->strips = WINDOW_1_3;

	this->stack = new LocalStack();
	this->stack->push(MemObj(new unsigned short int(0)));
	this->stack->push(MemObj(new bool(true));
	this->stack->push(MemObj(new unsigned short int(0)));
	this->stack->push(MemObj(new unsigned short int(0)));
}

void Animation_Holiday_Christmas_Win13Snow::step() {
	unsigned short int& i = this->stack->get(0).get<unsigned short int>();
	bool& mode = this->stack->get(1).get<bool>();
	unsigned short int& left = this->stack->get(2).get<unsigned short int>();
	unsigned short int& right = this->stack->get(3).get<unsigned short int>();

	if (mode == 0) {
		// randomize
		left = random(3,8);
		right = random(3,8);

		// snow fall
		this->christmas_snow(i, left, right);

		mode = 1;
	} else if (mode == 1) {
		// snow fall
		this->christmas_snow(i, left, right);

		i++;

		// 40 for a loop one direction, 80 for a full forwards and backwards
		if (i == 800) {
			i = 0;
			mode = 0;
			this->current_exec++;
		}
	}
}

void Animation_Holiday_Christmas_Win13Snow::christmas_snow(int i, int left_spacing, int right_spacing) {
	int rightBottom = 9;
	int rightTop = 40;
	int leftTop = 50;
	int leftBottom = 80;

	int leftFullLength = 41; // 39 pixels
	int rightFullLength = 41; // 40 pixels

	unsigned long int on  = window_generic.Color(150,150,150);
	unsigned long int red = window_generic.Color(150,0,0);
	unsigned long int green = window_generic.Color(0,150,0);

	int a = 40 - abs(40 - i % 80);

	// handle top and bottom for christmas
	// left top
	for (int x = leftTop - 4; x < leftTop; x++) {
		int rel_index = x - leftTop + 4;

		if (rel_index < a % leftFullLength) {
			window1.setPixelColor(x, red);
			window3.setPixelColor(x, green);
		} else {
			window1.setPixelColor(x, COLOR_OFF);
			window3.setPixelColor(x, COLOR_OFF);
		}
	}

	// right top
	for (int x = rightTop + 1; x <= rightTop + 5; x++) {
		int rel_index = x - 6;

		if (rel_index < a % rightFullLength) {
			window1.setPixelColor(x, green);
			window3.setPixelColor(x, red);
		} else {
			window1.setPixelColor(x, COLOR_OFF);
			window3.setPixelColor(x, COLOR_OFF);
		}
	}

	// left bottom
	for (int x = 4; x >= 0; x--) {
		int rel_index = x + 35;

		if (rel_index < a % rightFullLength) {
			window1.setPixelColor(x, red);
			window3.setPixelColor(x, green);
		} else {
			window1.setPixelColor(x, COLOR_OFF);
			window3.setPixelColor(x, COLOR_OFF);
		}
	}

	// right bottom
	for (int x = 5; x < rightBottom; x++) {
		int rel_index = x - 5;

		if (rel_index < a % rightFullLength) {
			window1.setPixelColor(x, green);
			window3.setPixelColor(x, red);
		} else {
			window1.setPixelColor(x, COLOR_OFF);
			window3.setPixelColor(x, COLOR_OFF);
		}
	}

	// set each right pixel
	for (int x = rightBottom; x <= rightTop; x++) {
		int rel_index = x - rightBottom;

		if (rel_index % right_spacing == (800 - i) % right_spacing) {
			window1.setPixelColor(x, on);
			window3.setPixelColor(x, on);
		} else {
			if (x - 4 < a % rightFullLength) {
				window1.setPixelColor(x, green);
				window3.setPixelColor(x, red);
			} else {
				window1.setPixelColor(x, COLOR_OFF);
				window3.setPixelColor(x, COLOR_OFF);
			}
		}
	}

	// set each left pixel
	for (int x = leftTop; x <= leftBottom; x++){
		int rel_index = x - leftTop;

		if (rel_index % left_spacing == i % left_spacing) {
			window1.setPixelColor(x, on);
			window3.setPixelColor(x, on);
		} else {
			if (rel_index + 4 < a % leftFullLength) {
				window1.setPixelColor(x, red);
				window3.setPixelColor(x, green);
			} else {
				window1.setPixelColor(x, COLOR_OFF);
				window3.setPixelColor(x, COLOR_OFF);
			}
		}
	}

	window1.show();
	window3.show();
}

void Animation_Holiday_Christmas_Win13Snow::clean() {
	this->stack->get(0).destroy<unsigned short int>();
	this->stack->get(1).destroy<bool>();
	this->stack->get(2).destroy<unsigned short int>();
	this->stack->get(3).destroy<unsigned short int>();

	delete this->stack;
}
