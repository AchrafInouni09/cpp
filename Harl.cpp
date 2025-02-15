#include "Harl.h"

void Harl::_debug(void)
{
    std::cout << "Debug message" << std::endl;
}

void Harl::_info(void)
{
    std::cout << "Info message" << std::endl;
}

void Harl::_warning(void)
{
    std::cout << "Warning message" << std::endl;
}

void Harl::_error(void)
{
    std::cout << "Error message" << std::endl;
}

void Harl::complain( std::string level )
{
    void(Harl::*f[4])(void) = {&Harl::_debug, &Harl::_info, &Harl::_warning ,&Harl::_error};
    std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    for (short i = 0; i < 4; i++)
    {
        if (levels[i] == level)
            (this->*f[i])();
    }
}