#ifndef CLAPTRAP_H
#define CLAPTRAP_H

#include <string>
#include <iostream>

class ClapTrap 
{
private:
    std::string name;
    unsigned int hitPoints;
    unsigned int energyPoints;
    unsigned int attackDamage;

public:
    // Orthodox Canonical Form
    ClapTrap();                              // Default constructor
    ClapTrap(const std::string& name);       // Parameterized constructor
    ClapTrap(const ClapTrap& other);         // Copy constructor
    ~ClapTrap();                             // Destructor
    ClapTrap& operator=(const ClapTrap& other); // Assignment operator

    // Member functions
    void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
};

#endif