#ifndef Animation_Disable_H
#define Animation_Disable_H

#include "../../lib/Animation.hpp"

class Animation_Disable : public Animation {
protected:
    Animation_Disable() {}
    ~Animation_Disable() {}

    void init();
};

class Animation_Disable_Desk1 : public Animation_Disable {
public:
    Animation_Disable_Desk1() {}
    ~Animation_Disable_Desk1() {}

    void init();
    void step();
};

class Animation_Disable_Desk2 : public Animation_Disable {
public:
    Animation_Disable_Desk2() {}
    ~Animation_Disable_Desk2() {}

    void init();
    void step();
};

class Animation_Disable_Window1 : public Animation_Disable {
public:
	Animation_Disable_Window1() {}
	~Animation_Disable_Window1() {}

    void init();
    void step();
};

class Animation_Disable_Window2 : public Animation_Disable {
public:
    Animation_Disable_Window2() {}
    ~Animation_Disable_Window2() {}

    void init();
    void step();
};

class Animation_Disable_Window3 : public Animation_Disable {
public:
    Animation_Disable_Window3() {}
    ~Animation_Disable_Window3() {}

    void init();
    void step();
};

#endif
