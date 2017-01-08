#ifndef Thread_H
#define Thread_H

#include <StandardCplusplus.h>
#include <vector>

#include "Animation.hpp"

class Thread {
private:
	unsigned int id;
	Animation* animation;
	unsigned long int updateRate;
	unsigned long int timeSum;
public:
	Thread(unsigned int id, Animation& anim);
	~Thread();

	unsigned int getID();
	unsigned long int getUpdateRate();
	unsigned long int getTimeSum();
	void addTimeSum(unsigned int dT);
	void zeroTimeSum();

	Animation& getAnimation();
};

#endif
