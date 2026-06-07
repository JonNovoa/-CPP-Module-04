#include "Dog.hpp"

Dog::Dog() {
    this->type = "Dog";
    this->_brain = new Brain(); // Asignación de memoria dinámica
    std::cout << "Dog constructor called" << std::endl;
}

// COPIA PROFUNDA: Crea un NUEVO Brain basándose en el del otro objeto
Dog::Dog(const Dog& other) : Animal(other), _brain(NULL) {
    std::cout << "Dog copy constructor called (Deep Copy)" << std::endl;
    if (other._brain)
        this->_brain = new Brain(*other._brain);
    else
        this->_brain = new Brain();
}

// COPIA PROFUNDA: Borra el Brain antiguo y reserva uno nuevo
Dog& Dog::operator=(const Dog& other) {
    std::cout << "Dog assignment operator called (Deep Copy)" << std::endl;
    if (this != &other) {
        Animal::operator=(other);
        delete this->_brain; // Liberar memoria vieja para evitar leaks
        if (other._brain)
            this->_brain = new Brain(*other._brain);
        else
            this->_brain = new Brain();
    }
    return *this;
}

Dog::~Dog() {
    delete this->_brain; // Liberar memoria obligatoria
    std::cout << "Dog destructor called" << std::endl;
}

void Dog::makeSound() const {
    std::cout << "Woof! Woof!" << std::endl;
}

void Dog::setIdea(int index, const std::string& idea) {
    if (index >= 0 && index < 100)
        this->_brain->ideas[index] = idea;
}

std::string Dog::getIdea(int index) const {
    if (index >= 0 && index < 100)
        return this->_brain->ideas[index];
    return "";
}