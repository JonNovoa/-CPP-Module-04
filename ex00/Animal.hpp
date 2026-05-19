#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>

class Animal
{
protected:
    std::string type;

public:
    Animal(void);
    virtual ~Animal(void);

    virtual void makeSound(void) const = 0;
    std::string getType(void) const;  // ← ASEGÚRATE DE QUE ESTÉ

};

#endif