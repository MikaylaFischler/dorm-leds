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
    this->update_rate = 10;
	this->num_strips = 2;
 	this->strips = DESK_ALL;

	i = 0;
	increasing = true;
}

void Animation_Simple_DeskWhitePurpleFade::step() {
	for (int x = 0; x < DESK1_LENGTH; x++) {
		if (x % 3 != 0) {
			desk1.setPixelColor(x, Color((int)(((float)i / 150.0) * 100), 0, i));
		} else {
			desk1.setPixelColor(x, COLOR_DIM_OFF_WHITE);
		}
	}

	for (int x = 0; x < DESK2_LENGTH; x++) {
		if (x % 3 != 0) {
			desk2.setPixelColor(x, Color((int)(((float)i / 150.0) * 100), 0, i));
		} else {
			desk2.setPixelColor(x, COLOR_DIM_OFF_WHITE);
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
      		this->current_exec++;
    	} else {
      		i--;
    	}
  	}
}

/* ~~~ Animation Simple: Window All WPI Spirit ~~~ */

void Animation_Simple_WinAllWPISpirit::init() {
	Animation_Simple::init();
	this->name = F("Window[all]: WPI Spirit");
	this->num_strips = 3;
	this->strips = WINDOW_ALL;

	i = 0;
	mode = true;
}

void Animation_Simple_WinAllWPISpirit::step() {
	if (!mode) {
		window1.setPixelColor(i, COLOR_MAROON);

		if (i % 2 == 0) {
			window2.setPixelColor(i, COLOR_LIGHT_SILVER);
		} else {
			window2.setPixelColor(i, COLOR_MAROON);
		}

		int modified = WINDOW_LENGTH + 9 - 1 - i;

		if (modified >= WINDOW_LENGTH) {
			modified -= WINDOW_LENGTH;
		}

		window3.setPixelColor(modified, COLOR_MAROON);
	} else if (mode) {
		window1.setPixelColor(i, COLOR_LIGHT_SILVER);

		for (int j = 0; j < WINDOW_LENGTH; j++) {
			if (i % 2 != 0) {
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
			this->current_exec++;
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
