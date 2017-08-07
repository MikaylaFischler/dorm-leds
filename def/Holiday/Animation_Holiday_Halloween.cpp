#include "Animation_Holiday.hpp"

/* ~~~ Animation Holiday Halloween: Basic Orange/Purple Fade (All Windows) ~~~ */

void Animation_Holiday_Halloween_WinAllFade::init() {
 	Animation_Holiday::init();
 	this->name = F("Window[all]: Basic Halloween Fade");
    this->update_rate = 5;
	this->num_strips = 3;
 	this->strips = WINDOW_ALL;

	i = 0;
	increasing = true;
}

void Animation_Holiday_Halloween_WinAllFade::step() {
    for (int x = 0; x < WINDOW_LENGTH; x++) {
    	window1.setPixelColor(x, Color(i, (int)(((float)i / 255.0) * 50), 0));
        window2.setPixelColor(x, Color((int)(((float)i / 255.0) * 150), 0, i));
        window3.setPixelColor(x, Color(i, (int)(((float)i / 255.0) * 50), 0));
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

/* ~~~ Animation Holiday Halloween: Randomized Sparkle Effect (All Windows) ~~~ */

void Animation_Holiday_Halloween_WinAllHalloweenSparkle::init() {
 	Animation_Holiday::init();
 	this->name = F("Window[all]: Halloween Sparkle Fade");
    this->update_rate = 100;
	this->num_strips = 3;
 	this->strips = WINDOW_ALL;

	i = 0;
	reset = true;

	for (int x = 0; x < WINDOW_LENGTH * 3; x++) { increasing[x] = false; }
}

void Animation_Holiday_Halloween_WinAllHalloweenSparkle::step() {
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
		this->sparkle_fade();

		i++;

		if (i == 256) {
			i = 0;
			reset = true;
      		this->current_exec++;
		}
	}

	showAllWindowStrips();

	Serial.println("heartbeat");
}

unsigned long int Animation_Holiday_Halloween_WinAllHalloweenSparkle::rand_halloween_color() {
	unsigned long int bright_orange = Color(255, 50, 0);
	unsigned long int medium_orange = Color(190, 37, 0);
	unsigned long int dim_orange = Color(100, 20, 0);

	unsigned long int bright_purple = Color(150, 0, 255);
	unsigned long int medium_purple = Color(112, 0, 190);
	unsigned long int dim_purple = Color(59, 0, 100);

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

void Animation_Holiday_Halloween_WinAllHalloweenSparkle::sparkle_fade() {
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

		bool inc = increasing[x];

		// now check each value to see if one is zero (acts as a data bit indicating which color is being displayed)
		// if green is 0, purple is being displayed
		// if blue is 0, orange is being displayed
		// if red is 0, black (off) is being displayed

		if (red == 0) {
			// is off, randomly pick a color
			int r = random(0,2);

			if (inc) {
				inc = false;
			} else {
				inc = true;
			}

			Serial.println(r);
			Serial.println(pixel);

			if (r == 0) {
				// purple
				win.setPixelColor(pixel, Color(1,0,2));
			} else {
				// orange
				win.setPixelColor(pixel, Color(5,1,0));
			}
		} else if (green == 0) {
			// was purple
			if (inc) {
				win.setPixelColor(pixel, Color(floor_0((float)red + PURPLE_R_SLOPE), 0, floor_0((float)blue + PURPLE_B_SLOPE)));
			} else {
				win.setPixelColor(pixel, Color(floor_0((float)red - PURPLE_R_SLOPE), 0, floor_0((float)blue - PURPLE_B_SLOPE)));
			}
		} else if (blue == 0) {
			// was orange
			if (inc) {
				win.setPixelColor(pixel, Color(floor_0((float)red + ORANGE_R_SLOPE), floor_0((float)green + ORANGE_G_SLOPE), 0));
			} else {
				win.setPixelColor(pixel, Color(floor_0((float)red - ORANGE_R_SLOPE), floor_0((float)green - ORANGE_G_SLOPE), 0));
			}
		}

		increasing[x] = inc;
	}
}
