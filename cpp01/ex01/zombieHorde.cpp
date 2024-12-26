#include "Zombie.h"

Zombie* Zombie::zombieHorde( int N, std::string name )
{
    Zombie *zombie = new Zombie[N];
    for (int i = 0; i < N; i++)
    {
        // new (&zombie[i])  Zombie(name);
        zombie[i].setName(name);

    }
    return (zombie);
}
