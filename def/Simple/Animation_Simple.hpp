#ifndef Animation_Simple_H
#define Animation_Simple_H

#include "../../lib/Animation.hpp"

class Animation_Simple : public Animation {
protected:
    Animation_Simple() {}
    ~Animation_Simple() {}

    void init();
};

class Animation_Simple_WhitePurpleFade : public Animation_Simple {
protected:
    void init();
public:
    Animation_Simple_WhitePurpleFade() {}
    ~Animation_Simple_WhitePurpleFade() {}
    void step();
};


#endif
