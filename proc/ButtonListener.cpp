#include "ButtonListener.hpp"

// <<constructors>>
// store the pointer to the function that reports buttons state
ButtonListener::ButtonListener(int (*buttonCheck) (void)) : invert(false) {
	this->read = &buttonCheck;
	this->init();
}

// store the pointer to the function that reports buttons state and option to invert
ButtonListener::ButtonListener(int (*buttonCheck) (void), bool invertButton) : invert(invertButton) {
	this->read = &buttonCheck;
	this->init();
}

// initialize by storing a pointer to the function that will tell us button state
void ButtonListener::init() {
	triggered = false;
	last_state = read();
}

// step the process; in this case: check button state and record it
// logically; invert is to be used as the false keyword,
// as it will create proper output for inverted/not inverted buttons
void ButtonListener::step() {
	if (last_state == invert && read() == !invert) {
		triggered = true;
	}

	last_state = read();

	if (last_state == HIGH) {
		state = !invert;
	} else {
		state = invert;
	}
}

// return a boolean value of the button
// logically; invert is to be used as the false keyword,
// as it will create proper output for inverted/not inverted buttons
bool ButtonListener::isPressed() const { return state; }

// returns whether the button has changed from not active to active since last checked
// useful to get a single click instead of a 'while active' type logic
// logically; invert is to be used as the false keyword,
// as it will create proper output for inverted/not inverted buttons
bool ButtonListener::wasPressed() {
	bool tmp = triggered;
	triggered = false;
	return tmp;
}
