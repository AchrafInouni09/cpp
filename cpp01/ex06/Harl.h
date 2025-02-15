#ifndef HARL_H
#define HARL_H

#include <iostream>

class Harl
{
private:
    std::string _level;
    void debug(void);
    void info(void);
    void warning(void);
    void error(void);

public:
    Harl(std::string level);
    void complain();
    short GetIndex(std::string level);
};

#endif