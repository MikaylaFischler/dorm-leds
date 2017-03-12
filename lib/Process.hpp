#ifndef PROCESS_HPP_
#define PROCESS_HPP_

#include <StandardCplusplus.h>
#include <vector>

#include "Executable.hpp"

class Process : public Executable {
protected:
	Process();
public:
	virtual ~Process();

    virtual void init() {};
	virtual void step() {};
	virtual void clean() {};
};

#endif
