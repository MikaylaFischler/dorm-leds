#ifndef DIGITALDEVICE_HPP_
#define DIGITALDEVICE_HPP_

#include "../lib/Device.hpp"

class DigitalDevice : public Device {
protected:
	int port;
	int type;
	int value;
public:
	DigitalDevice(void);
	DigitalDevice(String name, int port, int type);
	virtual ~DigitalDevice(void);

	void write(int value);
	int read(void);
};

#endif
