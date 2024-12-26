#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <iostream>
#include <cstring>

class Zombie
{
    private : 
        std::string _name;
    public : 

        Zombie (){}
        
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
        Zombie* newZombie( std::string name )
        {
            Zombie *zombie = new Zombie(name);
            return (zombie);
        }
        void randomChump( std::string name )
        {
            Zombie zombie(name);
            zombie.announce();
        }

        void setName(std::string name)
        {
            _name = name;
        }

        static Zombie* zombieHorde( int N, std::string name );


        ~Zombie()
        {
            std::cout << "Zombie " << _name << " is dead" << std::endl;
        }
};
#endif