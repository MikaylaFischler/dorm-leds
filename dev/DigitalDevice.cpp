#include "DigitalDevice.hpp"

// <<constructors>>
DigitalDevice::DigitalDevice() : Device(F("NullDigitalDevice")), port(-1), type(-1), value(0) {}
DigitalDevice::DigitalDevice(String name, int port, int type) : Device(name), value(0) {
	this->port = port;
	this->type = type;
	pinMode(port, type);
}

// <<destructor>>
DigitalDevice::~DigitalDevice() {}

// write to the digital device
void DigitalDevice::write(int value) {
	if (this->type == OUTPUT && this->port >= 0) {
		digitalWrite(this->port, value);
		this->value = value;
	}
}

// read this digital device
int DigitalDevice::read() {
	if ((this->type == INPUT || this->type == INPUT_PULLUP) && this->port >= 0) {
		digitalRead(this->port);
	} else {
		return this->value;
	}
}
