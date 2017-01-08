#ifndef Thread_H
#define Thread_H

#include "Animation.hpp"

class Thread {
private:
	unsigned int id;
	Animation* animation;
	unsigned long int updateRate;
	unsigned long int timeSum;
public:
	Thread(unsigned int id, Animation* anim, unsigned long int t);
	~Thread();

	unsigned int getID();
	unsigned long int getUpdateRate();
	unsigned long int getTimeSum();
	void addTimeSum(unsigned int dT);
	void zeroTimeSum();

	Animation* getAnimation();
};

#endif
