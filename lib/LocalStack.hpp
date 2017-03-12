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
        MemObj* get(unsigned int i);
        void update(unsigned int i, MemObj* val);
        /* DEPRECATED void drop(unsigned int i); */

        // get raw stack
        std::vector<MemObj*> getStack();
};

#endif
