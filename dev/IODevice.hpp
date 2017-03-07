#ifndef IODEVICE_HPP_
#define IODEVICE_HPP_

#include "../lib/Device.hpp"

class IODevice : public Device {
protected:
	int port;
	int value;
	
	IODevice(String name, int port, unsigned int type);
public:
	virtual ~IODevice();

	virtual void write(int value) = 0;
	virtual int read() = 0;
};

#endif
