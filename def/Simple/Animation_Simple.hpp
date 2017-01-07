#ifndef Animation_Simple_H
#define Animation_Simple_H

#include "../../lib/Animation.hpp"

class Animation_Simple : public Animation {
protected:
    Animation_Simple() {}
    ~Animation_Simple() {}

    void init();
};

class Animation_Simple_DeskWhitePurpleFade : public Animation_Simple {
protected:
    void init();
public:
    Animation_Simple_DeskWhitePurpleFade() {}
    ~Animation_Simple_DeskWhitePurpleFade() {}
    void step();
};

class Animation_Simple_WinAllPurpleFade : public Animation_Simple {
protected:
	void init();
public:
	Animation_Simple_WinAllPurpleFade() {}
	~Animation_Simple_WinAllPurpleFade() {}
	void step();
};

class Animation_Simple_WPISpirit : public Animation_Simple {
protected:
	void init();
public:
	Animation_Simple_WPISpirit() {}
	~Animation_Simple_WPISpirit() {}
	void step();
};

#endif
