#include "Animal.h"
#include "Dog.h"
#include "Cat.h"


int main()
{
    // Test basic functionality
    // const Animal* j = new Dog();
    // const Animal* i = new Cat();

    // delete j;
    // delete i;

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

    Dog dog1;
    dog1.getBrain()->setIdea(0, "Chase the ball");
    Dog dog2(dog1);
    dog2.getBrain()->setIdea(0, "Eat food");

    std::cout << "Dog1 Brain Idea: " << dog1.getBrain()->getIdea(0) << std::endl;
    std::cout << "Dog2 Brain Idea: " << dog2.getBrain()->getIdea(0) << std::endl;

    return 0;
}
