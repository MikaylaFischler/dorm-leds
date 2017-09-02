#ifndef ANIMATION_SEASONAL_HPP_
#define ANIMATION_SEASONAL_HPP_

#include "../../lib/exe/Animation.hpp"

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
    Animation_Seasonal_Indiv(int _id) : id(_id) {}
    ~Animation_Seasonal_Indiv() {}

    void init();

	int id;
};

// Animation_Seasonal_Spring.cpp

class Animation_Seasonal_Indiv_Spring_ClearSkyFade : public Animation_Seasonal_Indiv {
private:
	unsigned int i;
	bool increasing;

	static const int MAX_RED = 200;
	static const int MAX_GREEN = 180;
	static const int BLUE = 255;
public:
    Animation_Seasonal_Indiv_Spring_ClearSkyFade(int id) : Animation_Seasonal_Indiv(id) {}
    ~Animation_Seasonal_Indiv_Spring_ClearSkyFade() {}

	void init();
	void step();
};

class Animation_Seasonal_Indiv_Spring_WindowColors : public Animation_Seasonal_Indiv {
private:
	unsigned int i;
	unsigned short int color;
	bool increasing;
public:
    Animation_Seasonal_Indiv_Spring_WindowColors(int id) : Animation_Seasonal_Indiv(id) {}
    ~Animation_Seasonal_Indiv_Spring_WindowColors() {}

	void init();
	void step();
};

class Animation_Seasonal_Indiv_Spring_ColorWipe : public Animation_Seasonal_Indiv {
private:
	unsigned short int i;
	unsigned short int color_mode;
public:
    Animation_Seasonal_Indiv_Spring_ColorWipe(int id) : Animation_Seasonal_Indiv(id) {}
    ~Animation_Seasonal_Indiv_Spring_ColorWipe() {}

	void init();
	void step();
};

// Animation_Seasonal_Winter.cpp

// Animation_Seasonal_Weather.cpp

class Animation_Seasonal_Indiv_Weather : public Animation_Seasonal_Indiv {
protected:
	int i;
	bool randomized_spacing;
	short int left_spacing;
	short int right_spacing;

	void precipitation_init(int update_rate);
	void precipitation_step(int min_spacing, int max_spacing, long unsigned int color);

	Animation_Seasonal_Indiv_Weather(int id) : Animation_Seasonal_Indiv(id) {}
    ~Animation_Seasonal_Indiv_Weather() {}
};

class Animation_Seasonal_Indiv_Weather_WindowLightRain : public Animation_Seasonal_Indiv_Weather {
public:
    Animation_Seasonal_Indiv_Weather_WindowLightRain(int id) : Animation_Seasonal_Indiv_Weather(id) {}
    ~Animation_Seasonal_Indiv_Weather_WindowLightRain() {}

	void init();
	void step();
};

class Animation_Seasonal_Indiv_Weather_WindowRain : public Animation_Seasonal_Indiv_Weather {
public:
    Animation_Seasonal_Indiv_Weather_WindowRain(int id) : Animation_Seasonal_Indiv_Weather(id) {}
    ~Animation_Seasonal_Indiv_Weather_WindowRain() {}

	void init();
	void step();
};

class Animation_Seasonal_Indiv_Weather_WindowHeavyRain : public Animation_Seasonal_Indiv_Weather {
public:
    Animation_Seasonal_Indiv_Weather_WindowHeavyRain(int id) : Animation_Seasonal_Indiv_Weather(id) {}
    ~Animation_Seasonal_Indiv_Weather_WindowHeavyRain() {}

	void init();
	void step();
};

class Animation_Seasonal_Indiv_Weather_WindowLightSnow : public Animation_Seasonal_Indiv_Weather {
public:
    Animation_Seasonal_Indiv_Weather_WindowLightSnow(int id) : Animation_Seasonal_Indiv_Weather(id) {}
    ~Animation_Seasonal_Indiv_Weather_WindowLightSnow() {}

	void init();
	void step();
};

class Animation_Seasonal_Indiv_Weather_WindowSnow : public Animation_Seasonal_Indiv_Weather {
public:
    Animation_Seasonal_Indiv_Weather_WindowSnow(int id) : Animation_Seasonal_Indiv_Weather(id) {}
    ~Animation_Seasonal_Indiv_Weather_WindowSnow() {}

	void init();
	void step();
};

class Animation_Seasonal_Indiv_Weather_WindowHeavySnow : public Animation_Seasonal_Indiv_Weather {
public:
    Animation_Seasonal_Indiv_Weather_WindowHeavySnow(int id) : Animation_Seasonal_Indiv_Weather(id) {}
    ~Animation_Seasonal_Indiv_Weather_WindowHeavySnow() {}

	void init();
	void step();
};

#endif
