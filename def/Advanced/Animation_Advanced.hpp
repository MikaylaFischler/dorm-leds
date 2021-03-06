#ifndef ANIMATION_AUDIO_HPP_
#define ANIMATION_AUDIO_HPP_

#include "../../lib/exe/Animation.hpp"

#include "../../dev/MSGEQ7.hpp"
#include "../../dev/PulseMonitor.hpp"

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

class Animation_Advanced_Audio_BassPulseLR : public Animation_Advanced_Audio {
private:
	int low_L, low_R;
	int strip1, strip2;
public:
    Animation_Advanced_Audio_BassPulseLR(int str1, int str2) : strip1(str1), strip2(str2) {}
    ~Animation_Advanced_Audio_BassPulseLR() {}

	void init();
	void step();
};

class Animation_Advanced_Audio_BassPulseNestedLR : public Animation_Advanced_Audio {
private:
	int low_L, low_R, low2_L, low2_R, mid;
	int strip1, strip2;
public:
    Animation_Advanced_Audio_BassPulseNestedLR(int str1, int str2) : strip1(str1), strip2(str2) {}
    ~Animation_Advanced_Audio_BassPulseNestedLR() {}

	void init();
	void step();
};

class Animation_Advanced_Audio_PulseNestedLR : public Animation_Advanced_Audio {
private:
	int l0, l1, l2, l3, l4, l5, l6;
	int r0, r1, r2, r3, r4, r5, r6;
	int mid, len;
	int strip1, strip2;
	bool mode;
public:
    Animation_Advanced_Audio_PulseNestedLR(int str1, int str2, bool _mode) : strip1(str1), strip2(str2), mode(_mode) {}
    ~Animation_Advanced_Audio_PulseNestedLR() {}

	void init();
	void step();
};

class Animation_Advanced_Audio_BassPulseStrip : public Animation_Advanced_Audio {
private:
	vector<int> strip_ids;
	short unsigned int fadeFunctionOrder;
	long unsigned int color;
	int freq_range_0_sum, freq_range_1_sum, freq_range_2_sum, result;
public:
    Animation_Advanced_Audio_BassPulseStrip(int strip);
    Animation_Advanced_Audio_BassPulseStrip(vector<int> strip_ids);
    Animation_Advanced_Audio_BassPulseStrip(int strip, short unsigned int _fadeFO);
    Animation_Advanced_Audio_BassPulseStrip(vector<int> strip_ids, short unsigned int _fadeFO);
    Animation_Advanced_Audio_BassPulseStrip(int strip, short unsigned int _fadeFO, long unsigned int _color);
    Animation_Advanced_Audio_BassPulseStrip(vector<int> strip_ids, short unsigned int _fadeFO, long unsigned int _color);
    ~Animation_Advanced_Audio_BassPulseStrip() {}

	void init();
	void step();
};

class Animation_Advanced_Audio_BassMidPulseWindow : public Animation_Advanced_Audio {
private:
	unsigned int low_sum_l, low_sum_r, mid_sum_l, mid_sum_r, low_sum, mid_sum;
public:
    Animation_Advanced_Audio_BassMidPulseWindow() {}
    ~Animation_Advanced_Audio_BassMidPulseWindow() {}

	void init();
	void step();
};

class Animation_Advanced_Audio_BassPulseMidHueWindow : public Animation_Advanced_Audio {
private:
	unsigned int low_sum_l, low_sum_r, mid_sum_l, mid_sum_r, low_sum, mid_sum;
	long unsigned int hue;
public:
    Animation_Advanced_Audio_BassPulseMidHueWindow() {}
    ~Animation_Advanced_Audio_BassPulseMidHueWindow() {}

	void init();
	void step();
};

// Animation_Advanced_Audio_EQ.cpp

class Animation_Advanced_Audio_EQ_BasePulseCircularEQWindow : public Animation_Advanced_Audio {
private:
	short unsigned int low_sum;
	long unsigned int val;
	bool no_0, no_1, no_2, no_3, no_4, no_5, no_6;
public:
    Animation_Advanced_Audio_EQ_BasePulseCircularEQWindow() {}
    ~Animation_Advanced_Audio_EQ_BasePulseCircularEQWindow() {}

	void init();
	void step();
};

class Animation_Advanced_Audio_EQ_Window : public Animation_Advanced_Audio {
private:
	unsigned int val[7];
public:
    Animation_Advanced_Audio_EQ_Window() {}
    ~Animation_Advanced_Audio_EQ_Window() {}

	void init();
	void step();
};

class Animation_Advanced_Audio_EQ_MaxWindow : public Animation_Advanced_Audio {
private:
	unsigned int count;
	unsigned int val[6];
	unsigned short int max[6];
public:
    Animation_Advanced_Audio_EQ_MaxWindow() {}
    ~Animation_Advanced_Audio_EQ_MaxWindow() {}

	void init();
	void step();
};

class Animation_Advanced_Audio_EQ_MaxBassCeiling : public Animation_Advanced_Audio {
private:
	unsigned int max[2];
	unsigned int count;
	unsigned int val[2];
public:
    Animation_Advanced_Audio_EQ_MaxBassCeiling() {}
    ~Animation_Advanced_Audio_EQ_MaxBassCeiling() {}

	void init();
	void step();
};

// Animation_Advanced_Pulse.cpp

class Animation_Advanced_Pulse : public Animation_Advanced {
protected:
    Animation_Advanced_Pulse() {}
    ~Animation_Advanced_Pulse() {}

    void init();

	PulseMonitor* pulse_mon;
};

class Animation_Advanced_Pulse_CeilingPulse : public Animation_Advanced_Pulse {
private:
	bool quarticScaleFilter;
public:
    Animation_Advanced_Pulse_CeilingPulse(bool qSF) : quarticScaleFilter(qSF) {}
    ~Animation_Advanced_Pulse_CeilingPulse() {}

    void init();
	void step();
};

class Animation_Advanced_Pulse_CeilingChart : public Animation_Advanced_Pulse {
private:
	bool quarticScaleFilter;
	int cur_pixel;
public:
    Animation_Advanced_Pulse_CeilingChart(bool qSF) : quarticScaleFilter(qSF) {}
    ~Animation_Advanced_Pulse_CeilingChart() {}

    void init();
	void step();
};

#endif
