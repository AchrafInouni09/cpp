#include "ScavTrap.h"




ScavTrap::ScavTrap() : ClapTrap() 
{
    hitPoints = 10;
    energyPoints  = 10;
    attackDamage = 0;

    std::cout << "ScavTrap Constructor called\n";
}
ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name)
{
    this->name = name;
    hitPoints = 10;
    energyPoints  = 10;
    attackDamage = 0;

    std::cout << "ScavTrap Constructor called\n";
}
ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other)
{
    std::cout << "ScavTrap Copy Constructor called\n";
}


ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap Desructor called\n";
}

ScavTrap& ScavTrap::operator=(const ScavTrap &other)
{
    if (this != &other)
    {
        ClapTrap::operator=(other);
    }

    
    return (*this);
}
void ScavTrap::attack(const std::string& target)
{
    if (energyPoints == 0) {
        std::cout << "ScavTrap " << name << " has no energy points left to attack!" << std::endl;
        return;
    }
    if (hitPoints == 0) {
        std::cout << "ScavTrap " << name << " is dead and cannot attack!" << std::endl;
        return;
    }
    
    energyPoints--;
    std::cout << "ScavTrap " << name << " attacks " << target 
              << ", causing " << attackDamage << " points of damage!" << std::endl;

}

void ScavTrap::guardGate()
{
     std::cout << "ScavTrap " << name << " is now in Gate keeper mode" << std::endl;
}