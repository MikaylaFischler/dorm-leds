#include "Animation_Disable.hpp"

/* ~~~ Generic Disable ~~~ */

// define the generic disable init
void Animation_Disable::init() {
    Animation::init();
    this->num_strips = 1;
    this->update_rate = 1;
    this->max_exec = 1;
}

/* ~~~ Animation Disable: Desk 1 ~~~ */

void Animation_Disable_Desk1::init() {
    Animation_Disable::init();
    this->name = F("Desk[1]: Off");
    this->strips = BOTTOM_DESK;
}

void Animation_Disable_Desk1::step() {
    for (int i = 0; i < DESK1_LENGTH; i++) {
        desk1.setPixelColor(i, COLOR_OFF);
    }

    desk1.show();
}

/* ~~~ Animation Disable: Desk 2 ~~~ */

void Animation_Disable_Desk2::init() {
    Animation_Disable::init();
    this->name = F("Desk[2]: Off");
    this->strips = TOP_DESK;
}

void Animation_Disable_Desk2::step() {
    for (int i = 0; i < DESK2_LENGTH; i++) {
        desk1.setPixelColor(i, COLOR_OFF);
    }

    desk2.show();
}

/* ~~~ Animation Disable: Window 1 ~~~ */

void Animation_Disable_Window1::init() {
    Animation_Disable::init();
    this->name = F("Window[1]: Off");
    this->strips = WINDOW_1;
}

void Animation_Disable_Window1::step() {
    for (int i = 0; i < WINDOW_LENGTH; i++) {
        window1.setPixelColor(i, COLOR_OFF);
    }

    window1.show();
}

/* ~~~ Animation Disable: Window 2 ~~~ */

void Animation_Disable_Window2::init() {
    Animation_Disable::init();
    this->name = F("Window[2]: Off");
    this->strips = WINDOW_2;
}

void Animation_Disable_Window2::step() {
    for (int i = 0; i < WINDOW_LENGTH; i++) {
        window2.setPixelColor(i, COLOR_OFF);
    }

    window2.show();
}

/* ~~~ Animation Disable: Window 3 ~~~ */

void Animation_Disable_Window3::init() {
    Animation_Disable::init();
    this->name = F("Window[3]: Off");
    this->strips = WINDOW_3;
}

void Animation_Disable_Window3::step() {
    for (int i = 0; i < WINDOW_LENGTH; i++) {
        window3.setPixelColor(i, COLOR_OFF);
    }

    window3.show();
}
