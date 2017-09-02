#ifndef DEVICE_MANAGER_HPP_
#define DEVICE_MANAGER_HPP_

#include <Arduino.h>
#include <ArduinoSTL.h>
#include <vector>

#include "../../util/free_memory.h"

using std::vector;

class DeviceManager {
private:
	vector<Device*> devices;
public:
	DeviceManager() {}
	~DeviceManager() {}

	void mount(Device* dev);
	template <typename dev_type> void unmount(int id);

	unsigned int getNumDevices() const;
	vector<Device*> listDevices() const;

	template <typename dev_type> dev_type* getDevice(unsigned int id) const;

	Device* operator[] (int id) const;
};

#endif
