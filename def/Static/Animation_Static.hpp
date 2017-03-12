#ifndef ANIMATION_STATIC_HPP_
#define ANIMATION_STATIC_HPP_

#include "../../lib/Animation.hpp"

class Animation_Static : public Animation {
protected:
    Animation_Static() {}
    ~Animation_Static() {}

    void init();
};

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


#endif
