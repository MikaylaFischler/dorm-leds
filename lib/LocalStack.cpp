#include "LocalStack.h"

// <<constructors>>
LocalStack::LocalStack(){}

LocalStack::LocalStack(void*[] stack, int numElements){
    for(int i = 0; i < numElements; i++){
        this->stack.push_back(stack[i]);
    }
}

// <<destructor>>
LocalStack::~LocakStack(){}

// untyped methods
void LocalStack::push(void* datum){
    this->stack.push_back(datum);
}

void* LocalStack::get(unsigned int i){
    return this->stack.at(i);
}
