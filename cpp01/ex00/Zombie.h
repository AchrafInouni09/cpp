#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <iostream>
#include <cstring>

class Zombie
{
    private : 
        std::string _name;
    public : 

        Zombie(std::string name)
        {
            _name = name;
        }

        void announce()
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

        static Zombie* newZombie( std::string name );
        static void randomChump( std::string name );

        ~Zombie()
        {
            std::cout << "Zombie " << _name << "is dead" << std::endl;
        }
};
#endif