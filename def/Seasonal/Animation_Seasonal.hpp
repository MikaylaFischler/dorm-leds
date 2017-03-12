#ifndef ANIMATION_SEASONAL_HPP_
#define ANIMATION_SEASONAL_HPP_

#include "../../lib/Animation.hpp"

class Animation_Seasonal : public Animation {
protected:
    Animation_Seasonal() {}
    ~Animation_Seasonal() {}

    void init();
};

class Animation_Seasonal_Indiv : public Animation_Seasonal {
protected:
    Animation_Seasonal_Indiv() {}
    ~Animation_Seasonal_Indiv() {}

    void init();

	Adafruit_NeoPixel* strip;
};

// Animation_Seasonal_Winter.cpp

class Animation_Seasonal_Indiv_Winter_WindowSnow : public Animation_Seasonal_Indiv {
public:
    Animation_Seasonal_Indiv_Winter_WindowSnow(Adafruit_NeoPixel* strip);
    ~Animation_Seasonal_Indiv_Winter_WindowSnow() {}

	void init();
	void step();
	void clean();
};

// Animation_Seasonal_Spring.cpp

class Animation_Seasonal_Indiv_Spring_ClearSkyFade : public Animation_Seasonal_Indiv {
public:
    Animation_Seasonal_Indiv_Spring_ClearSkyFade(Adafruit_NeoPixel* strip);
    ~Animation_Seasonal_Indiv_Spring_ClearSkyFade() {}

	void init();
	void step();
	void clean();
};

#endif
