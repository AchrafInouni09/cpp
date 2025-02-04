#ifndef HumanB_H
#define HumanB_H

#include "Weapon.h"

class HumanB
{
    private:
        std::string name;
        Weapon *weapon;

    public:
        HumanB(std::string name): name(name), weapon(NULL) {};
        void setWeapon(Weapon &weapon);
        void attack();
};



# endif