#ifndef Animation_Simple_H
#define Animation_Simple_H

#include "../../lib/Animation.hpp"

class Animation_Simple : public Animation {
protected:
    Animation_Simple() {}
    ~Animation_Simple() {}
public:
    void init();
};

// Animation_Simple_Indiv.cpp

class Animation_Simple_Indiv : public Animation_Simple {
protected:
	Animation_Simple_Indiv() {}
	~Animation_Simple_Indiv() {}
public:
    void init();
};

// Animation_Simple_WinColorWipe.cpp

class Animation_Simple_WinColorWipe : public Animation_Simple {
protected:
    Animation_Simple_WinColorWipe() {}
    ~Animation_Simple_WinColorWipe() {}

	void rainbow_color_wipe(Adafruit_NeoPixel& strip, unsigned short int i, unsigned short int color_mode);
};

// Animation_Simple.cpp

class Animation_Simple_DeskWhitePurpleFade : public Animation_Simple {
public:
    Animation_Simple_DeskWhitePurpleFade() {}
    ~Animation_Simple_DeskWhitePurpleFade() {}

	void init();
	void step();
	void clean();
};

class Animation_Simple_WinAllPurpleFade : public Animation_Simple {
public:
	Animation_Simple_WinAllPurpleFade() {}
	~Animation_Simple_WinAllPurpleFade() {}

	void init();
	void step();
	void clean();
};

class Animation_Simple_WinAllWPISpirit : public Animation_Simple {
public:
	Animation_Simple_WinAllWPISpirit() {}
	~Animation_Simple_WinAllWPISpirit() {}

	void init();
	void step();
	void clean();
};

// Animation_Simple_WinColorWipe.cpp

class Animation_Simple_Win1RainbowWipe : public Animation_Simple_WinColorWipe {
public:
	Animation_Simple_Win1RainbowWipe() {}
	~Animation_Simple_Win1RainbowWipe() {}

	void init();
	void step();
	void clean();
};

class Animation_Simple_Win2RainbowWipe : public Animation_Simple_WinColorWipe {
public:
	Animation_Simple_Win2RainbowWipe() {}
	~Animation_Simple_Win2RainbowWipe() {}

	void init();
	void step();
	void clean();
};

class Animation_Simple_Win3RainbowWipe : public Animation_Simple_WinColorWipe {
public:
	Animation_Simple_Win3RainbowWipe() {}
	~Animation_Simple_Win3RainbowWipe() {}

	void init();
	void step();
	void clean();
};

// Animation_Simple_Indiv.cpp

class Animation_Simple_Indiv_ColorFade : public Animation_Simple_Indiv {
public:
	Animation_Simple_Indiv_ColorFade(Adafruit_NeoPixel* strip, uint32_t color);
	~Animation_Simple_Indiv_ColorFade() {}

	void init();
	void step();
	void clean();
private:
	Adafruit_NeoPixel* strip;
	uint32_t color;
};

class Animation_Simple_Indiv_Rainbow : public Animation_Simple_Indiv {
public:
	Animation_Simple_Indiv_Rainbow(Adafruit_NeoPixel* strip);
	~Animation_Simple_Indiv_Rainbow() {}

	void init();
	void step();
	void clean();
private:
	Adafruit_NeoPixel* strip;
};

class Animation_Simple_Indiv_RainbowCycle : public Animation_Simple_Indiv {
public:
	Animation_Simple_Indiv_RainbowCycle(Adafruit_NeoPixel* strip);
	~Animation_Simple_Indiv_RainbowCycle() {}

	void init();
	void step();
	void clean();
private:
	Adafruit_NeoPixel* strip;
};

#endif
