#include "Cat.hpp"

Cat::Cat() {
    std::cout << "Cat: Constructor por defecto." << std::endl;
    this->type = "Cat";
    this->_brain = new Brain();
}

Cat::Cat(const Cat& src) : AAnimal(src) {
    std::cout << "Cat: Constructor de copia." << std::endl;
    this->_brain = new Brain(*src._brain); // Copia profunda
}

Cat& Cat::operator=(const Cat& src) {
    std::cout << "Cat: Operador de asignación." << std::endl;
    if (this != &src) {
        this->type = src.type;
        delete this->_brain;
        this->_brain = new Brain(*src._brain); // Copia profunda
    }
    return *this;
}

Cat::~Cat() {
    std::cout << "Cat: Destructor." << std::endl;
    delete this->_brain;
}

void Cat::makeSound() const {
    std::cout << "¡Miau, miau!" << std::endl;
}

void Cat::setIdea(int index, const std::string& idea) {
    if (index >= 0 && index < 100) this->_brain->ideas[index] = idea;
}

std::string Cat::getIdea(int index) const {
    if (index >= 0 && index < 100) return this->_brain->ideas[index];
    return "";
}