#include "HumanB.h"

HumanB::HumanB(std::string name): name(name), weapon(NULL) {};

void HumanB::setWeapon(Weapon &weapon)
{
    this->weapon = &weapon;
}
void HumanB::attack()
{
    std::cout << this->name << " attacks with his " << this->weapon->getType() << std::endl;
}