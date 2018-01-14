#ifndef ANIMATION_DISABLE_HPP_
#define ANIMATION_DISABLE_HPP_

#include "../../lib/exe/Animation.hpp"

/*!
	@brief Shuts off the LEDs on a strip
	@class Disables an LED strip
	@remark Supports all RGB and RGBW strips
*/
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
