#ifndef IODEVICE_HPP_
#define IODEVICE_HPP_

#include "../lib/Device.hpp"

class IODevice : public Device {
protected:
	int port;
	int value;
public:
	IODevice();
	IODevice(String name, int port, unsigned int type);
	virtual ~IODevice();

	virtual void write(int value) = 0;
	virtual int read() = 0;
};

#endif
