#include "LEDButton.hpp"

// <<constructors>>
LEDButton::LEDButton(String name, int port_led, int port_button) : Device(name, DEV_LED_PUSH_BUTTON) {
	this->led = new DigitalDevice(name + F(": LED"), port_led, OUTPUT, DEV_LED);
	this->button = new DigitalDevice(name + F(": Button"), port_button, INPUT, DEV_PUSH_BUTTON);
}

// <<destructor>>
LEDButton::~LEDButton() {
	delete this->led;
	delete this->button;
}

// write to the digital device
void LEDButton::setLED(int value) {
	this->led->write(value);
}

// read this digital device
int LEDButton::read() {
	return this->button->read();
}
