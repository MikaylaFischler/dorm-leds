#ifndef DIGITALDEVICE_HPP_
#define DIGITALDEVICE_HPP_

#include "../lib/Device.hpp"

class DigitalDevice : public Device {
protected:
	int port;
	int io_type;
	int value;
public:
	DigitalDevice();
	DigitalDevice(String name, int port, int io_type, unsigned int type);
	virtual ~DigitalDevice();

	virtual void write(int value);
	virtual int read();
};

#endif
