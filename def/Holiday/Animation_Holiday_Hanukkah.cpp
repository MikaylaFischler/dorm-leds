#include "Animation_Holiday.cpp"

/* ~~~ Animation Holiday Hanukkah: Window 2 Hanukkah with Snow ~~~ */

void Animation_Holiday_Hanukkah_Win2Snow::init() {
 	Animation_Holiday::init();
 	this->name = F("Window[2]: Hanukkah with Snow");
	this->num_strips = 1;
 	this->strips = WINDOW_2;

	this->stack = LocalStack();
	this->stack.push(MemObj(new unsigned short int(0)));
	this->stack.push(MemObj(new bool(true));
	this->stack.push(MemObj(new unsigned short int(0)));
	this->stack.push(MemObj(new unsigned short int(0)));
}

void Animation_Holiday_Hanukkah_Win2Snow::step() {
	unsigned short int& i = this->stack.get(0).get<unsigned short int>();
	bool& mode = this->stack.get(1).get<bool>();
	unsigned short int& left = this->stack.get(2).get<unsigned short int>();
	unsigned short int& right = this->stack.get(3).get<unsigned short int>();

	if (mode == 0) {
		// randomize
		left = random(3,8);
		right = random(3,8);

		// snow fall
		this->hanukkah_snow(i, left, right);

		mode = 1;
	} else if (mode == 1) {
		// snow fall
		this->hanukkah_snow(i, left, right);

		i++;

		// 40 for a loop one direction, 80 for a full forwards and backwards
		if (i == 800) {
			i = 0;
			mode = 0;
			this->execution_count++;
		}
	}
}

void Animation_Holiday_Hanukkah_Win2Snow::hanukkah_snow(int i, int left_spacing, int right_spacing) {
	int rightBottom = 9;
	int rightTop = 40;
	int leftTop = 50;
	int leftBottom = 80;

	int leftFullLength = 41; // 39 pixels
	int rightFullLength = 41; // 40 pixels

	unsigned long int on  = window_generic.Color(150,150,150);
    unsigned long int blue = window_generic.Color(0,0,150);

	int a = 40 - abs(40 - i % 80);

	// handle top and bottom for christmas
	// left top
	for (int x = leftTop - 4; x < leftTop; x++) {
		int rel_index = x - leftTop + 4;

		if (rel_index < a % leftFullLength) {
			window2.setPixelColor(x, blue);
		} else {
			window2.setPixelColor(x, off);
		}
	}

	// right top
	for (int x = rightTop + 1; x <= rightTop + 5; x++) {
		int rel_index = x - 6;

		if (rel_index < a % rightFullLength) {
			window2.setPixelColor(x, blue);
		} else {
			window2.setPixelColor(x, off);
		}
	}

	// left bottom
	for (int x = 4; x >= 0; x--) {
		int rel_index = x + 35;

		if (rel_index < a % rightFullLength) {
			window2.setPixelColor(x, blue);
		} else {
			window2.setPixelColor(x, off);
		}
	}

	// right bottom
	for (int x = 5; x < rightBottom; x++) {
		int rel_index = x - 5;

		if (rel_index < a % rightFullLength) {
			window2.setPixelColor(x, blue);
		} else {
			window2.setPixelColor(x, off);
		}
	}

	// set each right pixel
	for (int x = rightBottom; x <= rightTop; x++) {
		int rel_index = x - rightBottom;

		if (rel_index % right_spacing == (800 - i) % right_spacing) {
			window2.setPixelColor(x, on);
		} else {
			if (x - 4 < a % rightFullLength) {
				window2.setPixelColor(x, blue);
			} else {
				window2.setPixelColor(x, off);
			}
		}
	}

	// set each left pixel
	for (int x = leftTop; x <= leftBottom; x++){
		int rel_index = x - leftTop;

		if (rel_index % left_spacing == i % left_spacing) {
			window2.setPixelColor(x, on);
		} else {
			if (rel_index + 4 < a % leftFullLength) {
				window2.setPixelColor(x, blue);
			} else {
				window2.setPixelColor(x, off);
			}
		}
	}

	window2.show();
}

void Animation_Holiday_Hanukkah_Win2Snow::clean() {
	this->stack.get(0).destroy<unsigned short int>();
	this->stack.get(1).destroy<bool>();
	this->stack.get(2).destroy<unsigned short int>();
	this->stack.get(3).destroy<unsigned short int>();
}
