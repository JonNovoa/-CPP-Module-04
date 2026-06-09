#include "Dog.hpp"

Dog::Dog() {
    std::cout << "Dog: Constructor por defecto." << std::endl;
    this->type = "Dog";
    this->_brain = new Brain();
}

Dog::Dog(const Dog& src) : AAnimal(src) {
    std::cout << "Dog: Constructor de copia." << std::endl;
    this->_brain = new Brain(*src._brain); // Copia profunda
}

Dog& Dog::operator=(const Dog& src) {
    std::cout << "Dog: Operador de asignación." << std::endl;
    if (this != &src) {
        this->type = src.type;
        delete this->_brain;
        this->_brain = new Brain(*src._brain); // Copia profunda
    }
    return *this;
}

Dog::~Dog() {
    std::cout << "Dog: Destructor." << std::endl;
    delete this->_brain;
}

void Dog::makeSound() const {
    std::cout << "¡Guau, guau!" << std::endl;
}

void Dog::setIdea(int index, const std::string& idea) {
    if (index >= 0 && index < 100) this->_brain->ideas[index] = idea;
}

std::string Dog::getIdea(int index) const {
    if (index >= 0 && index < 100) return this->_brain->ideas[index];
    return "";
}