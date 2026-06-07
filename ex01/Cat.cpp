#include "Cat.hpp"

Cat::Cat() {
    this->type = "Cat";
    this->_brain = new Brain(); // Asignación de memoria dinámica
    std::cout << "Cat constructor called" << std::endl;
}

// COPIA PROFUNDA: Crea un NUEVO Brain basándose en el del otro objeto
Cat::Cat(const Cat& other) : Animal(other), _brain(NULL) {
    std::cout << "Cat copy constructor called (Deep Copy)" << std::endl;
    if (other._brain)
        this->_brain = new Brain(*other._brain);
    else
        this->_brain = new Brain();
}

// COPIA PROFUNDA: Borra el Brain antiguo y reserva uno nuevo
Cat& Cat::operator=(const Cat& other) {
    std::cout << "Cat assignment operator called (Deep Copy)" << std::endl;
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

Cat::~Cat() {
    delete this->_brain; // Liberar memoria obligatoria
    std::cout << "Cat destructor called" << std::endl;
}

void Cat::makeSound() const {
    std::cout << "Meow... Meow..." << std::endl;
}

void Cat::setIdea(int index, const std::string& idea) {
    if (index >= 0 && index < 100)
        this->_brain->ideas[index] = idea;
}

std::string Cat::getIdea(int index) const {
    if (index >= 0 && index < 100)
        return this->_brain->ideas[index];
    return "";
}