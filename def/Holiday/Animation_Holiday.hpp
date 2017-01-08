#ifndef Animation_Holiday_H
#define Animation_Holiday_H

#include "../../lib/Animation.hpp"

class Animation_Holiday : public Animation {
protected:
    Animation_Holiday() {}
    ~Animation_Holiday() {}

    void init();
};

class Animation_Holiday_Halloween_WinAllFade : public Animation_Holiday {
protected:
    void init();
public:
    Animation_Holiday_Halloween_WinAllFade() {}
    ~Animation_Holiday_Halloween_WinAllFade() {}

    void step();
	void clean();
};

class Animation_Holiday_Halloween_WinAllSparkleFade : public Animation_Holiday {
private:
	unsigned long int rand_halloween_color();
	void sparkle_fade(float i, bool inc[]);
protected:
	void init();
public:
	Animation_Holiday_Halloween_WinAllSparkleFade() {}
	~Animation_Holiday_Halloween_WinAllSparkleFade() {}

	void step();
	void clean();
};

class Animation_Holiday_Christmas_Win13Snow : public Animation_Holiday {
private:
	void christmas_snow(int i, int left_spacing, int right_spacing);
protected:
	void init();
public:
	Animation_Holiday_Christmas_Win13Snow() {}
	~Animation_Holiday_Christmas_Win13Snow() {}

	void step();
	void clean();
};

class Animation_Holiday_Hanukkah_Win2Snow : public Animation_Holiday {
private:
	void hanukkah_snow(int i, int left_spacing, int right_spacing);
protected:
	void init();
public:
	Animation_Holiday_Hanukkah_Win2Snow() {}
	~Animation_Holiday_Hanukkah_Win2Snow() {}

	void step();
	void clean();
};

#endif
