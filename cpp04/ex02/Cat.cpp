#include "Cat.h"

Cat::Cat() : brain(new Brain())
{
    type = "Cat";
    std::cout << "Cat Default constructor called\n";
}

Cat::Cat(const Cat &other): Animal(other), brain(new Brain(*other.brain))
{
    std::cout << "Cat Copy constructor called\n";
}


 Cat& Cat::operator=(const Cat &other)
 {
    if (this != &other)
    {
        Animal::operator=(other);
        *brain = *other.brain;
    }
    return (*this);
 }
Cat::~Cat()
{
    delete brain;
    std::cout << "destructor Cat called\n";
}
void Cat::makeSound() const
{
    std::cout << "cats don't bark\n";
}

Brain* Cat::getBrain() const
{
    return brain;
}