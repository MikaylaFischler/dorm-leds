#include "DeviceManager.hpp"

// add a device to the system
void DeviceManager::mount(Device* dev) {
	// add device
	this->devices.push_back(dev);

	// log to console
	Serial.print(F("DeviceManager.cpp:> Device Mounted: "));
	Serial.print(dev->getName());
	Serial.print(F(", occupying "));
	Serial.print(mem_available - freeMemory());
	Serial.println(F(" bytes of SRAM"));

	// update global free memory
	mem_available = freeMemory();
}

// remove a device from the system
template <typename dev_type>
void DeviceManager::unmount(int id) {
	// log to console
	Serial.print(F("DeviceManager.cpp:> Device Unmounted: "));
	Serial.println(this->devices[id]->getName());

	delete this->devices.getDevice<dev_type*>(id);
	this->devices.erase(this->devices.begin() + id);
}

// get the number of devices present
unsigned int DeviceManager::getNumDevices() const { return this->devices.size(); }

// return a vector of the devices (by value)
vector<Device*> DeviceManager::listDevices() const { return this->devices; };

// get a device (with bounds check)
template <typename dev_type>
dev_type* DeviceManager::getDevice(unsigned int id) const {
	if (id < this->devices.size()) {
		return reinterpret_cast<dev_type*>(this->devices[id]);
	} else {
		return NULL;
	}
}

// get a device with the overloaded [] operator
Device* DeviceManager::operator[] (int id) const { return this->getDevice<Device>(id); }
