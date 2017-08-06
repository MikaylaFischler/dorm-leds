#ifndef ANIMATION_HOLIDAY_HPP_
#define ANIMATION_HOLIDAY_HPP_

#include "../../lib/Animation.hpp"

class Animation_Holiday : public Animation {
protected:
    Animation_Holiday() {}
    ~Animation_Holiday() {}

    void init();
};

// Animation_Holiday.cpp

class Animation_Holiday_EarthDay_WinAllFade : public Animation_Holiday {
private:
	unsigned short int i;
	bool mode;
	bool increasing;
public:
    Animation_Holiday_EarthDay_WinAllFade() {}
    ~Animation_Holiday_EarthDay_WinAllFade() {}

	void init();
    void step();
};

// Animation_Holiday_Indiv.cpp

class Animation_Holiday_Indiv : public Animation_Holiday {
protected:
    Animation_Holiday_Indiv(Adafruit_NeoPixel* _strip) : strip(_strip) {}
    ~Animation_Holiday_Indiv() {}

    void init();

	Adafruit_NeoPixel* strip;
};

class Animation_Holiday_Indiv_EarthDay_Fade : public Animation_Holiday_Indiv {
private:
	unsigned short int i;
	bool mode;
	bool increasing;
public:
    Animation_Holiday_Indiv_EarthDay_Fade(Adafruit_NeoPixel* strip) : Animation_Holiday_Indiv(strip) {}
    ~Animation_Holiday_Indiv_EarthDay_Fade() {}

	void init();
    void step();
};

// Animation_Holiday_Halloween.cpp

class Animation_Holiday_Halloween_WinAllFade : public Animation_Holiday {
private:
	unsigned short int i;
	bool increasing;
public:
    Animation_Holiday_Halloween_WinAllFade() {}
    ~Animation_Holiday_Halloween_WinAllFade() {}

	void init();
    void step();
};

class Animation_Holiday_Halloween_WinAllHalloweenSparkle : public Animation_Holiday {
private:
	unsigned int i;
	bool reset;
	bool[3 * WINDOW_LENGTH] increasing;

	unsigned long int rand_halloween_color();
	unsigned int floor_0(float x);

	void sparkle_fade(bool*& inc);
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
	unsigned short int i;
	unsigned short int left;
	unsigned short int right;
	bool mode;

	const int RIGHT_BOTTOM = 9;
	const int RIGHT_TOP = 40;
	const int LEFT_TOP = 50;
	const int LEFT_BOTTOM = 80;

	const int LEFT_FULL_LENGTH = 41; // 39 pixels
	const int RIGHT_FULL_LENGTH = 41; // 40 pixels

	void christmas_snow(int i, int left_spacing, int right_spacing);
public:
	Animation_Holiday_Christmas_Win13Snow() {}
	~Animation_Holiday_Christmas_Win13Snow() {}

	void init();
	void step();
};

// Animation_Holiday_Hanukkah.cpp

class Animation_Holiday_Hanukkah_Win2Snow : public Animation_Holiday {
private:
	unsigned short int i;
	unsigned short int left;
	unsigned short int right;
	bool mode;

	const int RIGHT_BOTTOM = 9;
	const int RIGHT_TOP = 40;
	const int LEFT_TOP = 50;
	const int LEFT_BOTTOM = 80;

	const int LEFT_FULL_LENGTH = 41; // 39 pixels
	const int RIGHT_FULL_LENGTH = 41; // 40 pixels

	void hanukkah_snow(int i, int left_spacing, int right_spacing);
public:
	Animation_Holiday_Hanukkah_Win2Snow() {}
	~Animation_Holiday_Hanukkah_Win2Snow() {}

	void init();
	void step();
	void clean();
};

#endif
