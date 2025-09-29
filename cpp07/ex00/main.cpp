#include <iostream>

#include "whatever.h"




int main( void )
{
    int a = 10, b = 20;
    std::cout << "a = " << a << ", b = " << b << std::endl;

    Whatever <int> w;

    w.swap( a, b );

    std::cout << "a = " << a << ", b = " << b << std::endl;


    double c = 100, d = 20;
    std::cout << "c = " << c << ", d = " << d << std::endl;

    Whatever <double> z;


    w.swap( a, b );

    std::cout << " min c = " << c << ", d = " << d <<   " is " << w.min(c, d)  <<  std::endl;
    return 0;
}
