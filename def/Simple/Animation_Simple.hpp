#ifndef Animation_Simple_H
#define Animation_Simple_H

#include "../../lib/Animation.hpp"

class Animation_Simple : public Animation {
protected:
    Animation_Simple() {}
    ~Animation_Simple() {}
public:
    void init();
};

class Animation_Simple_WinColorWipe : public Animation_Simple {
protected:
    Animation_Simple_WinColorWipe() {}
    ~Animation_Simple_WinColorWipe() {}

	void rainbow_color_wipe(Adafruit_NeoPixel& strip, unsigned short int i, unsigned short int color_mode);
};

class Animation_Simple_DeskWhitePurpleFade : public Animation_Simple {
public:
    Animation_Simple_DeskWhitePurpleFade() {}
    ~Animation_Simple_DeskWhitePurpleFade() {}

	void init();
	void step();
	void clean();
};

class Animation_Simple_WinAllPurpleFade : public Animation_Simple {
public:
	Animation_Simple_WinAllPurpleFade() {}
	~Animation_Simple_WinAllPurpleFade() {}

	void init();
	void step();
	void clean();
};

class Animation_Simple_WinAllWPISpirit : public Animation_Simple {
public:
	Animation_Simple_WinAllWPISpirit() {}
	~Animation_Simple_WinAllWPISpirit() {}

	void init();
	void step();
	void clean();
};

class Animation_Simple_Win1RainbowWipe : public Animation_Simple_WinColorWipe {
public:
	Animation_Simple_Win1RainbowWipe() {}
	~Animation_Simple_Win1RainbowWipe() {}

	void init();
	void step();
	void clean();
};

class Animation_Simple_Win2RainbowWipe : public Animation_Simple_WinColorWipe {
public:
	Animation_Simple_Win2RainbowWipe() {}
	~Animation_Simple_Win2RainbowWipe() {}

	void init();
	void step();
	void clean();
};

class Animation_Simple_Win3RainbowWipe : public Animation_Simple_WinColorWipe {
public:
	Animation_Simple_Win3RainbowWipe() {}
	~Animation_Simple_Win3RainbowWipe() {}

	void init();
	void step();
	void clean();
};

#endif
