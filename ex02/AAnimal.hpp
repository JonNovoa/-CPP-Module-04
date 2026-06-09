#ifndef AANIMAL_HPP
#define AANIMAL_HPP

#include <iostream>
#include <string>

class AAnimal {
protected:
    std::string type;

public:
    AAnimal();
    AAnimal(const AAnimal& src);
    AAnimal& operator=(const AAnimal& src);
    virtual ~AAnimal();

    // El "= 0" convierte a la clase en Abstracta (no instanciable)
    virtual void makeSound() const = 0; 
    std::string getType() const;
};

#endif