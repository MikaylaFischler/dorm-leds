#ifndef MEMOBJ_HPP_
#define MEMOBJ_HPP_

class MemObj {
private:
    void* var;
public:
    MemObj(void* var);
    ~MemObj();

    template <typename mem_type> mem_type& get();
	template <typename mem_type> mem_type* getpointer();
    template <typename mem_type> void destroy();
    template <typename mem_type> void destroyarray();
};

#endif
