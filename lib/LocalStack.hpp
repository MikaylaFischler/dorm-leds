#ifndef LocalStack_H
#define LocalStack_H

#include <StandardCplusplus.h>
#include <vector>

class LocalStack {
    private:
        std::vector<MemObj> stack;
    public:
        LocalStack();
        LocalStack(MemObj mem);
        LocalStack(MemObj stack[], int numElements);
        ~LocalStack();

        // untyped element manipulation
        void push(MemObj element);
        MemObj get(unsigned int i);
        void update(unsigned int i, MemObj val);
        /* DEPRECATED void drop(unsigned int i); */

        // get raw stack
        std::vector<MemObj> getStack();

        /* ~~~ Typed Getters ~~~ */
        // bool
        bool getBool(unsigned int i);

        // integers
        int getInt(unsigned int i);
        short int getShortInt(unsigned int i);
        long int getLongInt(unsigned int i);
        unsigned int getUnsignInt(unsigned int i);
        unsigned short int getUnsignShortInt(unsigned int i);
        unsigned long int getUnsignLongInt(unsigned int i);

        // floating point numbers
        float getFloat(unsigned int i);
        double getDouble(unsigned int i);
        long double getLongDouble(unsigned int i);

        // text
        char getChar(unsigned int i);
        unsigned char getUnsignChar(unsigned int i);
        String getString(unsigned int i);

        // some common arrays
        bool * getBoolArray(unsigned int i);
        int * getIntArray(unsigned int i);
        short int * getShortIntArray(unsigned int i);
};

#endif
