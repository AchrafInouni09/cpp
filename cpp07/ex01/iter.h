#ifndef ITER_H
#define ITER_H

template <typename T>

class Iter 
{
    public:
    Iter() {}
    Iter (const Iter &other)
    {
        *this = other;
    }
    Iter &operator=(const Iter &other)
    {
        if (this != &other)
        {

        }
        return *this;
    }
    ~Iter() {}

    void  iter(T *array, int length, void (*f)(T const &))
    {
        for (int i = 0; i < length; i++)
        {
            f(array[i]);
        }
            
    }
};


#endif
