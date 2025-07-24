#include <iostream>
#include "ScalarConverter.h"
// #include <cstdlib>

using namespace std;


std::string trim(const std::string& s)
{
    size_t start = s.find_first_not_of(" \t\n\r");
    size_t end = s.find_last_not_of(" \t\n\r");
    if (start == std::string::npos)
        return "";
    return s.substr(start, end - start + 1);
}

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cout << "error no paramter : ./convert <p>\n";
        return (1);
    }


    // cout <<  ScalarConverter::IsNumberParseable(argv[1])  << endl;
    ScalarConverter::Convert(argv[1]);

    // -inff, +inff and nanf

    // -inf, +inf and nan.

    // std::cout << atof(argv[1]) << endl;

    return (0);
}