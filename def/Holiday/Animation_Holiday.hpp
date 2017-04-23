#ifndef ANIMATION_HOLIDAY_HPP_
#define ANIMATION_HOLIDAY_HPP_

#include "../../lib/Animation.hpp"

class Animation_Holiday : public Animation {
protected:
    Animation_Holiday() {}
    ~Animation_Holiday() {}

    void init();
};

// Animation_Holiday_Indiv.cpp

class Animation_Holiday_Indiv : public Animation_Holiday {
protected:
    Animation_Holiday_Indiv(Adafruit_NeoPixel* strip);
    ~Animation_Holiday_Indiv() {}

    void init();

	Adafruit_NeoPixel* strip;
};

class Animation_Holiday_Indiv_EarthDay_Fade : public Animation_Holiday_Indiv {
public:
    Animation_Holiday_Indiv_EarthDay_Fade(Adafruit_NeoPixel* strip) : Animation_Holiday_Indiv(strip) {}
    ~Animation_Holiday_Indiv_EarthDay_Fade() {}

	void init();
    void step();
	void clean();
};

// Animation_Holiday.cpp

class Animation_Holiday_EarthDay_WinAllFade : public Animation_Holiday {
public:
    Animation_Holiday_EarthDay_WinAllFade() {}
    ~Animation_Holiday_EarthDay_WinAllFade() {}

	void init();
    void step();
	void clean();
};

// Animation_Holiday_Halloween.cpp

class Animation_Holiday_Halloween_WinAllFade : public Animation_Holiday {
public:
    Animation_Holiday_Halloween_WinAllFade() {}
    ~Animation_Holiday_Halloween_WinAllFade() {}

	void init();
    void step();
	void clean();
};

class Animation_Holiday_Halloween_WinAllHalloweenSparkle : public Animation_Holiday {
private:
	unsigned long int rand_halloween_color();
	void sparkle_fade(bool*& inc);
	unsigned int floor_0(float x);
public:
	Animation_Holiday_Halloween_WinAllHalloweenSparkle() {}
	~Animation_Holiday_Halloween_WinAllHalloweenSparkle() {}

	void init();
	void step();
	void clean();
};

// Animation_Holiday_Christmas.cpp

class Animation_Holiday_Christmas_Win13Snow : public Animation_Holiday {
private:
	void christmas_snow(int i, int left_spacing, int right_spacing);
public:
	Animation_Holiday_Christmas_Win13Snow() {}
	~Animation_Holiday_Christmas_Win13Snow() {}

	void init();
	void step();
	void clean();
};

// Animation_Holiday_Hanukkah.cpp

class Animation_Holiday_Hanukkah_Win2Snow : public Animation_Holiday {
private:
	void hanukkah_snow(int i, int left_spacing, int right_spacing);
public:
	Animation_Holiday_Hanukkah_Win2Snow() {}
	~Animation_Holiday_Hanukkah_Win2Snow() {}

	void init();
	void step();
	void clean();
};

#endif
