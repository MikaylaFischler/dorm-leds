#include "DigitalDevice.hpp"

// <<constructors>>
DigitalDevice::DigitalDevice() : Device(F("NullDigitalDevice")), port(-1), io_type(-1), value(0) {}
DigitalDevice::DigitalDevice(String name, int port, int io_type, unsigned int type) : Device(name, type), value(0) {
	this->port = port;
	this->io_type = io_type;
	pinMode(port, io_type);
}

// <<destructor>>
DigitalDevice::~DigitalDevice() {}

// write to the digital device
void DigitalDevice::write(int value) {
	if (this->io_type == OUTPUT && this->port >= 0) {
		digitalWrite(this->port, value);
		this->value = value;
	}
}

// read this digital device
int DigitalDevice::read() {
	if ((this->io_type == INPUT || this->io_type == INPUT_PULLUP) && this->port >= 0) {
		return digitalRead(this->port);
	} else {
		return this->value;
	}
}
