#include "Animation_Seasonal.hpp"

/* ~~~ Animation Seasonal Individual Spring: Clear Sky Blue Color Fade */

void Animation_Seasonal_Indiv_Spring_ClearSkyFade::init() {
 	Animation_Seasonal_Indiv::init();
 	this->name = F("Clear Skies");
	this->update_rate = 50;

	i = 0;
	increasing = true;
}

void Animation_Seasonal_Indiv_Spring_ClearSkyFade::step() {
	// step animation
	for (uint16_t x = 0; x < npsm[this->id]->numPixels(); x++) {
		npsm[this->id]->setPixelColor(x, MAX_RED - i, MAX_GREEN - i, BLUE);
	}

	npsm[this->id]->show();

	if (increasing) {
		if (i >= 150) {
			i--;
			increasing = false;
		} else {
			i++;
		}
	} else {
		if (i <= 0) {
			i++;
			increasing = true;
      		this->current_exec++;
		} else {
			i--;
		}
	}

}

/* ~~~ Animation Seasonal Spring: Window Spring Colors */

void Animation_Seasonal_Indiv_Spring_WindowColors::init() {
 	Animation_Seasonal_Indiv::init();
 	this->name = F("Spring Colors");
	this->update_rate = 5;

	i = 0;
	color = random(0,4);
	increasing = true;
}

void Animation_Seasonal_Indiv_Spring_WindowColors::step() {
	// step animation
	unsigned long int c = 0;

	switch (color) {
		case 0: // violet
			c = Color(round(175.0 * (i / 255.0)), 0, i);
			break;
		case 1: // yellow
			c = Color(i, round(150.0 * (i / 255.0)), 0);
			break;
		case 2: // green
			c = Color(0, i, 0);
			break;
		case 3: // sky blue
			c = Color(0, i, round(230.0 * (i / 255.0)));
			break;
	}

	for (uint16_t x = 0; x < WINDOW_LENGTH; x++) {
		npsm[this->id]->setPixelColor(x, c);
	}

	npsm[this->id]->show();

	if (increasing) {
		if (i >= 255) {
			i--;
			increasing = false;
		} else {
			i++;
		}
	} else {
		if (i <= 0) {
			i++;
			increasing = true;

			// re-randomize
			color = random(0,4);

      		this->current_exec++;
		} else {
			i--;
		}
	}
}

/* ~~~ Animation Seasonal Individual Spring: Spring Color Chase */

void Animation_Seasonal_Indiv_Spring_ColorWipe::init() {
 	Animation_Seasonal_Indiv::init();
 	this->name = F("Spring Color Fade");
	this->update_rate = 35;

	i = 0;
	color_mode = 0;
}

void Animation_Seasonal_Indiv_Spring_ColorWipe::step() {
	// start wiping the current color
	if (color_mode == 0) {
		npsm[this->id]->setPixelColor(i, COLOR_PURPLE);
	} else if (color_mode == 1) {
		npsm[this->id]->setPixelColor(i, COLOR_YELLOW);
	} else if (color_mode == 2) {
		npsm[this->id]->setPixelColor(i, COLOR_GREEN);
	} else if (color_mode == 3) {
		npsm[this->id]->setPixelColor(i, COLOR_LIGHT_BLUE_GREEN);
	}

    npsm[this->id]->show();

    i++;

	if (i == npsm[this->id]->numPixels()) {
		color_mode++;
		i = 0;

		if (color_mode == 4) {
			color_mode = 0;
			this->current_exec++;
		}
	}
}
