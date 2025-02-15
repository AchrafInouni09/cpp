#include "Zombie.h"


int main()
{
    int n = 5;
    Zombie *zombie = Zombie::zombieHorde(n, "Achraf");

    for (short i = 0; i < n; i++)
    {
        zombie[i].announce();
    }

    delete [] zombie;
    
    return (0);
}