#include "DeviceManager.hpp"

// <<constructor>>
DeviceManager::DeviceManager() {}

// <<destructor>>
DeviceManager::~DeviceManager() {}

// add a device to the system
void DeviceManager::mount(Device* dev) {
	this->devices.push_back(dev);

	Serial.print(F("DeviceManager.cpp:> Device Mounted: "));
	Serial.println(dev->getName());
	Serial.print(F(", occupying "));
	Serial.print(mem_available - freeMemory());
	Serial.println(F(" bytes of SRAM"));

	mem_available = freeMemory();
}

// remove a device from the system
void DeviceManager::unmount(int id) {
	Serial.print(F("DeviceManager.cpp:> Device Unmounted: "));
	Serial.println(this->devices.at(this->devices.begin() + id)->getName());

	this->devices.erase(this->devices.begin() + id);
}

// get the number of devices present
unsigned int DeviceManager::getNumDevices() const { return this->devices.size(); }

// return a vector of the devices (by value)
std::vector<Device*> DeviceManager::listDevices() const { return this->devices; };

// get a device (with bounds check)
Device* DeviceManager::getDevice(unsigned int id) const {
	if (id < this->devices.size()) {
		return this->devices[id];
	} else {
		return NULL;
	}
}

// get a device with the overloaded [] operator
Device* DeviceManager::operator[] (int id) const { return this->getDevice(id); }
