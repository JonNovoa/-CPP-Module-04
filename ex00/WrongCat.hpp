#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
public:
    WrongCat(void);
    ~WrongCat(void);  // ← SIN virtual

    void makeSound(void) const;  // ← SIN virtual
};

#endif