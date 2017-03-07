#ifndef DEVICE_HPP_
#define DEVICE_HPP_

#include <Arduino.h>

class Device {
protected:
	const String name;
	Device(void);
	Device(String name);
public:
	virtual ~Device(void);

	String getName(void);
};

#endif
