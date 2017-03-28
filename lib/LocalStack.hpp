#ifndef LOCALSTACK_HPP_
#define LOCALSTACK_HPP_

#include <StandardCplusplus.h>
#include <vector>

#include "MemObj.hpp"

class LocalStack {
private:
    std::vector<MemObj*> stack;
public:
    LocalStack();
    ~LocalStack();

    // untyped element manipulation
    void push(MemObj* element);
	void drop(unsigned int i);
    void replace(unsigned int i, MemObj* obj);
    MemObj* get(unsigned int i) const;

    // get raw stack
    std::vector<MemObj*> getStack() const;
};

#endif
