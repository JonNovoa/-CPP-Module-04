#ifndef AANIMAL_HPP
#define AANIMAL_HPP

#include <iostream>
#include <string>

class AAnimal {
protected:
    std::string type;

public:
    AAnimal();
    AAnimal(const AAnimal& other);
    AAnimal& operator=(const AAnimal& other);
    virtual ~AAnimal();

    // CRÍTICO: El `= 0` la convierte en una función VIRTUAL PURA.
    // Esto hace que la clase AAnimal sea ABSTRACTA automáticamente.
    virtual void makeSound() const = 0; 
    
    std::string getType() const;
};

#endif