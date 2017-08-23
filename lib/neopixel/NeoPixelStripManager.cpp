#include "NeoPixelStripManager.hpp"

// add a new strip to the manager
NeoPixelStripManager::addStrip(String name, bool rgbw, Adafruit_NeoPixel* strip) {
	strip_data* d = new strip_data;

	d->name = name;
	d->rgbw = rgbw;
	d->in_use = false;
	d->used_by = NULL;

	this->strips.push_back(strip);
	this->data.push_back(d);
}

// drop a strip from the manager
NeoPixelStripManager::dropStrip(int id) {
	delete this->strips.at(id);
	delete this->data.at(id);

	strips.erase(strips.begin() + id);
	data.erase(data.begin() + id);
}

//check how many strips in the manager
int NeoPixelStripManager::numStrips() const { return this->strips.size(); };

// get strip name
String NeoPixelStripManager::name(int id) const { return this->data.at(id)->name; }

// get if RGBW
bool NeoPixelStripManager::isRGBW(int id) const { return this->data.at(id)->rgbw; }

// get if in use
bool NeoPixelStripManager::inUse(int id) const { return this->data.at(id)->in_use; }

// get what used by
Animation* NeoPixelStripManager::usedBy(int id) const { return this->data.at(id)->used_by; }

// get the strip
Adafruit_NeoPixel* NeoPixelStripManager::strip(int id) { return this->strips.at(id); }

// get the strip with the [] operator
Adafruit_NeoPixel* NeoPixelStripManager::operator[] (int id) { return this->strips.at(id); }

// set strip as used
void NeoPixelStripManager::use(int id, Animation* anim) {
	this->data.at(id)->used_by = anim;
	this->data.at(id)->in_use = true;
}

// release a strip from being used
void NeoPixelStripManager::release(int id) {
	this->data.at(id)->used_by = NULL;
	this->data.at(id)->in_use = false;
}
