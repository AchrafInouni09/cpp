#ifndef SCALARCONVERTER_H
#define SCALARCONVERTER_H

#include <iostream>
#include <cstdlib>
#include <iomanip>

class ScalarConverter 
{
    private:

    static void Print_Char(std::string s);
    static void Print_Int(std::string s);
    static void Print_Dbl(std::string s);
    static void Print_Flt(std::string s);
    bool        IsNumberParseable(std::string s);
    bool        IsLateral (std::string s);

    
    double To_Double(std::string s);
    float  To_Flaot(std::string s);
    int  To_Int (std::string s);
    
    public:

    static void PrintWord(std::string s);
    static void Convert(std::string s);
    ;
};

#endif