#include "Zombie.h"

Zombie::Zombie()
{
}

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
Zombie* Zombie::newZombie( std::string name )
{
    Zombie *zombie = new Zombie(name);
    return (zombie);
}
void Zombie::randomChump( std::string name )
{
    Zombie zombie(name);
    zombie.announce();
}
void Zombie::setName(std::string name)
{
    _name = name;
}

Zombie::~Zombie()
{
    std::cout << "Zombie " << _name << " is dead" << std::endl;
}