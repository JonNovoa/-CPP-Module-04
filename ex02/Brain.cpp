#include "Brain.hpp"

Brain::Brain() {
    std::cout << "Brain: Constructor por defecto." << std::endl;
}

Brain::Brain(const Brain& src) {
    std::cout << "Brain: Constructor de copia." << std::endl;
    *this = src;
}

Brain& Brain::operator=(const Brain& src) {
    std::cout << "Brain: Operador de asignación." << std::endl;
    if (this != &src) {
        for (int i = 0; i < 100; i++) {
            this->ideas[i] = src.ideas[i];
        }
    }
    return *this;
}

Brain::~Brain() {
    std::cout << "Brain: Destructor." << std::endl;
}