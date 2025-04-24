#include "Dog.h"

Dog::Dog() :  brain(new Brain())
{
    type = "dog";
    std::cout << "Dog Default constructor called\n";
}
Dog::Dog(const Dog &other): Animal(other), brain (new Brain(*other.brain))
{
    std::cout << "Dog Copy constructor called\n";
}

 Dog& Dog::operator=(const Dog &other)
 {
    if (this != &other)
    {
        Animal::operator=(other);
        *brain = *other.brain;
    }
    return (*this);
 }
Dog::~Dog()
{
    delete brain;
    std::cout << "destructor dog called\n";
}
void Dog::makeSound() const
{
    std::cout << "Hey I'm " << type << " howhow\n";
}

Brain* Dog::getBrain() const
{
    return brain;
}