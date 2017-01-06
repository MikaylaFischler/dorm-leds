#include "LocalStack.hpp"

// <<constructors>>
LocalStack::LocalStack() {}

LocalStack::LocalStack(MemObj datum) {
    this->stack.push_back(datum);
}

LocalStack::LocalStack(MemObj stack[], int numElements) {
    for(int i = 0; i < numElements; i++) {
        this->stack.push_back(stack[i]);
    }
}

// <<destructor>>
LocalStack::~LocalStack() {}

// untyped methods and manipulations
void LocalStack::push(void* datum) {
    this->stack.push_back(datum);
}

void* LocalStack::get(unsigned int i) {
    return this->stack.at(i);
}

void LocalStack::update(unsigned int i, void* val) {
    this->stack.at(i) = val;
}

/**
No Longer Allowed: Would cause a memory leak
void LocalStack::drop(unsigned int i) {
    this->stack.erase(this->stack.begin() + i);
}
**/

/* ~~~ Typed Get Functions ~~~ */

// boolean
bool LocalStack::getBool(unsigned int i) { return this->get(i).get<bool>(); }

// integers
int LocalStack::getInt(unsigned int i) { return this->get(i).get<int>(); }

short int LocalStack::getShortInt(unsigned int i) { return this->get(i).get<short int>(); }

long int LocalStack::getLongInt(unsigned int i) { return this->get(i).get<long int>(); }

unsigned int LocalStack::getUnsignInt(unsigned int i) { return this->get(i).get<unsigned int>(); }

unsigned short int LocalStack::getUnsignShortInt(unsigned int i) { return this->get(i).get<unsigned short int>(); }

unsigned long int LocalStack::getUnsignLongInt(unsigned int i) { return this->get(i).get<unsigned long int>(); }

// floating point numbers
float LocalStack::getFloat(unsigned int i) { return this->get(i).get<float>(); }

double LocalStack::getDouble(unsigned int i) { return this->get(i).get<double>(); }

long double LocalStack::getLongDouble(unsigned int i) { return this->get(i).get<long double>(); }

// text
char LocalStack::getChar(unsigned int i) { return this->get(i).get<char>(); }

unsigned char LocalStack::getUnsignChar(unsigned int i) { return this->get(i).get<unsigned char>(); }

String LocalStack::getString(unsigned int i) { return this->get(i).get<String>(); }

// some common arrays
bool* LocalStack::getBoolArray(unsigned int i) { return this->get(i).get<bool*>(); }

int* LocalStack::getIntArray(unsigned int i) { return this->get(i).get<int*>(); }

short int* LocalStack::getShortIntArray(unsigned int i) { return this->get(i).get<short int*>(); }
