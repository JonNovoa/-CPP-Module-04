#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal {
private:
    Brain* _brain; // Atributo privado obligatorio

public:
    Dog();
    Dog(const Dog& other);
    Dog& operator=(const Dog& other);
    virtual ~Dog();

    virtual void makeSound() const;
    
    // Funciones auxiliares para verificar la copia profunda en el main
    void setIdea(int index, const std::string& idea);
    std::string getIdea(int index) const;
};

#endif