#ifndef LISTENER_HPP_
#define LISTENER_HPP_

#include "Process.hpp"

class Listener : public Process {
protected:
	Listener();
public:
	virtual ~Listener();

	virtual void init();
};

#endif
