#ifndef DIGITALDEVICE_HPP_
#define DIGITALDEVICE_HPP_

#include "IODevice.hpp"

class DigitalDevice : public IODevice {
protected:
	int io_type;
public:
	DigitalDevice(String name, int port, int io_type, unsigned int type);
	virtual ~DigitalDevice();

	virtual void write(int value);
	virtual int read();
};

#endif
