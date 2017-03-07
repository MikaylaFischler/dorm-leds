#include "IODevice.hpp"

// <<constructors>>
IODevice::IODevice() : Device(F("NullIODevice")), port(-1), value(0) {}
IODevice::IODevice(String name, int port, unsigned int type) : Device(name, type), value(0) {
	this->port = port;
}

// <<destructor>>
IODevice::~IODevice() {}
