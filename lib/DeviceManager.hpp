#ifndef DEVICE_MANAGER_HPP_
#define DEVICE_MANAGER_HPP_

#include <Arduino.h>
#include <StandardCplusplus.h>
#include <vector>

#include "../util/mem.c"
#include "../util/free_memory.h"

class DeviceManager {
private:
	std::vector<Device*> devices;
public:
	DeviceManager();
	~DeviceManager();

	void mount(Device* dev);
	void unmount(int id);
	unsigned int getNumDevices() const;

	std::vector<Device*> listDevices() const;
	template <typename dev_type> dev_type* getDevice(unsigned int id) const;

	Device* operator[] (int id) const;
};

#endif
