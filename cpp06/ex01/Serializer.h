#ifndef SERIALIZER_H
#define SERIALIZER_H


#include <iostream>
// #include <cstdint>
#include <stdint.h>
#include <iomanip>


struct Data
{
    int nb;
    double dbl;
    char letter;
    float flt;
};



class Serializer
{

    public : 

    static uintptr_t serialize(Data* ptr);
    static Data* deserialize(uintptr_t raw);

};

#endif