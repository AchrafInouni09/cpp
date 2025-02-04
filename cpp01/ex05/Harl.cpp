#include "Harl.h"

void Harl::debug(void)
{
    std::cout << "Debug message" << std::endl;
}

void Harl::info(void)
{
    std::cout << "Info message" << std::endl;
}

void Harl::warning(void)
{
    std::cout << "Warning message" << std::endl;
}

void Harl::error(void)
{
    std::cout << "Error message" << std::endl;
}

void Harl::complain( std::string level )
{
    void (Harl::*f[4])(void) = { &Harl::debug, &Harl::info, &Harl::warning, &Harl::error };
    std::string levels[4] = { "DEBUG", "INFO", "WARNING", "ERROR" };
    for (int i = 0; i < 4; i++)
    {
        if (levels[i] == level)
            (this->*f[i])();
    }
}