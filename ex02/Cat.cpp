#include "Cat.cpp"
#include "Cat.hpp"

Cat::Cat() {
    this->type = "Cat";
    this->_brain = new Brain();
    std::cout << "Cat constructor called" << std::endl;
}

Cat::Cat(const Cat& other) : AAnimal(other), _brain(NULL) {
    std::cout << "Cat copy constructor called" << std::endl;
    if (other._brain)
        this->_brain = new Brain(*other._brain);
    else
        this->_brain = new Brain();
}

Cat& Cat::operator=(const Cat& other) {
    std::cout << "Cat assignment operator called" << std::endl;
    if (this != &other) {
        AAnimal::operator=(other);
        delete this->_brain;
        if (other._brain)
            this->_brain = new Brain(*other._brain);
        else
            this->_brain = new Brain();
    }
    return *this;
}

Cat::~Cat() {
    delete this->_brain;
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