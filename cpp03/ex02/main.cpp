#include "FragTrap.h"

int main() {
    
    FragTrap frag1("Warrior");
    FragTrap frag2(frag1);
    FragTrap frag3;
    frag3 = frag1;

    
    frag1.highFivesGuys();

    frag1.attack("Enemy");
    frag1.takeDamage(30);
    frag1.beRepaired(20);

    return 0;
}