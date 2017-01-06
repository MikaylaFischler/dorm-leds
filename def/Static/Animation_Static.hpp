#ifndef Animation_Static_H
#define Animation_Static_H

#include "../../lib/Animation.hpp"

class Animation_Static : public Animation {
protected:
    Animation_Disable() {}
    ~Animation_Disable() {}

    void init();
};

class Animation_Static_DeskDimAmbient : public Animation_Static {
protected:
    void main();
    void init();
public:
    Animation_Static_DeskDimAmbient() {}
    ~Animation_Static_DeskDimAmbient() {}
};


#endif
