#include "DiamondTrap.h"

int main() {
    DiamondTrap diamond("Diamond");
    
    diamond.whoAmI();
    diamond.attack("Enemy");
    diamond.guardGate();
    diamond.highFivesGuys();
    
    DiamondTrap diamond2(diamond);
    diamond2.whoAmI();
    
    DiamondTrap diamond3;
    diamond3 = diamond;
    diamond3.whoAmI();
    
    return 0;
}