#include "Dog.hpp"

Dog::Dog(void)
{
    this->type = "Dog";
    std::cout << "Dog constructor called" << std::endl;
}

Dog::~Dog(void)
{
    std::cout << "Dog destructor called" << std::endl;
}

void Dog::makeSound(void) const
{
    std::cout << "Woof! Woof!" << std::endl;
}