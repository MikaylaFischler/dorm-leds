#ifndef Animation_Simple_H
#define Animation_Simple_H

#include "../../lib/Animation.hpp"

class Animation_Simple : public Animation {
protected:
    Animation_Simple() {}
    ~Animation_Simple() {}

    void init();
};

// Animation_Simple_Indiv.cpp

class Animation_Simple_Indiv : public Animation_Simple {
protected:
	Animation_Simple_Indiv() {}
	~Animation_Simple_Indiv() {}
	
    void init();
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

class Animation_Simple_WinAllWPISpirit : public Animation_Simple {
public:
	Animation_Simple_WinAllWPISpirit() {}
	~Animation_Simple_WinAllWPISpirit() {}

	void init();
	void step();
	void clean();
};

// Animation_Simple_Indiv.cpp

class Animation_Simple_Indiv_CalmPurpleFade : public Animation_Simple_Indiv {
public:
	Animation_Simple_Indiv_CalmPurpleFade(Adafruit_NeoPixel* strip);
	~Animation_Simple_Indiv_CalmPurpleFade() {}

	void init();
	void step();
	void clean();
private:
	Adafruit_NeoPixel* strip;
};

class Animation_Simple_Indiv_ColorFlash : public Animation_Simple_Indiv {
public:
	Animation_Simple_Indiv_ColorFlash(Adafruit_NeoPixel* strip, uint32_t color);
	Animation_Simple_Indiv_ColorFlash(Adafruit_NeoPixel* strip, uint32_t color, int rate);
	~Animation_Simple_Indiv_ColorFlash() {}

	void init();
	void step();
	void clean();
private:
	Adafruit_NeoPixel* strip;
	uint32_t color;
	int rate;
};

class Animation_Simple_Indiv_AlternatingColorFlash : public Animation_Simple_Indiv {
public:
	Animation_Simple_Indiv_AlternatingColorFlash(Adafruit_NeoPixel* strip, uint32_t color_a, uint32_t color_b);
	Animation_Simple_Indiv_AlternatingColorFlash(Adafruit_NeoPixel* strip, uint32_t color_a, uint32_t color_b, int rate);
	~Animation_Simple_Indiv_AlternatingColorFlash() {}

	void init();
	void step();
	void clean();
private:
	Adafruit_NeoPixel* strip;
	uint32_t color_a;
	uint32_t color_b;
	int rate;
};

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

class Animation_Simple_Indiv_TheaterChase : public Animation_Simple_Indiv {
public:
	Animation_Simple_Indiv_TheaterChase(Adafruit_NeoPixel* strip, uint32_t color);
	~Animation_Simple_Indiv_TheaterChase() {}

	void init();
	void step();
	void clean();
private:
	Adafruit_NeoPixel* strip;
	uint32_t color;
};

// Animation_Simple_Indiv_Rainbow.cpp

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

class Animation_Simple_Indiv_RainbowWipe : public Animation_Simple_Indiv {
public:
	Animation_Simple_Indiv_RainbowWipe(Adafruit_NeoPixel* strip);
	~Animation_Simple_Indiv_RainbowWipe() {}

	void init();
	void step();
	void clean();
private:
	Adafruit_NeoPixel* strip;
};

class Animation_Simple_Indiv_RainbowTheaterChase : public Animation_Simple_Indiv {
public:
	Animation_Simple_Indiv_RainbowTheaterChase(Adafruit_NeoPixel* strip);
	~Animation_Simple_Indiv_RainbowTheaterChase() {}

	void init();
	void step();
	void clean();
private:
	Adafruit_NeoPixel* strip;
};

#endif
