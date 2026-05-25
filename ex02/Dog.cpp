#include "Dog.hpp"

Dog::Dog() : brain(new Brain()) {
	this->type = "Dog";
	std::cout << "[Dog] Default constructor called" << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other), brain(new Brain(*other.brain)) {
	std::cout << "[Dog] Copy constructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& other) {
	std::cout << "[Dog] Copy assignment operator called" << std::endl;
	if (this != &other) {
		Animal::operator=(other);
		*brain = *other.brain; // deep copy
	}
	return *this;
}

Dog::~Dog() {
	std::cout << "[Dog] Destructor called" << std::endl;
	delete brain;
}

void Dog::makeSound() const {
	std::cout << "[Dog] Woof!" << std::endl;
}

Brain* Dog::getBrain() const {
	return brain;
}