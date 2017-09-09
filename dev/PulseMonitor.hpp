#ifndef PULSEMONITOR_HPP_
#define PULSEMONITOR_HPP_

/*
 *	Device code for Pulse Monitor (http://pulsemonitor.com)
 */

#include <Arduino.h>

#include "../lib/device/Device.hpp"

class PulseMonitor : public Device {
private:
	static const int PULSE_THRESHOLD = 550;
	const int data_port;
public:
	PulseMonitor(String name, int port) : Device(name, DEV_PULSEMON), data_port(port) {}
	virtual ~PulseMonitor() {}

	bool beat() const;
	int read() const;
};

#endif
