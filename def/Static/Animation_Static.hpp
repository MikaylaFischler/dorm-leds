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

/*!
	@brief Displays a transgender pride colors as three colored strips
	@class Displays transgender pride colors using three windows bordered in
		LED strips
	@remark Utilizes pre-defined RGB LED strips, not portable (see warning)
	@warning Only works for a specific LED strip setup
*/
class Animation_Static_TransColorWindows : public Animation_Static {
public:
    Animation_Static_TransColorWindows() {}
    ~Animation_Static_TransColorWindows() {}

	void init();
    void step();
};

/*!
	@brief Displays a transgender pride flag
	@class Displays transgender flag using inner vertical borders of three
		windows bordered in LEDs
	@remark Utilizes pre-defined RGB LED strips, not portable (see warning)
	@warning Only works for a specific LED strip setup
*/
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

/*!
	@brief Displays a color on an LED strip
	@class Sets all LEDs on a strip to a given color
	@remark Supports all RGB and RGBW strips
*/
class Animation_Static_Indiv_Color : public Animation_Static_Indiv {
private:
	unsigned long int color;
public:
    Animation_Static_Indiv_Color(int id, unsigned long int c) : Animation_Static_Indiv(id), color(c) {}
    ~Animation_Static_Indiv_Color() {}

	void init();
    void step();
};

/*!
	@brief Displays a spaced dim lighting
	@class Sets each third LED on a strip to a soft RGB white
	@remark Supports all RGB and RGBW strips
*/
class Animation_Static_Indiv_ThirdDimAmbient : public Animation_Static_Indiv {
public:
    Animation_Static_Indiv_ThirdDimAmbient(int id) : Animation_Static_Indiv(id) {}
    ~Animation_Static_Indiv_ThirdDimAmbient() {}

	void init();
    void step();
};

/*!
	@brief Displays a spaced dim lighting
	@class Sets each third LED on a strip to a soft white
	@remark Supports all RGBW strips
	@warning Does not support RGB strips
*/
class Animation_Static_Indiv_ThirdDimAmbient_W : public Animation_Static_Indiv {
public:
    Animation_Static_Indiv_ThirdDimAmbient_W(int id) : Animation_Static_Indiv(id) {}
    ~Animation_Static_Indiv_ThirdDimAmbient_W() {}

	void init();
    void step();
};

/*!
	@brief Displays a bright natural white lighting
	@class Sets each LED on a strip to white
	@remark Supports all RGBW strips
	@warning Does not support RGB strips
*/
class Animation_Static_Indiv_Light_W : public Animation_Static_Indiv {
public:
    Animation_Static_Indiv_Light_W(int id) : Animation_Static_Indiv(id) {}
    ~Animation_Static_Indiv_Light_W() {}

	void init();
    void step();
};

#endif
