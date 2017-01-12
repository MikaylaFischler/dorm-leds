#ifndef Process_H
#define Process_H

#include <StandardCplusplus.h>
#include <vector>

class Process {
protected:
    String name;

    LocalStack* stack;

    unsigned long int update_rate;

	Process();
public:
	virtual ~Process();
    virtual void init();

	virtual void run() {};
    virtual void clean() {};

    String getName();
    unsigned long int getUpdateRate();
};

#endif
