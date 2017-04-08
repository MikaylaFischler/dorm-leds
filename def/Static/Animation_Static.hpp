#ifndef ANIMATION_STATIC_HPP_
#define ANIMATION_STATIC_HPP_

#include "../../lib/Animation.hpp"

class Animation_Static : public Animation {
protected:
    Animation_Static() {}
    ~Animation_Static() {}

    void init();
};

// Animation_Simple_Indiv.cpp

class Animation_Static_Indiv : public Animation_Static {
protected:
	Animation_Static_Indiv() {}
	~Animation_Static_Indiv() {}

    void init();

	Adafruit_NeoPixel* strip;
};

// Animation_Static.cpp

class Animation_Static_DeskBrightWhite : public Animation_Static {
public:
    Animation_Static_DeskBrightWhite() {}
    ~Animation_Static_DeskBrightWhite() {}

    void step();
	void init();
};

class Animation_Static_DeskThirdDimAmbient : public Animation_Static {
public:
    Animation_Static_DeskThirdDimAmbient() {}
    ~Animation_Static_DeskThirdDimAmbient() {}

    void step();
	void init();
};

class Animation_Static_DeskDimAmbient : public Animation_Static {
public:
    Animation_Static_DeskDimAmbient() {}
    ~Animation_Static_DeskDimAmbient() {}

    void step();
	void init();
};

class Animation_Static_TransFlagWindows : public Animation_Static {
public:
    Animation_Static_TransFlagWindows() {}
    ~Animation_Static_TransFlagWindows() {}

    void step();
	void init();
};

class Animation_Static_TransFlagStripedWindows : public Animation_Static {
public:
    Animation_Static_TransFlagStripedWindows() {}
    ~Animation_Static_TransFlagStripedWindows() {}

    void step();
	void init();
};

// Animation_Static_Indiv.cpp

class Animation_Static_Indiv_Color : public Animation_Static_Indiv {
private:
	unsigned long int color;
public:
    Animation_Static_Indiv_Color(Adafruit_NeoPixel* strip, unsigned long int color);
    ~Animation_Static_Indiv_Color() {}

    void step();
	void init();
};

class Animation_Static_Indiv_ThirdDimAmbient : public Animation_Static_Indiv {
public:
    Animation_Static_Indiv_ThirdDimAmbient(Adafruit_NeoPixel* strip);
    ~Animation_Static_Indiv_ThirdDimAmbient() {}

    void step();
	void init();
};

#endif
