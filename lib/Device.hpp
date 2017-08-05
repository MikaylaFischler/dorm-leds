#ifndef DEVICE_HPP_
#define DEVICE_HPP_

#include <Arduino.h>
#include "../conf/dev_types.h"

class Device {
protected:
	const String name;
	const unsigned int type;

	Device(String name, unsigned int type);
public:
	virtual ~Device();

	String getName() const;
	unsigned int getType() const;
};

#endif
