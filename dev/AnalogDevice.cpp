#include "AnalogDevice.hpp"

// <<constructors>>
AnalogDevice::AnalogDevice() : IODevice(F("NullAnalogDevice"), -1, 0) {}
AnalogDevice::AnalogDevice(String name, int port, unsigned int type) : IODevice(name, port, type) {}

// <<destructor>>
AnalogDevice::~AnalogDevice() {}

// write to the analog device (0 to 255)
void AnalogDevice::write(int value) {
	analogWrite(this->port, value);
}

// read this analog device (0 - 1023)
int AnalogDevice::read() {
	return analogRead(this->port);
}
