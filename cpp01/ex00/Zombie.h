#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <iostream>
#include <cstring>

class Zombie
{
    private : 
        std::string _name;
    public : 

        Zombie(std::string name);

        void announce();

        static Zombie* newZombie( std::string name );

        static void randomChump( std::string name );

        ~Zombie();
};
#endif