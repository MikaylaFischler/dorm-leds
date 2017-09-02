#ifndef ANIMATION_STATIC_HPP_
#define ANIMATION_STATIC_HPP_

#include "../../lib/exe/Animation.hpp"

class Animation_Static : public Animation {
protected:
    Animation_Static() {}
    ~Animation_Static() {}

    void init();
};

// Animation_Static.cpp

class Animation_Static_DeskBrightWhite : public Animation_Static {
public:
    Animation_Static_DeskBrightWhite() {}
    ~Animation_Static_DeskBrightWhite() {}

	void init();
    void step();
};

class Animation_Static_DeskDimAmbient : public Animation_Static {
public:
    Animation_Static_DeskDimAmbient() {}
    ~Animation_Static_DeskDimAmbient() {}

	void init();
    void step();
};

class Animation_Static_TransFlagWindows : public Animation_Static {
public:
    Animation_Static_TransFlagWindows() {}
    ~Animation_Static_TransFlagWindows() {}

	void init();
    void step();
};

class Animation_Static_TransFlagStripedWindows : public Animation_Static {
public:
    Animation_Static_TransFlagStripedWindows() {}
    ~Animation_Static_TransFlagStripedWindows() {}

	void init();
    void step();
};

// Animation_Static_Indiv.cpp

class Animation_Static_Indiv : public Animation_Static {
protected:
	Animation_Static_Indiv(int _id) : id(_id) {}
	~Animation_Static_Indiv() {}

    void init();

	int id;
};

class Animation_Static_Indiv_Color : public Animation_Static_Indiv {
private:
	unsigned long int color;
public:
    Animation_Static_Indiv_Color(int id, unsigned long int c) : Animation_Static_Indiv(id), color(c) {}
    ~Animation_Static_Indiv_Color() {}

	void init();
    void step();
};

class Animation_Static_Indiv_ThirdDimAmbient : public Animation_Static_Indiv {
public:
    Animation_Static_Indiv_ThirdDimAmbient(int id) : Animation_Static_Indiv(id) {}
    ~Animation_Static_Indiv_ThirdDimAmbient() {}

	void init();
    void step();
};

#endif
