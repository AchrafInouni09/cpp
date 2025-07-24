#ifndef BASE_H
#define BASE_H


#include <iostream>
#include <cstdlib>

#include <cstdlib>
#include <ctime>


class Base
{
    public : 

    virtual ~Base();
    static Base * generate(void);
    static void   identify(Base* p);
    static void identify(Base& p);

};


#endif  
