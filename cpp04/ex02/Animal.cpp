#include "Animal.h"

Animal::Animal() : type ("default")
{
    std::cout << "Animal Default constructor called\n";
}
Animal::Animal(const Animal &other) : type(other.type)
{
    
}
Animal &Animal::operator=(const Animal &other)
{
    if (this != &other)
    {
        type = other.type;
    }
    return (*this);
}
Animal::~Animal()
{
    std::cout << "destructor animal called\n";
}

std::string Animal::getType() const
{
    return (type);
}