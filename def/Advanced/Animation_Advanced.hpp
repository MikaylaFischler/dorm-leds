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

class Animation_Advanced_Audio_BeatPulseWindow : public Animation_Advanced_Audio {
public:
    Animation_Advanced_Audio_BeatPulseWindow() {}
    ~Animation_Advanced_Audio_BeatPulseWindow() {}

	void init();
	void step();
	void clean();
};

class Animation_Advanced_Audio_BassPulseWindow : public Animation_Advanced_Audio {
public:
    Animation_Advanced_Audio_BassPulseWindow() {}
    ~Animation_Advanced_Audio_BassPulseWindow() {}

	void init();
	void step();
};

class Animation_Advanced_Audio_BassMidPulseWindow : public Animation_Advanced_Audio {
public:
    Animation_Advanced_Audio_BassMidPulseWindow() {}
    ~Animation_Advanced_Audio_BassMidPulseWindow() {}

	void init();
	void step();
};

class Animation_Advanced_Audio_EqualizerWindow : public Animation_Advanced_Audio {
public:
    Animation_Advanced_Audio_EqualizerWindow() {}
    ~Animation_Advanced_Audio_EqualizerWindow() {}

	void init();
	void step();
};

class Animation_Advanced_Audio_MaxEqualizerWindow : public Animation_Advanced_Audio {
public:
    Animation_Advanced_Audio_MaxEqualizerWindow() {}
    ~Animation_Advanced_Audio_MaxEqualizerWindow() {}

	void init();
	void step();
	void clean();
};

#endif
