#include "MemObj.hpp"

// <<constructor>>
MemObj::MemObj(void* var) { this->var = var; }

// <<destructor>>
// WARNING: YOU MUST CALL DESTROY WHEN THIS OBJECT IS DONE BEING USED [WITH KNOWLEDGE OF THE TYPE]
// OTHERWISE THE 'var' WILL BE A MEMORY LEAK
MemObj::~MemObj() {}

// get the data
template <typename mem_type>
mem_type& MemObj::get() { return *(reinterpret_cast<mem_type*>(var)); }

// get the data as a pointer
template <typename mem_type>
mem_type* MemObj::getpointer() { return reinterpret_cast<mem_type*>(var); }

// free the memory
template <typename mem_type>
void MemObj::destroy() { delete reinterpret_cast<mem_type*>(var); }

// free the memory as an array
template <typename mem_type>
void MemObj::destroyarray() { delete[] (mem_type*) var; }
