#include "LocalStack.hpp"

// <<constructors>>
LocalStack::LocalStack() {}

// <<destructor>>
// do NOT call this unless each memory object has already been deleted
// you will lose the pointers to the memory and it will become a memory leak
LocalStack::~LocalStack() {}

/* ~~~ untyped methods and manipulations ~~~ */

// push a new memory object into the vector
void LocalStack::push(MemObj* datum) {
    this->stack.push_back(datum);
}

// replace a memory object in the vector
// note: is a memory leak UNLESS you delete the origional memobj first
void LocalStack::replace(unsigned int i, MemObj* val) {
    this->stack.at(i) = val;
}

// get a memory object from the vector
MemObj* LocalStack::get(unsigned int i) const {
    return this->stack.at(i);
}

// remove a memory object pointer from the vector
// note: is a memory leak UNLESS you delete the memobj first
void LocalStack::drop(unsigned int i) {
    this->stack.erase(this->stack.begin() + i);
}

std::vector<MemObj*> LocalStack::getStack() const { return this->stack; }
