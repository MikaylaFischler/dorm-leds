#include "Animation_Simple.hpp"

/* ~~~ Generic Simple ~~~ */

// define the generic simple init
void Animation_Simple::init() {
  	Animation::init();
  	this->max_exec = -1;
}

/* ~~~ Animation Simple: Desk Both Off White/Purple Fade ~~~ */

void Animation_Simple_WhitePurpleFade::init() {
 	Animation_Simple::init();
 	this->name = F("Desk[all]: Off White with Purple Fade");
 	this->strips = FULL_DESK;

	this->stack = LocalStack();
	this->stack.push(MemObj(new unsigned short int(0)));
	this->stack.push(MemObj(new bool(true)));
}

void Animation_Simple_WhitePurpleFade::step() {
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
