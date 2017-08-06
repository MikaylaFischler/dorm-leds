#include "Animation_Simple.hpp"

/* ~~~ Generic Individual ~~~ */

// define the generic individual init
void Animation_Simple_Indiv::init() {
  	Animation_Simple::init();
	this->num_strips = 1;
	this->name = getNameOfStrip(this->strip);
	this->strips = getAsStripArray(this->strip);
}

/* ~~~ Animation Simple Individual: Calm Purple Fade ~~~ */

void Animation_Simple_Indiv_CalmPurpleFade::init() {
	Animation_Simple_Indiv::init();
	this->name += F(": Purple Fade");
    this->update_rate = 10;

	i = 0;
	increasing = true;
}

void Animation_Simple_Indiv_CalmPurpleFade::step() {
	for (unsigned int x = 0; x < this->strip->numPixels(); x++) {
		this->strip->setPixelColor(x, Color((int)(((float)i / 150.0) * 100), 0, i));
	}

	this->strip->show();

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

/* ~~~ Animation Simple Individual: Strip Color Flash ~~~ */

void Animation_Simple_Indiv_ColorFlash::init() {
	Animation_Simple_Indiv::init();
	this->name += F(": Color Flash");
    this->update_rate = this->rate;

	mode = true;
}

void Animation_Simple_Indiv_ColorFlash::step() {
	// set each led to the proper color
	for (unsigned int j = 0; j < strip->numPixels(); j++) {
		if (mode) {
			this->strip->setPixelColor(j, this->color);
		} else {
			this->strip->setPixelColor(j, COLOR_OFF);
		}
	}

	this->strip->show();

	if (mode) {
		mode = false;
	} else {
		mode = true;
		this->current_exec++;
	}
}

/* ~~~ Animation Simple Individual: Strip Alternating Color Flash ~~~ */

void Animation_Simple_Indiv_AlternatingColorFlash::init() {
	Animation_Simple_Indiv::init();
	this->name += F(": Color Flash");
    this->update_rate = this->rate;

	mode = true;
	cur_color = true;
}

void Animation_Simple_Indiv_AlternatingColorFlash::step() {
	// set each led to the proper color
	for (unsigned int j = 0; j < this->strip->numPixels(); j++) {
		if (mode) {
			if (cur_color) {
				this->strip->setPixelColor(j, this->color_a);
			} else {
				this->strip->setPixelColor(j, this->color_b);
			}
		} else {
			this->strip->setPixelColor(j, COLOR_OFF);
		}
	}

	this->strip->show();

	if (mode) {
		mode = false;
		cur_color = !cur_color;
	} else {
		mode = true;
		this->current_exec++;
	}
}

/* ~~~ Animation Simple Individual: Strip Color Fade ~~~ */

void Animation_Simple_Indiv_ColorFade::init() {
	Animation_Simple_Indiv::init();
	this->name += F(": Color Fade");
    this->update_rate = 30;

	i = 0;
	increasing = true;
}

void Animation_Simple_Indiv_ColorFade::step() {
	// set each led to the proper color
	for (unsigned int j = 0; j < this->strip->numPixels(); j++) {
		this->strip->setPixelColor(j, round(redFromColor(this->color) * i/255.0), round(greenFromColor(this->color) * i/255.0), round(blueFromColor(this->color) * i/255.0));
	}

	this->strip->show();

	if (increasing) {
		if (i == 255) {
			increasing = false;
		} else {
			i++;
		}
	} else {
		if (i == 0) {
			increasing = true;
			this->current_exec++;
		} else {
			i--;
		}
	}
}

/* ~~~ Animation Simple Individual: Theater Chase ~~~ */

void Animation_Simple_Indiv_TheaterChase::init() {
	Animation_Simple_Indiv::init();
	this->name += F(": Theater Chase");
    this->update_rate = 35;

	i = 0;
	alternate = true;
}

void Animation_Simple_Indiv_TheaterChase::step() {
	if (alternate) {
		// set each led to the proper color
		for (unsigned int j = 0; j < this->strip->numPixels(); j += 3) {
			// turn every third pixel on
			this->strip->setPixelColor(j + i, this->color);
		}

		this->strip->show();
	} else {
		for (unsigned int j = 0; j < this->strip->numPixels(); j += 3) {
			// turn every third pixel off
			this->strip->setPixelColor(j + i, COLOR_OFF);
		}
	}

	alternate = !alternate;

	if (i < 2 && alternate) {
		i++;
	} else if (i == 2 && alternate) {
		i = 0;
		this->current_exec++;
	}
}
