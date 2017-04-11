#ifndef ANIMATION_SEASONAL_HPP_
#define ANIMATION_SEASONAL_HPP_

#include "../../lib/Animation.hpp"

class Animation_Seasonal : public Animation {
protected:
    Animation_Seasonal() {}
    ~Animation_Seasonal() {}

    void init();
};

// there will be no files with Indiv in the name, this is just to reduce code and follow some of the Indiv implementation standards used in the other animations
// Each Animation_Seasonal_XXX.cpp can/will contain both Indiv and non-Indiv animations
class Animation_Seasonal_Indiv : public Animation_Seasonal {
protected:
    Animation_Seasonal_Indiv() {}
    ~Animation_Seasonal_Indiv() {}

    void init();

	Adafruit_NeoPixel* strip;
};

// Animation_Seasonal_Winter.cpp

// Animation_Seasonal_Spring.cpp

class Animation_Seasonal_Indiv_Spring_ClearSkyFade : public Animation_Seasonal_Indiv {
public:
    Animation_Seasonal_Indiv_Spring_ClearSkyFade(Adafruit_NeoPixel* strip);
    ~Animation_Seasonal_Indiv_Spring_ClearSkyFade() {}

	void init();
	void step();
	void clean();
};

class Animation_Seasonal_Indiv_Spring_WindowColors : public Animation_Seasonal_Indiv {
public:
    Animation_Seasonal_Indiv_Spring_WindowColors(Adafruit_NeoPixel* strip);
    ~Animation_Seasonal_Indiv_Spring_WindowColors() {}

	void init();
	void step();
	void clean();
};

class Animation_Seasonal_Indiv_Spring_ColorWipe : public Animation_Seasonal_Indiv {
public:
    Animation_Seasonal_Indiv_Spring_ColorWipe(Adafruit_NeoPixel* strip);
    ~Animation_Seasonal_Indiv_Spring_ColorWipe() {}

	void init();
	void step();
	void clean();
};

// Animation_Seasonal_Weather.cpp

class Animation_Seasonal_Indiv_Weather_WindowLightRain : public Animation_Seasonal_Indiv {
public:
    Animation_Seasonal_Indiv_Weather_WindowLightRain(Adafruit_NeoPixel* strip);
    ~Animation_Seasonal_Indiv_Weather_WindowLightRain() {}

	void init();
	void step();
	void clean();
};

class Animation_Seasonal_Indiv_Weather_WindowRain : public Animation_Seasonal_Indiv {
public:
    Animation_Seasonal_Indiv_Weather_WindowRain(Adafruit_NeoPixel* strip);
    ~Animation_Seasonal_Indiv_Weather_WindowRain() {}

	void init();
	void step();
	void clean();
};

class Animation_Seasonal_Indiv_Weather_WindowHeavyRain : public Animation_Seasonal_Indiv {
public:
    Animation_Seasonal_Indiv_Weather_WindowHeavyRain(Adafruit_NeoPixel* strip);
    ~Animation_Seasonal_Indiv_Weather_WindowHeavyRain() {}

	void init();
	void step();
	void clean();
};

class Animation_Seasonal_Indiv_Weather_WindowLightSnow : public Animation_Seasonal_Indiv {
public:
    Animation_Seasonal_Indiv_Weather_WindowLightSnow(Adafruit_NeoPixel* strip);
    ~Animation_Seasonal_Indiv_Weather_WindowLightSnow() {}

	void init();
	void step();
	void clean();
};

class Animation_Seasonal_Indiv_Weather_WindowSnow : public Animation_Seasonal_Indiv {
public:
    Animation_Seasonal_Indiv_Weather_WindowSnow(Adafruit_NeoPixel* strip);
    ~Animation_Seasonal_Indiv_Weather_WindowSnow() {}

	void init();
	void step();
	void clean();
};

class Animation_Seasonal_Indiv_Weather_WindowHeavySnow : public Animation_Seasonal_Indiv {
public:
    Animation_Seasonal_Indiv_Weather_WindowHeavySnow(Adafruit_NeoPixel* strip);
    ~Animation_Seasonal_Indiv_Weather_WindowHeavySnow() {}

	void init();
	void step();
	void clean();
};

#endif
