#include "Fixed.h"
#include <iostream>

int main(void) {
    Fixed a;
    Fixed const b(Fixed(5.05f) * Fixed(2));

    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << Fixed::max(a, b) << std::endl;

    // to be deleted;

    // Fixed z(1);
    // Fixed const e(88);

    // std::cout << "z : " << z.toFloat() << "\n";
    // std::cout << "e : " << e.toFloat() << "\n";
    // std::cout << "Hello : " << Fixed::min(a, b);

    return 0;
}