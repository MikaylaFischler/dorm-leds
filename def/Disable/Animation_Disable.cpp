#include "Animation_Disable.hpp"

/* ~~~ Animation Disable ~~~ */

void Animation_Disable::init() {
    Animation::init();
    this->update_rate = 1;
    this->max_exec = 1;
    this->strips.push_back(id);
	this->name = npsm.name(id) + F(": Off");
}

void Animation_Disable::step() {
    for (int i = 0; i < npsm[id]->numPixels(); i++) {
        npsm[i]->setPixelColor(i, COLOR_OFF);
    }

    npsm[i]->show();

	this->current_exec++;
}
