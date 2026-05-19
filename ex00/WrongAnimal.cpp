#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void)
{
    std::cout << "WrongAnimal constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal(void)
{
    std::cout << "WrongAnimal destructor called" << std::endl;
}

void WrongAnimal::makeSound(void) const
{
    std::cout << "Generic wrong sound" << std::endl;
}

std::string WrongAnimal::getType(void) const
{
    return this->type;
}