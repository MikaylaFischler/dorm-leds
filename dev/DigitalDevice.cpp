#include "DigitalDevice.hpp"

// <<constructor>>
DigitalDevice::DigitalDevice(String name, int port, int io_type, unsigned int type) : IODevice(name, port, type) {
	this->io_type = io_type;
	pinMode(port, io_type);
}

// <<destructor>>
DigitalDevice::~DigitalDevice() {}

// write to the digital device
void DigitalDevice::write(int value) {
	if (this->io_type == OUTPUT) {
		digitalWrite(this->port, value);
		this->value = value;
	}
}

// read this digital device
int DigitalDevice::read() {
	if (this->io_type == INPUT || this->io_type == INPUT_PULLUP) {
		return digitalRead(this->port);
	} else {
		return this->value;
	}
}
