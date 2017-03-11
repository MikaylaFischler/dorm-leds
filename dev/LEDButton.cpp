#include "LEDButton.hpp"

// <<constructor>>
LEDButton::LEDButton(String name, int led_port, int button_port) : Device(name, DEV_LED_PUSH_BUTTON),
								led(led_port), button(button_port) {
	pinMode(led_port, OUTPUT);
	pinMode(button_port, INPUT);
}

// <<destructor>>
LEDButton::~LEDButton() {}

// light the led
void LEDButton::setLED(int value) {
	digitalWrite(led, value);
}

// read the button
int LEDButton::read() const {
	return digitalRead(button);
}
