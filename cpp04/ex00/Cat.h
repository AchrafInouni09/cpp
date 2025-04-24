#ifndef CAT_H
# define CAT_H

#include "Animal.h"


class Cat : public Animal
{
    public :
        Cat();
        Cat(const Cat &other);
        Cat& operator=(const Cat &other);
        ~Cat();
        virtual void makeSound() const;
};


#endif