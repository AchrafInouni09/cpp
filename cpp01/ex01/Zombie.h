#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <iostream>
#include <cstring>

class Zombie
{
    private : 
        std::string _name;
    public : 

        Zombie();

        Zombie(std::string name);

        void announce();

        Zombie* newZombie( std::string name );

        void randomChump( std::string name );

        void setName(std::string name);

        static Zombie* zombieHorde( int N, std::string name );

        ~Zombie();
};
#endif