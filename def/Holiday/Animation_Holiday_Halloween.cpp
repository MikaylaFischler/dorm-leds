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

Animation_Holiday_Halloween_WinAllHalloweenSparkle::HalloweenPixel::HalloweenPixel(unsigned long int color_32b, bool inc, char cid) :
	increasing(inc), color_id(cid) {
		this->r = redFromColor(color_32b);
		this->g = greenFromColor(color_32b);
		this->b = blueFromColor(color_32b);
}

Animation_Holiday_Halloween_WinAllHalloweenSparkle::~Animation_Holiday_Halloween_WinAllHalloweenSparkle() {
	// free memory for each pixel
	for (int x = 0; x < WINDOW_LENGTH * 3; x++) {
		delete pixeldata[x];
	}
}

void Animation_Holiday_Halloween_WinAllHalloweenSparkle::init() {
 	Animation_Holiday::init();
 	this->name = F("Window[all]: Halloween Sparkle Fade");
    this->update_rate = 5;
	this->num_strips = 3;
 	this->strips = WINDOW_ALL;

	i = 0;

	// randomize
	for (int x = 0; x < WINDOW_LENGTH * 3; x++) {
		randomize_display(x);
	}
}

void Animation_Holiday_Halloween_WinAllHalloweenSparkle::step() {
	// fade for a bit
	this->sparkle_fade();

	// somewhat of an idea of full executions
	i++;
	if (i == 256) {
		i = 0;
  		this->current_exec++;
	}

	showAllWindowStrips();
}

void Animation_Holiday_Halloween_WinAllHalloweenSparkle::randomize_display(int x) {
	unsigned long int bright_orange = Color(255, 50, 0);
	unsigned long int medium_orange = Color(190, 37, 0);
	unsigned long int dim_orange = Color(100, 20, 0);

	unsigned long int bright_purple = Color(150, 0, 255);
	unsigned long int medium_purple = Color(112, 0, 190);
	unsigned long int dim_purple = Color(59, 0, 100);

	long int r = random(0,7);
	unsigned long int color;
	bool increasing;
	char cid;

	switch(r) {
		case 0:
			color = COLOR_OFF;
			increasing = true;
			cid = 'x';
			break;
		case 1:
			color = bright_orange;
			increasing = false;
			cid = 'o';
			break;
		case 2:
			color = medium_orange;
			increasing = true;
			cid = 'o';
			break;
		case 3:
			color = dim_orange;
			increasing = true;
			cid = 'o';
			break;
		case 4:
			color = bright_purple;
			increasing = false;
			cid = 'p';
			break;
		case 5:
			color = medium_purple;
			increasing = true;
			cid = 'p';
			break;
		case 6:
			color = dim_purple;
			increasing = true;
			cid = 'p';
			break;
		default:
			color = COLOR_OFF;
			increasing = true;
			cid = 'x';
	}

	pixeldata[x] = new HalloweenPixel(color, increasing, cid);

	if (x < WINDOW_LENGTH) {
		window1.setPixelColor(x, color);
	} else if (x < WINDOW_LENGTH * 2) {
		window2.setPixelColor(x - WINDOW_LENGTH, color);
	} else {
		window3.setPixelColor(x - WINDOW_LENGTH * 2, color);
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

		// now check each value to see if one is zero (acts as a data bit indicating which color is being displayed)
		// if green is 0, purple is being displayed
		// if blue is 0, orange is being displayed
		// if red is 0, black (off) is being displayed

		HalloweenPixel* data = pixeldata[x];

		if (data->r == 0) {
			// is off, randomly pick a color
			int r = random(0,2);
			data->increasing = true;

			if (r == 0) {
				// purple
				data->r = 1;
				data->g = 0;
				data->b = 81;

				win.setPixelColor(pixel, Color(1,0,81));
			} else {
				// orange
				data->r = 5;
				data->g = 1;
				data->b = 0;

				win.setPixelColor(pixel, Color(5,1,0));
			}
		} else if (data->g == 0) {
			// is purple
			if (data->increasing) {
				data->r = floor_0((float)data->r + 1);
				data->b = floor_0((float)data->b + 1);

				if (data->r >= 255 || data->b >= 255) {
					data->increasing = false;
					data->r = floor_0((float)data->r - 1);
					data->b = floor_0((float)data->b - 1);
				}
			} else {
				data->r = floor_0((float)data->r - 1);
				data->b = floor_0((float)data->b - 1);

				if (data->r <= 0 || data->b <= 0) {
					data->increasing = false;
					data->r = 0;
					data->b = 0;
				}
			}

			data->g = 0;
			win.setPixelColor(pixel, Color(data->r, 0, data->b));
		} else if (data->b == 0) {
			// is orange
			if (data->increasing) {
				data->r = floor_0((float)data->r + 1);
				data->g = floor_0((float)data->g + ORANGE_G_SLOPE);

				if (data->r >= 255 || data->g >= 255) {
					data->increasing = false;
					data->r = floor_0((float)data->r - 1);
					data->g = floor_0((float)data->g - ORANGE_G_SLOPE);
				}
			} else {
				data->r = floor_0((float)data->r - 1);
				data->g = floor_0((float)data->g - ORANGE_G_SLOPE);

				if (data->r <= 0 || data->g <= 0) {
					data->increasing = true;
					data->r = 0;
					data->g = 0;
				}
			}

			data->b = 0;
			win.setPixelColor(pixel, Color(data->r, data->g, 0));
		} else {
			Serial.println("ERROR: UNKNOWN COLOR STATE");
		}
	}
}
