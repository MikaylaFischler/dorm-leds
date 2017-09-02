#ifndef ANIMATION_DISABLE_HPP_
#define ANIMATION_DISABLE_HPP_

#include "../../lib/exe/Animation.hpp"

class Animation_Disable : public Animation {
private:
	int id;
public:
    Animation_Disable(int i) : id(i) {}
    ~Animation_Disable() {}

    void init();
	void step();
};

#endif
