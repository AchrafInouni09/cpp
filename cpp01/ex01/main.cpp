#include "Zombie.h"


int main()
{
    int n = 5;
    Zombie *zombie = Zombie::zombieHorde(n, "Achraf");

    delete [] zombie;
    
    return (0);
}