#include "WrongCat.hpp"

WrongCat::WrongCat(void)
{
    this->type = "WrongCat";
    std::cout << "WrongCat constructor called" << std::endl;
}

WrongCat::~WrongCat(void)
{
    std::cout << "WrongCat destructor called" << std::endl;
}

void WrongCat::makeSound(void) const
{
    std::cout << "Wrong cat meow" << std::endl;
}