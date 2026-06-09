#include "AAnimal.hpp"

AAnimal::AAnimal() : type("AAnimal") {
    std::cout << "AAnimal: Constructor por defecto." << std::endl;
}

AAnimal::AAnimal(const AAnimal& src) {
    std::cout << "AAnimal: Constructor de copia." << std::endl;
    *this = src;
}

AAnimal& AAnimal::operator=(const AAnimal& src) {
    std::cout << "AAnimal: Operador de asignación." << std::endl;
    if (this != &src) {
        this->type = src.type;
    }
    return *this;
}

AAnimal::~AAnimal() {
    std::cout << "AAnimal: Destructor." << std::endl;
}

std::string AAnimal::getType() const {
    return this->type;
}