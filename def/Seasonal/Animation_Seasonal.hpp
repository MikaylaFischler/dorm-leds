#ifndef Animation_Seasonal_H
#define Animation_Seasonal_H

#include "../../lib/Animation.hpp"

class Animation_Seasonal : public Animation {
protected:
    Animation_Seasonal() {}
    ~Animation_Seasonal() {}
public:
    void init();
};

class Animation_Seasonal_Winter_WindowSnow : public Animation_Seasonal {
public:
    Animation_Seasonal_Winter_WindowSnow(Adafruit_NeoPixel* strip);
    ~Animation_Seasonal_Winter_WindowSnow() {}

	void init();
	void step();
	void clean();
private:
	Adafruit_NeoPixel* strip;
};

class Animation_Seasonal_Spring_ClearSkyFade : public Animation_Seasonal {
public:
    Animation_Seasonal_Spring_ClearSkyFade(Adafruit_NeoPixel* strip);
    ~Animation_Seasonal_Spring_ClearSkyFade() {}

	void init();
	void step();
	void clean();
private:
	Adafruit_NeoPixel* strip;
};

#endif
