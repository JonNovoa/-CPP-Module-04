#include "Animal.hpp"

Animal::Animal(void)
{
    std::cout << "Animal constructor called" << std::endl;
}

Animal::~Animal(void)
{
    std::cout << "Animal destructor called" << std::endl;
}

std::string Animal::getType(void) const
{
    return this->type;
}