#ifndef Animation_Static_H
#define Animation_Static_H

#include "../../lib/Animation.hpp"

class Animation_Static : public Animation {
protected:
    Animation_Static() {}
    ~Animation_Static() {}

    void init();
};

class Animation_Static_DeskDimAmbient : public Animation_Static {
protected:
	void init();
public:
    Animation_Static_DeskDimAmbient() {}
    ~Animation_Static_DeskDimAmbient() {}
	
    void step();
};


#endif
