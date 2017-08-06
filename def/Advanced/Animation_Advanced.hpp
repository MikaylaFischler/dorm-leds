#ifndef ANIMATION_AUDIO_HPP_
#define ANIMATION_AUDIO_HPP_

#include "../../lib/Animation.hpp"

#include "../../dev/MSGEQ7.hpp"
#include "../../conf/globals.h"

#include "../../util/led.c"
#include "../../util/ledmath.c"

class Animation_Advanced : public Animation {
protected:
    Animation_Advanced() {}
    ~Animation_Advanced() {}

    void init();
};

// Animation_Advanced_Audio.cpp

class Animation_Advanced_Audio : public Animation_Advanced {
protected:
    Animation_Advanced_Audio() {}
    ~Animation_Advanced_Audio() {}

    void init();

	MSGEQ7* left_eq;
	MSGEQ7* right_eq;
};

class Animation_Advanced_Audio_BassPulseWindow : public Animation_Advanced_Audio {
private:
	int low_sum;
	int low2_sum;
public:
    Animation_Advanced_Audio_BassPulseWindow() {}
    ~Animation_Advanced_Audio_BassPulseWindow() {}

	void init();
	void step();
};

class Animation_Advanced_Audio_BassMidPulseWindow : public Animation_Advanced_Audio {
private:
	int low_sum_l;
	int low_sum_r;
	int mid_sum_l;
	int mid_sum_r;

	int low_sum;
	int mid_sum;
public:
    Animation_Advanced_Audio_BassMidPulseWindow() {}
    ~Animation_Advanced_Audio_BassMidPulseWindow() {}

	void init();
	void step();
};

class Animation_Advanced_Audio_BassPulseMidHueWindow : public Animation_Advanced_Audio {
private:
	int low_sum_l;
	int low_sum_r;
	int mid_sum_l;
	int mid_sum_r;

	int low_sum;
	int mid_sum;

	long unsigned int hue;
public:
    Animation_Advanced_Audio_BassPulseMidHueWindow() {}
    ~Animation_Advanced_Audio_BassPulseMidHueWindow() {}

	void init();
	void step();
};

class Animation_Advanced_Audio_BasePulseCircularEqWindow : public Animation_Advanced_Audio {
private:
	int low_sum;

	long unsigned int val;

	bool no_0;
	bool no_1;
	bool no_2;
	bool no_3;
	bool no_4;
	bool no_5;
	bool no_6;
public:
    Animation_Advanced_Audio_BasePulseCircularEqWindow() {}
    ~Animation_Advanced_Audio_BasePulseCircularEqWindow() {}

	void init();
	void step();
};

class Animation_Advanced_Audio_EqualizerWindow : public Animation_Advanced_Audio {
private:
	unsigned int val[7];
public:
    Animation_Advanced_Audio_EqualizerWindow() {}
    ~Animation_Advanced_Audio_EqualizerWindow() {}

	void init();
	void step();
};

class Animation_Advanced_Audio_MaxEqualizerWindow : public Animation_Advanced_Audio {
private:
	unsigned short int max[6];
	unsigned int count;
	unsigned int val[6];
public:
    Animation_Advanced_Audio_MaxEqualizerWindow() {}
    ~Animation_Advanced_Audio_MaxEqualizerWindow() {}

	void init();
	void step();
	void clean();
};

#endif
