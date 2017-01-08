#include "Animation_Simple.cpp"

/* ~~~ Generic Window Color Wipe ~~~ */

// define the rainbow color wipe helper function
void Animation_Simple_WinColorWipe::rainbow_color_wipe(Adafruit_NeoPixel& strip, unsigned short int i, unsigned short int color_mode) {
	if (color_mode % 2 != 0) {
		strip.setPixelColor(i, COLOR_OFF);
	} else if (color_mode == 0) {
		strip.setPixelColor(i, COLOR_RED);
	} else if (color_mode == 2) {
		strip.setPixelColor(i, COLOR_ORANGE);
	} else if (color_mode == 4) {
		strip.setPixelColor(i, COLOR_YELLOW);
	} else if (color_mode == 6) {
		strip.setPixelColor(i, COLOR_GREEN);
	} else if (color_mode == 8) {
		strip.setPixelColor(i, COLOR_SEA_GREEN);
	} else if (color_mode == 10) {
		strip.setPixelColor(i, COLOR_BLUE);
	} else if (color_mode == 12) {
		strip.setPixelColor(i, COLOR_INDIGO);
	} else if (color_mode == 14) {
		strip.setPixelColor(i, COLOR_VIOLET);
	}
}

/* ~~~ Animation Simple: Window 1 Rainbow Color Wipe ~~~ */

void Animation_Simple_Win1RainbowWipe::init() {
 	Animation_Simple::init();
 	this->name = F("Window[1]: Rainbow Color Wipe");
 	this->strips = WINDOW_1;

	this->stack = LocalStack();
	this->stack.push(MemObj(new unsigned short int(0)));
	this->stack.push(MemObj(new unsigned short int(0)));
}

void Animation_Simple_Win1RainbowWipe::step() {
	unsigned short int& i = this->stack.get(0).get<unsigned short int>();
	unsigned short int& color_mode = this->stack.get(1).get<unsigned short int>();

    this->rainbow_color_wipe(window1, i, color_mode);

    window1.show();

    i++;

	if (i == WINDOW_LENGTH) {
		color_mode++;
		i = 0;

		if (color_mode == 16) {
			color_mode = 0;
			this->execution_count++;
		}
	}
}

void Animation_Simple_Win1RainbowWipe::clean() {
	this->stack.get(0).destroy<unsigned short int>();
	this->stack.get(1).destroy<unsigned short int>();
}

/* ~~~ Animation Simple: Window 2 Rainbow Color Wipe ~~~ */

void Animation_Simple_Win2RainbowWipe::init() {
 	Animation_Simple::init();
 	this->name = F("Window[2]: Rainbow Color Wipe");
 	this->strips = WINDOW_2;

	this->stack = LocalStack();
	this->stack.push(MemObj(new unsigned short int(0)));
	this->stack.push(MemObj(new unsigned short int(0)));
}

void Animation_Simple_Win2RainbowWipe::step() {
	unsigned short int& i = this->stack.get(0).get<unsigned short int>();
	unsigned short int& color_mode = this->stack.get(1).get<unsigned short int>();

    this->rainbow_color_wipe(window2, i, color_mode);

    window2.show();

    i++;

	if (i == WINDOW_LENGTH) {
		color_mode++;
		i = 0;

		if (color_mode == 16) {
			color_mode = 0;
			this->execution_count++;
		}
	}
}

void Animation_Simple_Win2RainbowWipe::clean() {
	this->stack.get(0).destroy<unsigned short int>();
	this->stack.get(1).destroy<unsigned short int>();
}

/* ~~~ Animation Simple: Window 3 Rainbow Color Wipe ~~~ */

void Animation_Simple_Win3RainbowWipe::init() {
 	Animation_Simple::init();
 	this->name = F("Window[3]: Rainbow Color Wipe");
 	this->strips = WINDOW_3;

	this->stack = LocalStack();
	this->stack.push(MemObj(new unsigned short int(0)));
	this->stack.push(MemObj(new unsigned short int(0)));
}

void Animation_Simple_Win3RainbowWipe::step() {
	unsigned short int& i = this->stack.get(0).get<unsigned short int>();
	unsigned short int& color_mode = this->stack.get(1).get<unsigned short int>();

    this->rainbow_color_wipe(window2, i, color_mode);

    window3.show();

    i++;

	if (i == WINDOW_LENGTH) {
		color_mode++;
		i = 0;

		if (color_mode == 16) {
			color_mode = 0;
			this->execution_count++;
		}
	}
}

void Animation_Simple_Win3RainbowWipe::clean() {
	this->stack.get(0).destroy<unsigned short int>();
	this->stack.get(1).destroy<unsigned short int>();
}
