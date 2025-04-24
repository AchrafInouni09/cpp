#include "Cat.h"

Cat::Cat()
{
    type = "Cat";
    std::cout << "Cat Default constructor called\n";
}
Cat::Cat(const Cat &other): Animal(other)
{
    std::cout << "Cat Copy constructor called\n";
}

 Cat& Cat::operator=(const Cat &other)
 {
    if (this != &other)
    {
        this->type = other.type;
    }
    return (*this);
 }
Cat::~Cat()
{
    std::cout << "destructor Cat called\n";
}
void Cat::makeSound() const
{
    std::cout << "cats don't bark\n";
}