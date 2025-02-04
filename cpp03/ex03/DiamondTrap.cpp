#include "DiamondTrap.h"


DiamondTrap::DiamondTrap() : 
    ClapTrap("default_clap_name"),
    ScavTrap("default_clap_name"),
    FragTrap("default_clap_name")
{
    this->name = "default";
    this->hitPoints = FragTrap::hitPoints;
    this->energyPoints = ScavTrap::energyPoints;
    this->attackDamage = FragTrap::attackDamage;
    std::cout << "DiamondTrap Default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const std::string& name) :
    ClapTrap(name + "_clap_name"),
    ScavTrap(name + "_clap_name"),
    FragTrap(name + "_clap_name")
{
    this->name = name;
    this->hitPoints = FragTrap::hitPoints;
    this->energyPoints = ScavTrap::energyPoints;
    this->attackDamage = FragTrap::attackDamage;
    std::cout << "DiamondTrap Named constructor called for " << name << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other) :
    ClapTrap(other),
    ScavTrap(other),
    FragTrap(other),
    name(other.name)
{
    std::cout << "DiamondTrap Copy constructor called" << std::endl;
}

DiamondTrap::~DiamondTrap() {
    std::cout << "DiamondTrap Destructor called for " << this->name << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other) {
    if (this != &other) {
        ClapTrap::operator=(other);
        this->name = other.name;
    }
    std::cout << "DiamondTrap Copy assignment operator called" << std::endl;
    return *this;
}

void DiamondTrap::whoAmI() {
    std::cout << "I am DiamondTrap " << this->name 
              << ", and my ClapTrap name is " << ClapTrap::name << std::endl;
}