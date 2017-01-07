#include "MemObj.hpp"

// <<constructor>>
MemObj::MemObj(void* var) { this->var = var; }

// <<destructor>>
// WARNING: YOU MUST CALL DESTROY WHEN THIS OBJECT IS DONE BEING USED [WITH KNOWLEDGE OF THE TYPE]
// OTHERWISE THE `var` WILL BE A MEMORY LEAK
MemObj::~MemObj() {}

// get the data
mem_type& MemObj::get() { return (mem_type&) data; }

/*
// update the data
void MemObj::set(mem_type* new_data) {
    delete (mem_type*) data;
    this->data = new_data;
}
*/

// free the memory
void MemObj::destroy() { delete (mem_type*) data; }
