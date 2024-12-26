#include "Zombie.h"


int main()
{
    Zombie zombie("Achraf");
    zombie.announce();


    Zombie *zombie2 = zombie.newZombie("Foo");
    zombie2->announce();

    delete zombie2;
}