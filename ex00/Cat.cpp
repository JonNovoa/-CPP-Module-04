#include "Cat.hpp"

Cat::Cat(void)
{
    this->type = "Cat";
    std::cout << "Cat constructor called" << std::endl;
}

Cat::~Cat(void)
{
    std::cout << "Cat destructor called" << std::endl;
}

void Cat::makeSound(void) const
{
    std::cout << "Meow! Meow!" << std::endl;
}