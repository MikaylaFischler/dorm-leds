#ifndef Listener_H
#define Listener_H

#include "Process.hpp"

class Listener : public Process {
protected:
	Listener();
public:
	virtual ~Listener();

	virtual void init();
	virtual bool check() = 0;
};

#endif
