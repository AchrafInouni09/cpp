#include "ScalarConverter.h"




ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter (const ScalarConverter &) {}
ScalarConverter &ScalarConverter::operator= (const ScalarConverter&other)
{
    if (this != &other)
    {
        *this = other;
    }
    return (*this);
}
ScalarConverter::~ScalarConverter() {}


void ScalarConverter::PrintWord(std::string s)
{
    std::cout << "s : " <<   s << std::endl;
}


// double Convert::To_Double(std::string s)
// {
//     double  result = 0.0;
//     int     i =  0;
//     short   sign = 1;

//     while ((i < (int)s.length()) && isspace(s[i]))
//         i++;

//     while (i < (int)s.length() && (s[i] == '+' || s[i] == '-'))
//     {
//         if (s[i] == '-')
//             sign *= -1;
//         i++;
//     }

//     while (i < (int)s.length() && isdigit(s[i]))
//     {
//         result = (result * 10.0) + (s[i] -'0');
//         i++;
//     }

//     if (s[i] == '.')
//     {
//         // std::cout << "fraction part found\n";
//         i++;

//         double frac = 0.0;
//         double base = 0.1;

//         while (i < (int)s.length() && isdigit(s[i]))
//         {
//             frac += (s[i] - '0') * base;
//             base *= 0.1;
//             i++;
//         }
//         // std::cout << "frac : " << frac  << std::endl;
//         // std::cout << "result : " << result << std::endl;
//         result += frac;
//     }
       
//     // std::cout << "i : " << i << "\n";
//     // std::cout << "result before returning : " << result << std::endl;
//     return (result * sign);
// }

double ScalarConverter::To_Double(std::string s)
{
    const char *s1 = s.c_str(); 
    return ((double)atof(s1));
}

float ScalarConverter::To_Flaot(std::string s)
{
    const char *s1 = s.c_str();
    return (atof(s1));

}

void ScalarConverter::Convert(std::string s)
{
    if (s.empty())
    {
        std::cout << "empty argument.\n";
        return ;
    }

    std::cout << "===========\n";

    Print_Char(s);
    Print_Int(s);
    Print_Flt(s);
    Print_Dbl(s);

    std::cout << "===========\n";
}



bool ScalarConverter::IsNumberParseable(std::string s)
{
    int i=0;

    while (s[i] && isspace(s[i]))
        i++;

    while (s[i] && s[i] != '.')
    {
        if (!isdigit(s[i]))
            return (false);
        i++;
    }

    if (s[i] == '.')
    {
        if (!s[i+1])
            return (false);
        if (!isdigit(s[i + 1]))
            return (false);
        // std::cout << ". found\n";
        i++;
        while (s[i])
        {
            if (s[i] != 'f' && !isdigit(s[i]))
                return (false);
            if (s[i] == 'f' &&  s[i + 1])
                return (false);
            i++;
        }
    }
    return (true);
}

int ScalarConverter::To_Int(std::string s)
{
    const char *s1 = s.c_str();
    return (atoi(s1));
}


void    ScalarConverter::Print_Char(std::string s)
{
    if (s.length() == 1)
    {
        if (isdigit(s[0]))
        {
            std::cout << "char   : non displayable\n";
            return;
        }

        if (isprint(s[0]))
        {
            std::cout << "char   : " << s[0] << "\n";
        }
    }
    else
    {
        ScalarConverter tmp;

        if (tmp.IsNumberParseable(s))
        {
            std::cout << "char: '*'\n";
        }
        else
        {
            std::cout << "char   : impossible\n";
        }
    }
}

void ScalarConverter::Print_Int(std::string s)
{
    ScalarConverter tmp;
    if (tmp.IsNumberParseable(s))
    {
        std::cout << "int     : " << tmp.To_Int(s) << "\n";
    }
    else
    {
        std::cout << "int     : impossible\n";
    }
}

bool ScalarConverter::IsLateral (std::string s)
{
    return ((s == "-inff") || (s == "+inff") || (s == "nanf") || 
            (s == "-inf") || (s == "+inf") || (s == "nan"));
}

void ScalarConverter::Print_Dbl(std::string s)
{
    ScalarConverter tmp;

    if (tmp.IsNumberParseable(s) || tmp.IsLateral(s))
    {
        std::cout << "double   : " << std::fixed  << std::setprecision(1) <<  tmp.To_Double (s) << "\n";

    }
    else
    {
        std::cout << "double  :  impossible\n";

    }
}

void ScalarConverter::Print_Flt(std::string s)
{
    ScalarConverter tmp;

    if (tmp.IsNumberParseable(s) || tmp.IsLateral(s))
    {
        std::cout << "float   : " <<  std::fixed  << std::setprecision(1) << tmp.To_Flaot (s) << "f\n";
    }
    else
    {
        std::cout << "float   :  impossible\n";
    }
    // chech if parseable;
}



