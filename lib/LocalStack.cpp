#include "LocalStack.h"

// <<constructors>>
LocalStack::LocalStack(){}

LocalStack::LocalStack(void* datum){
  this->stack.push_back(datum);
}

LocalStack::LocalStack(void* stack[], int numElements){
  for(int i = 0; i < numElements; i++){
    this->stack.push_back(stack[i]);
  }
}

// <<destructor>>
LocalStack::~LocalStack(){}

// untyped methods and manipulations
void LocalStack::push(void* datum){
  this->stack.push_back(datum);
}

void* LocalStack::get(unsigned int i){
  return this->stack.at(i);
}

void LocalStack::update(unsigned int i, void* val){
  this->stack.at(i) = val;
}

void LocalStack::drop(unsigned int i){
  this->stack.erase(this->stack.begin() + i);
}

// typed get functions
// boolean
bool LocalStack::getBool(unsigned int i){
  void* stack_ptr = this->get(i);
	bool* ptr = (bool*) stack_ptr;
	return *ptr;
}

// integers
int LocalStack::getInt(unsigned int i){
  void* stack_ptr = this->get(i);
  int* ptr = (int*) stack_ptr;
  return *ptr;
}

short int LocalStack::getShortInt(unsigned int i){
  void* stack_ptr = this->get(i);
  short int* ptr = (short int*) stack_ptr;
  return *ptr;
}

long int LocalStack::getLongInt(unsigned int i){
  void* stack_ptr = this->get(i);
  long int* ptr = (long int*) stack_ptr;
  return *ptr;
}

unsigned int LocalStack::getUInt(unsigned int i){
  void* stack_ptr = this->get(i);
  unsigned int* ptr = (unsigned int*) stack_ptr;
  return *ptr;
}

unsigned short int LocalStack::getUnsignShortInt(unsigned int i){
  void* stack_ptr = this->get(i);
  unsigned short int* ptr = (unsigned short int*) stack_ptr;
  return *ptr;
}

unsigned long int LocalStack::getUnsignLongInt(unsigned int i){
  void* stack_ptr = this->get(i);
  unsigned long int* ptr = (unsigned long int*) stack_ptr;
  return *ptr;
}

// floating point numbers
float LocalStack::getFloat(unsigned int i){
  void* stack_ptr = this->get(i);
  float* ptr = (float*) stack_ptr;
  return *ptr;
}

double LocalStack::getDouble(unsigned int i){
  void* stack_ptr = this->get(i);
  double* ptr = (double*) stack_ptr;
  return *ptr;
}

long double LocalStack::getLongDouble(unsigned int i){
  void* stack_ptr = this->get(i);
  long double* ptr = (long double*) stack_ptr;
  return *ptr;
}

// text
char LocalStack::getChar(unsigned int i){
  void* stack_ptr = this->get(i);
  char* ptr = (char*) stack_ptr;
  return *ptr;
}

unsigned char LocalStack::getUnsignChar(unsigned int i){
  void* stack_ptr = this->get(i);
  unsigned char* ptr = (unsigned char*) stack_ptr;
  return *ptr;
}

String LocalStack::getString(unsigned int i){
  void* stack_ptr = this->get(i);
  String* ptr = (String*) stack_ptr;
  return *ptr;
}

// some common arrays
bool* LocalStack::getBoolArray(unsigned int i){
  void* stack_ptr = this->get(i);
  bool* ptr = (bool*) stack_ptr;
  return ptr;
}

int* LocalStack::getIntArray(unsigned int i){
  void* stack_ptr = this->get(i);
  int* ptr = (int*) stack_ptr;
  return ptr;
}

short int* LocalStack::getShortIntArray(unsigned int i){
  void* stack_ptr = this->get(i);
  short int* ptr = (short int*) stack_ptr;
  return ptr;
}
