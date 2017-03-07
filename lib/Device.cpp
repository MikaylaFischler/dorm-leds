#include "Device.hpp"

// <<constructors>>
Device::Device() : name(F("NullDevice")) {}
Device::Device(String name) : name(name) {}

// <<destructor>>
Device::~Device() {}

// get the name of the device
String Device::getName() { return this->name; }
