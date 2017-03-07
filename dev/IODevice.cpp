#include "IODevice.hpp"

// <<constructors>>
IODevice::IODevice(String name, int port, unsigned int type) : Device(name, type), value(0) {
	this->port = port;
}

// <<destructor>>
IODevice::~IODevice() {}
