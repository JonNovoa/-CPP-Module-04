#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>
#include <string>

class WrongAnimal
{
protected:
    std::string type;

public:
    WrongAnimal(void);
    ~WrongAnimal(void);  // ← SIN virtual (IMPORTANTE)

    void makeSound(void) const;  // ← SIN virtual (IMPORTANTE)
    
    std::string getType(void) const;
};

#endif