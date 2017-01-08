#include "Animation_Simple.hpp"

/* ~~~ Generic Simple ~~~ */

// define the generic simple init
void Animation_Simple::init() {
  	Animation::init();
  	this->max_exec = -1;
}

/* ~~~ Animation Simple: Desk Both Off White/Purple Fade ~~~ */

void Animation_Simple_DeskWhitePurpleFade::init() {
 	Animation_Simple::init();
 	this->name = F("Desk[all]: Off White with Purple Fade");
	this->num_strips = 2;
 	this->strips = FULL_DESK;

	this->stack = LocalStack();
	this->stack.push(MemObj(new unsigned short int(0)));
	this->stack.push(MemObj(new bool(true)));
}

void Animation_Simple_DeskWhitePurpleFade::step() {
	unsigned short int& i = this->stack.get(0).get<unsigned short int>();
	bool& increasing = this->stack.get(1).get<bool>();

	for (int y = 0; y < DESK1_LENGTH; y++) {
		if (y%3 != 0) {
			desk1.setPixelColor(y, desk1.Color((int)(((float)i / 150.0) * 100), 0, i));
		} else {
			desk1.setPixelColor(y, COLOR_DIM_OFF_WHITE);
		}
	}

	for (int z = 0; z < DESK2_LENGTH; z++) {
		if (z%3 != 0) {
			desk2.setPixelColor(z, desk2.Color((int)(((float)i / 150.0) * 100), 0, i));
		} else {
			desk2.setPixelColor(z, COLOR_DIM_OFF_WHITE);
		}
	}

	desk1.show();
	desk2.show();

  	if (increasing) {
    	if (i == 150) {
    		i--;
      		increasing = false;
    	} else {
      		i++;
    	}
  	} else {
    	if (i == 0) {
      		i++;
      		increasing = true;
      		this->execution_count++;
    	} else {
      		i--;
    	}
  	}
}

void Animation_Simple_Win1RainbowWipe::clean() {
	this->stack.get(0).destroy<unsigned short int>();
	this->stack.get(1).destroy<bool>();
}

/* ~~~ Animation Simple: Window All Purple Fade ~~~ */

void Animation_Simple_WinAllPurpleFade::init() {
	Animation_Simple::init();
	this->name = F("Window[all]: Purple Fade");
	this->num_strips = 3;
	this->strips = WINDOW_ALL;

	this->stack = LocalStack();
	this->stack.push(MemObj(new unsigned short int(0)));
	this->stack.push(MemObj(new bool(true)));
}

void Animation_Simple_WinAllPurpleFade::step() {
	unsigned short int& i = this->stack.get(0).get<unsigned short int>();
	bool& increasing = this->stack.get(1).get<bool>();

	for (int x = 0; x < WINDOW_LENGTH; x++) {
		setAllWindowPixelColor(x, window_generic.Color((int)(((float)i / 150.0) * 100), 0, i));
	}

	showAllWindowStrips();

  	if (increasing) {
    	if (i == 150) {
    		i--;
      		increasing = false;
    	} else {
      		i++;
    	}
  	} else {
    	if (i == 0) {
      		i++;
      		increasing = true;
      		this->execution_count++;
    	} else {
      		i--;
    	}
  	}
}

void Animation_Simple_Win1RainbowWipe::clean() {
	this->stack.get(0).destroy<unsigned short int>();
	this->stack.get(1).destroy<bool>();
}

/* ~~~ Animation Simple: Window All WPI Spirit ~~~ */

void Animation_Simple_WPISpirit::init() {
	Animation_Simple::init();
	this->name = F("Window[all]: WPI Spirit");
	this->num_strips = 3;
	this->strips = WINDOW_ALL;

	this->stack = LocalStack();
	this->stack.push(MemObj(new unsigned short int(0)));
	this->stack.push(MemObj(new bool(true)));
}

void Animation_Simple_WPISpirit::step() {
	unsigned short int& i = this->stack.get(0).get<unsigned short int>();
	bool& mode = this->stack.get(1).get<bool>();

	if (mode == 0) {
		window1.setPixelColor(i, COLOR_MAROON);

		if (i%2 == 0) {
			window2.setPixelColor(i, COLOR_LIGHT_SILVER);
		} else {
			window2.setPixelColor(i, COLOR_MAROON);
		}

		int modified = WINDOW_LENGTH + 9 - 1 - i;

		if (modified >= WINDOW_LENGTH) {
			modified -= WINDOW_LENGTH;
		}

		window3.setPixelColor(modified, COLOR_MAROON);
	} else if (mode == 1) {
		window1.setPixelColor(i, COLOR_LIGHT_SILVER);

		for (int j = 0; j < WINDOW_LENGTH; j++) {
			if (i%2 != 0) {
				window2.setPixelColor(i, COLOR_LIGHT_SILVER);
			} else {
				window2.setPixelColor(i, COLOR_MAROON);
			}
		}

		int modified = WINDOW_LENGTH + 9 - 1 - i;

		if (modified >= WINDOW_LENGTH) {
			modified -= WINDOW_LENGTH;
		}

		window3.setPixelColor(modified, COLOR_LIGHT_SILVER);
	}

    window1.show();
    window3.show();

	if (mode) {
		if (i + 1 == WINDOW_LENGTH) {
			i = 0;
			mode = false;
			window2.show();
			fec++;
		} else {
			i++;
		}
	} else {
		if (i + 1 == WINDOW_LENGTH) {
			i = 0;
			mode = true;
			window2.show();
		} else {
			i++;
		}
	}
}

void Animation_Simple_Win1RainbowWipe::clean() {
	this->stack.get(0).destroy<unsigned short int>();
	this->stack.get(1).destroy<bool>();
}
