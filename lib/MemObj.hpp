#ifndef MemObj_H
#define MemObj_H

class MemObj {
private:
    void* var;
public:
    MemObj (void* var);
    ~MemObj ();

    template <typename mem_type> mem_type& get ();
    template <typename mem_type> void set (mem_type* new_var);
    template <typename mem_type> void destroy ();
};

#endif
