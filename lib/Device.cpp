#include "Device.hpp"

// <<constructor>>
Device::Device(String name, unsigned int type) : name(name), type(type) {}

// <<destructor>>
Device::~Device() {}

// get the name of the device
String Device::getName() const { return this->name; }

// get the type of the device
unsigned int Device::getType() const { return this->type; }
