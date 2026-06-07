#include "Dog.hpp"

Dog::Dog() {
    this->type = "Dog";
    this->_brain = new Brain();
    std::cout << "Dog constructor called" << std::endl;
}

Dog::Dog(const Dog& other) : AAnimal(other), _brain(NULL) {
    std::cout << "Dog copy constructor called" << std::endl;
    if (other._brain)
        this->_brain = new Brain(*other._brain);
    else
        this->_brain = new Brain();
}

Dog& Dog::operator=(const Dog& other) {
    std::cout << "Dog assignment operator called" << std::endl;
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

Dog::~Dog() {
    delete this->_brain;
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