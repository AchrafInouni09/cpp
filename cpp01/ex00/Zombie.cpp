#include "Zombie.h"

Zombie::Zombie(std::string name)
{
    _name = name;
}

void Zombie::announce()
{
    bool isfound = 0;
    if (strcmp(_name.c_str(),"Foo"))
    {
        std::cout << "<";
        isfound = 1;
    }
    std::cout << _name;
    if (isfound)
        std::cout << ">";
    std::cout << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::~Zombie()
{
    std::cout << "Zombie " << _name << "is dead" << std::endl;
}
