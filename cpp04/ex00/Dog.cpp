#include "Dog.h"

Dog::Dog()
{
    type = "dog";
    std::cout << "Dog Default constructor called\n";
}
Dog::Dog(const Dog &other): Animal(other)
{
    std::cout << "Dog Copy constructor called\n";
}

 Dog& Dog::operator=(const Dog &other)
 {
    if (this != &other)
    {
        this->type = other.type;
    }
    return (*this);
 }
Dog::~Dog()
{
    std::cout << "destructor dog called\n";
}
void Dog::makeSound() const
{
    std::cout << "Hey I'm " << type << " howhow\n";
}