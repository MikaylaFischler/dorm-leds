#ifndef Process_H
#define Process_H

#include <StandardCplusplus.h>
#include <vector>

#include "Executable.hpp"

class Process : public Executable {
protected:
	Process();
public:
	virtual ~Process();
    virtual void init();
	virtual void run() {};
};

#endif
