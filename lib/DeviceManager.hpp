#ifndef DEVICE_MANAGER_HPP_
#define DEVICE_MANAGER_HPP_

#include <StandardCplusplus.h>
#include <vector>

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
	Device* getDevice(unsigned int id) const;

	Device* operator[] (int id) const;
};

#endif
