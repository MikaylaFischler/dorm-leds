#ifndef ANIMATION_SIMPLE_HPP_
#define ANIMATION_SIMPLE_HPP_

#include "../../lib/exe/Animation.hpp"

class Animation_Simple : public Animation {
protected:
    Animation_Simple() {}
    ~Animation_Simple() {}

    void init();
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

class Animation_Simple_Indiv : public Animation_Simple {
protected:
	Animation_Simple_Indiv(int _id) : id(_id) {}
	~Animation_Simple_Indiv() {}

    void init();

	int id;
};

class Animation_Simple_Indiv_CalmPurpleFade : public Animation_Simple_Indiv {
private:
	unsigned short int i;
	bool increasing;
public:
	Animation_Simple_Indiv_CalmPurpleFade(int id) : Animation_Simple_Indiv(id) {}
	~Animation_Simple_Indiv_CalmPurpleFade() {}

	void init();
	void step();
};

class Animation_Simple_Indiv_ColorFlash : public Animation_Simple_Indiv {
private:
	uint32_t color;
	int rate;
	bool mode;
public:
	Animation_Simple_Indiv_ColorFlash(int id, uint32_t c) : Animation_Simple_Indiv(id), color(c), rate(200) {}
	Animation_Simple_Indiv_ColorFlash(int id, uint32_t c, int _rate) : Animation_Simple_Indiv(id), color(c), rate(_rate) {}
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
	Animation_Simple_Indiv_AlternatingColorFlash(int id, uint32_t c_a, uint32_t c_b) : Animation_Simple_Indiv(id), color_a(c_a), color_b(c_b), rate(200) {}
	Animation_Simple_Indiv_AlternatingColorFlash(int id, uint32_t c_a, uint32_t c_b, int _rate) : Animation_Simple_Indiv(id), color_a(c_a), color_b(c_b), rate(_rate) {}
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
	Animation_Simple_Indiv_ColorFade(int id, uint32_t c) : Animation_Simple_Indiv(id), color(c) {}
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
	Animation_Simple_Indiv_TheaterChase(int id, uint32_t c) : Animation_Simple_Indiv(id), color(c) {}
	~Animation_Simple_Indiv_TheaterChase() {}

	void init();
	void step();
};

// Animation_Simple_Indiv_Rainbow.cpp

class Animation_Simple_Indiv_Rainbow : public Animation_Simple_Indiv {
private:
	unsigned short int i;
public:
	Animation_Simple_Indiv_Rainbow(int id) : Animation_Simple_Indiv(id) {}
	~Animation_Simple_Indiv_Rainbow() {}

	void init();
	void step();
};

class Animation_Simple_Indiv_RainbowCycle : public Animation_Simple_Indiv {
private:
	unsigned short int i;
public:
	Animation_Simple_Indiv_RainbowCycle(int id) : Animation_Simple_Indiv(id) {}
	~Animation_Simple_Indiv_RainbowCycle() {}

	void init();
	void step();
};

class Animation_Simple_Indiv_RainbowWipe : public Animation_Simple_Indiv {
private:
	unsigned short int i, cur_color;
public:
	Animation_Simple_Indiv_RainbowWipe(int id) : Animation_Simple_Indiv(id) {}
	~Animation_Simple_Indiv_RainbowWipe() {}

	void init();
	void step();
};

class Animation_Simple_Indiv_RainbowTheaterChase : public Animation_Simple_Indiv {
private:
	unsigned short int i, j;
	bool alternate;
public:
	Animation_Simple_Indiv_RainbowTheaterChase(int id) : Animation_Simple_Indiv(id) {}
	~Animation_Simple_Indiv_RainbowTheaterChase() {}

	void init();
	void step();
};

class Animation_Simple_Indiv_RainbowWhiteTheaterChase : public Animation_Simple_Indiv {
private:
	unsigned short int i, j;
	bool alternate;
public:
	Animation_Simple_Indiv_RainbowWhiteTheaterChase(int id) : Animation_Simple_Indiv(id) {}
	~Animation_Simple_Indiv_RainbowWhiteTheaterChase() {}

	void init();
	void step();
};

#endif
