#ifndef ANIMATION_SIMPLE_HPP_
#define ANIMATION_SIMPLE_HPP_

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
	Animation_Simple_Indiv(Adafruit_NeoPixel* _strip) : strip(_strip) {}
	~Animation_Simple_Indiv() {}

    void init();

	Adafruit_NeoPixel* strip;
};

// Animation_Simple.cpp

class Animation_Simple_DeskWhitePurpleFade : public Animation_Simple {
private:
	short int i;
	bool increasing;
public:
    Animation_Simple_DeskWhitePurpleFade() {}
    ~Animation_Simple_DeskWhitePurpleFade() {}

	void init();
	void step();
};

class Animation_Simple_WinAllWPISpirit : public Animation_Simple {
private:
	unsigned short int i;
	bool mode;
public:
	Animation_Simple_WinAllWPISpirit() {}
	~Animation_Simple_WinAllWPISpirit() {}

	void init();
	void step();
};

// Animation_Simple_Indiv.cpp

class Animation_Simple_Indiv_CalmPurpleFade : public Animation_Simple_Indiv {
private:
	unsigned short int i;
	bool increasing;
public:
	Animation_Simple_Indiv_CalmPurpleFade(Adafruit_NeoPixel* strip) : Animation_Simple_Indiv(strip) {}
	~Animation_Simple_Indiv_CalmPurpleFade() {}

	void init();
	void step();
	void clean();
};

class Animation_Simple_Indiv_ColorFlash : public Animation_Simple_Indiv {
private:
	uint32_t color;
	int rate;
	bool mode;
public:
	Animation_Simple_Indiv_ColorFlash(Adafruit_NeoPixel* strip, uint32_t c);
	Animation_Simple_Indiv_ColorFlash(Adafruit_NeoPixel* strip, uint32_t c, int _rate);
	~Animation_Simple_Indiv_ColorFlash() {}

	void init();
	void step();
};

class Animation_Simple_Indiv_AlternatingColorFlash : public Animation_Simple_Indiv {
private:
	uint32_t color_a;
	uint32_t color_b;
	int rate;
	bool mode;
	bool cur_color;
public:
	Animation_Simple_Indiv_AlternatingColorFlash(Adafruit_NeoPixel* strip, uint32_t c_a, uint32_t c_b);
	Animation_Simple_Indiv_AlternatingColorFlash(Adafruit_NeoPixel* strip, uint32_t c_a, uint32_t c_b, int _rate);
	~Animation_Simple_Indiv_AlternatingColorFlash() {}

	void init();
	void step();
};

class Animation_Simple_Indiv_ColorFade : public Animation_Simple_Indiv {
private:
	uint32_t color;
	unsigned short int i;
	bool increasing;
public:
	Animation_Simple_Indiv_ColorFade(Adafruit_NeoPixel* strip, uint32_t c);
	~Animation_Simple_Indiv_ColorFade() {}

	void init();
	void step();
};

class Animation_Simple_Indiv_TheaterChase : public Animation_Simple_Indiv {
private:
	uint32_t color;
	unsigned short int i;
	bool alternate;
public:
	Animation_Simple_Indiv_TheaterChase(Adafruit_NeoPixel* strip, uint32_t c);
	~Animation_Simple_Indiv_TheaterChase() {}

	void init();
	void step();
};

// Animation_Simple_Indiv_Rainbow.cpp

class Animation_Simple_Indiv_Rainbow : public Animation_Simple_Indiv {
private:
	unsigned short int i;
public:
	Animation_Simple_Indiv_Rainbow(Adafruit_NeoPixel* strip) : Animation_Simple_Indiv(strip) {}
	~Animation_Simple_Indiv_Rainbow() {}

	void init();
	void step();
};

class Animation_Simple_Indiv_RainbowCycle : public Animation_Simple_Indiv {
private:
	unsigned short int i;
public:
	Animation_Simple_Indiv_RainbowCycle(Adafruit_NeoPixel* strip) : Animation_Simple_Indiv(strip) {}
	~Animation_Simple_Indiv_RainbowCycle() {}

	void init();
	void step();
};

class Animation_Simple_Indiv_RainbowWipe : public Animation_Simple_Indiv {
private:
	unsigned short int i;
	unsigned short int cur_color;
public:
	Animation_Simple_Indiv_RainbowWipe(Adafruit_NeoPixel* strip) : Animation_Simple_Indiv(strip) {}
	~Animation_Simple_Indiv_RainbowWipe() {}

	void init();
	void step();
};

class Animation_Simple_Indiv_RainbowTheaterChase : public Animation_Simple_Indiv {
private:
	unsigned short int i;
	unsigned short int j;
	bool alternate;
public:
	Animation_Simple_Indiv_RainbowTheaterChase(Adafruit_NeoPixel* strip) : Animation_Simple_Indiv(strip) {}
	~Animation_Simple_Indiv_RainbowTheaterChase() {}

	void init();
	void step();
};

#endif
