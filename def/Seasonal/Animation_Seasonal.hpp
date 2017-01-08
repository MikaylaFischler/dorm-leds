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

    void init();
	void snow(Adafruit_NeoPixel& strip, unsigned int i, unsigned short int left, unsigned short int right);
};

class Animation_Seasonal_Winter_Win1Snow : public Animation_Seasonal_Winter {
protected:
    void init();
public:
    Animation_Seasonal_Winter_Win1Snow() {}
    ~Animation_Seasonal_Winter_Win1Snow() {}

    void step();
	void clean();
};

class Animation_Seasonal_Winter_Win2Snow : public Animation_Seasonal_Winter {
protected:
	void init();
public:
	Animation_Seasonal_Winter_Win2Snow() {}
	~Animation_Seasonal_Winter_Win2Snow() {}

	void step();
	void clean();
};

class Animation_Seasonal_Winter_Win3Snow : public Animation_Seasonal_Winter {
protected:
	void init();
public:
	Animation_Seasonal_Winter_Win3Snow() {}
	~Animation_Seasonal_Winter_Win3Snow() {}

	void step();
	void clean();
};

#endif
