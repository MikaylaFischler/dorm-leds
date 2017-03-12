#ifndef Animation_Audio_H
#define Animation_Audio_H

#include "../../lib/Animation.hpp"
#include "../../conf/globals.h"
#include "../../dev/MSGEQ7.hpp"
#include "../../util/led.c"

class Animation_Advanced : public Animation {
protected:
    Animation_Advanced() {}
    ~Animation_Advanced() {}

    void init();
};

class Animation_Advanced_Audio : public Animation_Advanced {
protected:
    Animation_Advanced_Audio() {}
    ~Animation_Advanced_Audio() {}

    void init();
};

class Animation_Advanced_Audio_BeatPulseWindow : public Animation_Advanced_Audio {
public:
    Animation_Advanced_Audio_BeatPulseWindow() {}
    ~Animation_Advanced_Audio_BeatPulseWindow() {}

	void init();
	void step();
	void clean();
private:
	MSGEQ7* left_eq;
};

class Animation_Advanced_Audio_BasePulseWindow : public Animation_Advanced_Audio {
public:
    Animation_Advanced_Audio_BasePulseWindow() {}
    ~Animation_Advanced_Audio_BasePulseWindow() {}

	void init();
	void step();
	void clean();
private:
	MSGEQ7* left_eq;
};

class Animation_Advanced_Audio_EqualizerWindow : public Animation_Advanced_Audio {
public:
    Animation_Advanced_Audio_EqualizerWindow() {}
    ~Animation_Advanced_Audio_EqualizerWindow() {}

	void init();
	void step();
	void clean();
private:
	MSGEQ7* left_eq;
};

class Animation_Advanced_Audio_MaxEqualizerWindow : public Animation_Advanced_Audio {
public:
    Animation_Advanced_Audio_MaxEqualizerWindow() {}
    ~Animation_Advanced_Audio_MaxEqualizerWindow() {}

	void init();
	void step();
	void clean();
private:
	MSGEQ7* left_eq;
};

#endif
