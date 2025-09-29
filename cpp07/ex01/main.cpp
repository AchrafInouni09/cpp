#include <iostream>
#include <string>
#include "iter.h"

template <typename T>

void print( T const &data)
{
    std::cout << data << std::endl;
}

int main (void)
{
    int tab[] = {0, 1, 2, 3, 4};
    std::string str[] = {"Hello", "World", "!"};

    int tab2[] = {};
    double tab3[] = {21,22, 252,99};
    char  tab4[] = {'c', 'a', 'r', 't'};
    

    Iter<int> it;
    it.iter(tab, 5, print);

    Iter<std::string> it2;
    it2.iter(str, 3, print);

    Iter<int> it3;
    it3.iter(tab2, 0, print);

    Iter<double> it4;
    it4.iter(tab3, 4, print);

    Iter<char> it5;
    it5.iter(tab4, 4, print);
    
    return 0;
}