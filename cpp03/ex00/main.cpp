#include "ClapTrap.h"

int main()
{
    ClapTrap clap1("Clappy");
    ClapTrap clap2("Trappy");

    clap1.attack("Enemy");
    clap2.takeDamage(5);

    clap2.beRepaired(3);

    for (int i = 0; i < 10; i++)
    {
        clap1.attack("Enemy");
    }
    clap1.attack("Enemy");


    clap2.takeDamage(8);

    clap2.attack("Enemy");
    clap2.beRepaired(5);

    ClapTrap clap3(clap1);
    clap3.attack("Enemy");

    return 0;
}