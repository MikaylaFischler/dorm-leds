#include "Animation_Holiday.hpp"

/* ~~~ Animation Holiday Halloween: Basic Orange/Purple Fade (All Windows) ~~~ */

void Animation_Holiday_Halloween_WinAllFade::init() {
 	Animation_Holiday::init();
 	this->name = F("Window[all]: Basic Halloween Fade");
    this->update_rate = 5;
	this->num_strips = 3;
 	this->strips = WINDOW_ALL;

	this->stack = new LocalStack();
	this->stack->push(new MemObj(new unsigned short int(0)));
	this->stack->push(new MemObj(new bool(true)));
}

void Animation_Holiday_Halloween_WinAllFade::step() {
	unsigned short int& i = this->stack->get(0)->get<unsigned short int>();
	bool& increasing = this->stack->get(1)->get<bool>();

    for (int x = 0; x < WINDOW_LENGTH; x++) {
    	window1.setPixelColor(x, window_generic.Color(i, (int)(((float)i / 255.0) * 50), 0));
        window2.setPixelColor(x, window_generic.Color((int)(((float)i / 255.0) * 150), 0, i));
        window3.setPixelColor(x, window_generic.Color(i, (int)(((float)i / 255.0) * 50), 0));
    }

    showAllWindowStrips();

    if (increasing) {
        if (i == 255) {
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

void Animation_Holiday_Halloween_WinAllFade::clean() {
	this->stack->get(0)->destroy<unsigned short int>();
	this->stack->get(1)->destroy<bool>();

	delete this->stack;
}

/* ~~~ Animation Holiday Halloween: Randomized Sparkle Effect (All Windows) ~~~ */

void Animation_Holiday_Halloween_WinAllHalloweenSparkle::init() {
 	Animation_Holiday::init();
 	this->name = F("Window[all]: Halloween Sparkle Fade");
    this->update_rate = 1000;
	this->num_strips = 3;
 	this->strips = WINDOW_ALL;

	this->stack = new LocalStack();
	this->stack->push(new MemObj(new unsigned int(0)));
	this->stack->push(new MemObj(new bool(true)));
	this->stack->push(new MemObj(new bool[WINDOW_LENGTH * 3] {false}));
}

void Animation_Holiday_Halloween_WinAllHalloweenSparkle::step() {
	unsigned int& i = this->stack->get(0)->get<unsigned int>();
	bool& reset = this->stack->get(1)->get<bool>();
	bool*& increasing = this->stack->get(2)->get<bool*>();

	if (reset) {
		// randomize
		for (int x = 0; x < WINDOW_LENGTH; x++) {
			window1.setPixelColor(x, this->rand_halloween_color());
			window2.setPixelColor(x, this->rand_halloween_color());
			window3.setPixelColor(x, this->rand_halloween_color());
		}

		reset = false;
	} else {
		// fade for a bit
		this->sparkle_fade(increasing);

		i++;

		if (i == 256) {
			i = 0;
			reset = true;
      		this->current_exec++;
		}
	}

	showAllWindowStrips();
}

void Animation_Holiday_Halloween_WinAllHalloweenSparkle::clean() {
	this->stack->get(0)->destroy<unsigned int>();
	this->stack->get(1)->destroy<unsigned short int>();
	bool* arr = this->stack->get(2)->get<bool[WINDOW_LENGTH * 3]>();
	delete [] arr;

	delete this->stack;
}

unsigned long int Animation_Holiday_Halloween_WinAllHalloweenSparkle::rand_halloween_color() {
	unsigned long int bright_orange = window_generic.Color(255, 50, 0);
	unsigned long int medium_orange = window_generic.Color(190, 37, 0);
	unsigned long int dim_orange = window_generic.Color(100, 20, 0);

	unsigned long int bright_purple = window_generic.Color(150, 0, 255);
	unsigned long int medium_purple = window_generic.Color(112, 0, 190);
	unsigned long int dim_purple = window_generic.Color(59, 0, 100);

	long int r = random(0,7);

	switch(r) {
		case 0:
			return COLOR_OFF;
		case 1:
			return bright_orange;
		case 2:
			return medium_orange;
		case 3:
			return dim_orange;
		case 4:
			return bright_purple;
		case 5:
			return medium_purple;
		case 6:
			return dim_purple;
		default:
			return COLOR_OFF;
	}
}

unsigned int Animation_Holiday_Halloween_WinAllHalloweenSparkle::floor_0(float x) {
	if (x <= 0.0) {
		// handle cases below 0
		return (unsigned int) 0;
	} else {
		// this will not be negative ever
		return (unsigned int) floor(x);
	}
}

void Animation_Holiday_Halloween_WinAllHalloweenSparkle::sparkle_fade(bool*& inc) {
	const float ORANGE_R_SLOPE = 1.0;
	const float ORANGE_G_SLOPE = 0.196078;
	const float PURPLE_R_SLOPE = 0.588235;
	const float PURPLE_B_SLOPE = 1.0;

	Adafruit_NeoPixel* temp_win;

	// fade with absolute value since so many different values
	for (int x = 0; x < WINDOW_LENGTH * 3; x++) {
		int pixel = 0;

		if (x < WINDOW_LENGTH) {
			temp_win = &window1;
			pixel = x;
		} else if (x < WINDOW_LENGTH * 2) {
			temp_win = &window2;
			pixel = x - WINDOW_LENGTH;
		} else {
			temp_win = &window3;
			pixel = x - WINDOW_LENGTH * 2;
		}

		Adafruit_NeoPixel& win = *temp_win;

		unsigned long int color = win.getPixelColor(pixel);

		unsigned int red = redFromColor(color);
		unsigned int green = greenFromColor(color);
		unsigned int blue = blueFromColor(color);

		bool increasing = inc[x];

		// now check each value to see if one is zero (acts as a data bit indicating which color is being displayed)
		// if green is 0, purple is being displayed
		// if blue is 0, orange is being displayed
		// if red is 0, black (off) is being displayed

		if (red <= 0) {
			// is off, randomly pick a color
			int r = random(0,2);

			if (increasing) {
				increasing = false;
			} else {
				increasing = true;
			}

			if (r == 0) {
				// purple
				win.setPixelColor(pixel, window_generic.Color(1,0,2));
			} else {
				// orange
				win.setPixelColor(pixel, window_generic.Color(5,1,0));
			}
		} else if (green == 0) {
			// was purple
			if (increasing) {
				win.setPixelColor(pixel, window_generic.Color(floor_0((float)red + PURPLE_R_SLOPE), 0, floor_0((float)blue + PURPLE_B_SLOPE)));
			} else {
				win.setPixelColor(pixel, window_generic.Color(floor_0((float)red - PURPLE_R_SLOPE), 0, floor_0((float)blue - PURPLE_B_SLOPE)));
			}
		} else if (blue == 0) {
			// was orange
			if (increasing) {
				win.setPixelColor(pixel, window_generic.Color(floor_0((float)red + ORANGE_R_SLOPE), floor_0((float)green + ORANGE_G_SLOPE), 0));
			} else {
				win.setPixelColor(pixel, window_generic.Color(floor_0((float)red - ORANGE_R_SLOPE), floor_0((float)green - ORANGE_G_SLOPE), 0));
			}
		}

		inc[x] = increasing;
	}
}
