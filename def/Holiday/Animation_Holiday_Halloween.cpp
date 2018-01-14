#include "Animation_Holiday.hpp"

/* ~~~ Animation Holiday Halloween: Basic Orange/Purple Fade (All Windows) ~~~ */

void Animation_Holiday_Halloween_WinAllFade::init() {
 	Animation_Holiday::init();
 	this->name = F("Window Basic Halloween Fade");
    this->update_rate = 5;
 	this->strips.push_back(ID_WINDOW_1);
 	this->strips.push_back(ID_WINDOW_2);
 	this->strips.push_back(ID_WINDOW_3);

	i = 0;
	increasing = true;
}

void Animation_Holiday_Halloween_WinAllFade::step() {
    for (uint16_t x = 0; x < WINDOW_LENGTH; x++) {
    	npsm[ID_WINDOW_1]->setPixelColor(x, Color(i, (int)(((float)i / 255.0) * 50), 0));
        npsm[ID_WINDOW_2]->setPixelColor(x, Color((int)(((float)i / 255.0) * 150), 0, i));
        npsm[ID_WINDOW_3]->setPixelColor(x, Color(i, (int)(((float)i / 255.0) * 50), 0));
    }

	npsm[ID_WINDOW_1]->show();
    npsm[ID_WINDOW_2]->show();
    npsm[ID_WINDOW_3]->show();

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

Animation_Holiday_Halloween_WinAllHalloweenSparkle::~Animation_Holiday_Halloween_WinAllHalloweenSparkle() {
	// free memory for each pixel
	for (uint32_t x = 0; x < WINDOW_LENGTH * 3; x++) { delete pixeldata[x]; }
}

void Animation_Holiday_Halloween_WinAllHalloweenSparkle::init() {
 	Animation_Holiday::init();
 	this->name = F("Window Halloween Sparkle Fade");
    this->update_rate = 1;
 	this->strips.push_back(ID_WINDOW_1);
 	this->strips.push_back(ID_WINDOW_2);
 	this->strips.push_back(ID_WINDOW_3);

	i = 0;

	// randomize
	for (uint32_t x = 0; x < WINDOW_LENGTH * 3; x++) {
		randomize_display(x);

		randomSeed(analogRead(RAND_SEED_ANALOG_NOISE_PORT) * micros());

		// init all off
		if (x < WINDOW_LENGTH) {
			npsm[ID_WINDOW_1]->setPixelColor(x, COLOR_OFF);
		} else if (x < WINDOW_LENGTH * 2) {
			npsm[ID_WINDOW_2]->setPixelColor(x - WINDOW_LENGTH, COLOR_OFF);
		} else {
			npsm[ID_WINDOW_3]->setPixelColor(x - WINDOW_LENGTH * 2, COLOR_OFF);
		}
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

	npsm[ID_WINDOW_1]->show();
	npsm[ID_WINDOW_2]->show();
	npsm[ID_WINDOW_3]->show();
}

void Animation_Holiday_Halloween_WinAllHalloweenSparkle::randomize_display(int x) {
	// cast from long int to int explicitly
	int i   = (int) random(1,255);
	int inc = (int) random(0,2);
	int cid = (int) random(0,3);

	bool increasing;
	char color_id;

	if (inc == 1) {
		increasing = true;
	} else {
		increasing = false;
	}

	// randomize color
	if (cid == 0) {
		color_id = 'x';
	} else if (cid == 1) {
		color_id = 'p';
	} else {
		color_id = 'o';
	}

	pixeldata[x] = new HalloweenPixel(increasing, i, color_id);
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
	for (uint32_t x = 0; x < WINDOW_LENGTH * 3; x++) {
		int pixel = 0;

		if (x < WINDOW_LENGTH) {
			temp_win = npsm[ID_WINDOW_1];
			pixel = x;
		} else if (x < WINDOW_LENGTH * 2) {
			temp_win = npsm[ID_WINDOW_2];
			pixel = x - WINDOW_LENGTH;
		} else {
			temp_win = npsm[ID_WINDOW_3];
			pixel = x - WINDOW_LENGTH * 2;
		}

		Adafruit_NeoPixel& win = *temp_win;

		HalloweenPixel* data = pixeldata[x];

		if (data->color_id == 'x') {
			// is off, randomly pick a color
			data->increasing = true;
			data->i = 0;

			if (random(0,2) == 0) {
				// purple
				data->color_id = 'p';
				win.setPixelColor(pixel, Color(floor_0((float)data->i * PURPLE_R_SLOPE), 0, floor_0((float)data->i * PURPLE_B_SLOPE)));
			} else {
				// orange
				data->color_id = 'o';
				win.setPixelColor(pixel, Color(floor_0((float)data->i * ORANGE_R_SLOPE), floor_0((float)data->i * ORANGE_G_SLOPE), 0));
			}
		} else {
			if (data->color_id == 'p') {
				// is purple
				win.setPixelColor(pixel, Color(floor_0((float)data->i * PURPLE_R_SLOPE), 0, floor_0((float)data->i * PURPLE_B_SLOPE)));
			} else if (data->color_id == 'o') {
				// is orange
				win.setPixelColor(pixel, Color(floor_0((float)data->i * ORANGE_R_SLOPE), floor_0((float)data->i * ORANGE_G_SLOPE), 0));
			}

			if (data->increasing) {
				if (data->i >= 254) {
					(data->i) -= 2;
					data->increasing = false;
				} else {
					(data->i) += 2;
				}
			} else {
				if (data->i <= 1) {
					data->color_id = 'x';
				} else {
					(data->i) -= 2;
				}
			}
		}
	}
}
