#include "LocalStack.hpp"

// <<constructors>>
LocalStack::LocalStack() {}

/*
LocalStack::LocalStack(MemObj datum) {
    this->stack.push_back(datum);
}

LocalStack::LocalStack(MemObj stack[], int numElements) {
    for(int i = 0; i < numElements; i++) {
        this->stack.push_back(stack[i]);
    }
}
*/

// <<destructor>>
LocalStack::~LocalStack() {}

// untyped methods and manipulations
void LocalStack::push(MemObj datum) {
    this->stack.push_back(datum);
}

MemObj LocalStack::get(unsigned int i) {
    return this->stack.at(i);
}

void LocalStack::update(unsigned int i, MemObj val) {
    this->stack.at(i) = val;
}

/**
No Longer Allowed: Would cause a memory leak
void LocalStack::drop(unsigned int i) {
    this->stack.erase(this->stack.begin() + i);
}
**/
