#ifndef ANALOGDEVICE_HPP_
#define ANALOGDEVICE_HPP_

#include "IODevice.hpp"

class AnalogDevice : public IODevice {
public:
	AnalogDevice(String name, int port, unsigned int type);
	virtual ~AnalogDevice();

	virtual void write(int value);
	virtual int read();
};

#endif
