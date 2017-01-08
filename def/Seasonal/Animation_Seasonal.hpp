#ifndef Animation_Seasonal_H
#define Animation_Seasonal_H

#include "../../lib/Animation.hpp"

class Animation_Seasonal : public Animation {
protected:
    Animation_Seasonal() {}
    ~Animation_Seasonal() {}

    void init();
};

class Animation_Seasonal_Winter : public Animation_Seasonal {
protected:
    Animation_Seasonal_Winter() {}
    ~Animation_Seasonal_Winter() {}
};

class Animation_Seasonal_Winter_Snow : public Animation_Seasonal_Winter {
protected:
    Animation_Seasonal_Winter() {}
    ~Animation_Seasonal_Winter() {}

    void init();
	void snow(Adafruit_NeoPixel& strip, unsigned int i, unsigned short int left_spacing, unsigned short int right_spacing);
	void snow_step(Adafruit_NeoPixel& strip);
};

class Animation_Seasonal_Winter_Snow_Win1 : public Animation_Seasonal_Winter_Snow {
protected:
    void init();
public:
    Animation_Seasonal_Winter_Snow_Win1() {}
    ~Animation_Seasonal_Winter_Snow_Win1() {}

    void step();
	void clean();
};

class Animation_Seasonal_Winter_Snow_Win2 : public Animation_Seasonal_Winter_Snow {
protected:
	void init();
public:
	Animation_Seasonal_Winter_Snow_Win2() {}
	~Animation_Seasonal_Winter_Snow_Win2() {}

	void step();
	void clean();
};

class Animation_Seasonal_Winter_Snow_Win3 : public Animation_Seasonal_Winter_Snow {
protected:
	void init();
public:
	Animation_Seasonal_Winter_Snow_Win3() {}
	~Animation_Seasonal_Winter_Snow_Win3() {}

	void step();
	void clean();
};

#endif
