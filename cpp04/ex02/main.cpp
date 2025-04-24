#include "Animal.h"
#include "Dog.h"
#include "Cat.h"


int main()
{
    const Animal* j = new Dog();
    const Animal* i = new Cat();


    j->makeSound();
    i->makeSound();

    delete j;
    delete i;

    std::cout << "-------------------" << std::endl;

    const Animal* animals[4];
    for (int k = 0; k < 2; ++k)
    {
        animals[k] = new Dog();
    }
    for (int k = 2; k < 4; ++k)
    {
        animals[k] = new Cat();
    }

    for (int k = 0; k < 4; ++k)
    {
        animals[k]->makeSound();
    }

    for (int k = 0; k < 4; ++k)
    {
        delete animals[k];
    }


    return 0;
}
