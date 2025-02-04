#include "ClapTrap.h"

int main() {
    // Test constructor
    ClapTrap clap1("Clappy");
    ClapTrap clap2("Trappy");

    // Test attack and damage
    clap1.attack("Enemy");
    clap2.takeDamage(5);

    // Test repair
    clap2.beRepaired(3);

    // Test energy points depletion
    for (int i = 0; i < 10; i++) {
        clap1.attack("Enemy");
    }
    // Should fail due to no energy points
    clap1.attack("Enemy");

    // Test death
    clap2.takeDamage(8);
    // Should fail due to being dead
    clap2.attack("Enemy");
    clap2.beRepaired(5);

    // Test copy constructor
    ClapTrap clap3(clap1);
    clap3.attack("Enemy");

    return 0;
}