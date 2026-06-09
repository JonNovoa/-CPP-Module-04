#include "AMateria.hpp"
#include "ICharacter.hpp"

AMateria::AMateria(std::string const & type) : type(type) {}

AMateria::AMateria(const AMateria& src) : type(src.type) {}

// El enunciado dice que copiar el tipo no tiene sentido en la asignación
AMateria& AMateria::operator=(const AMateria& src) {
    (void)src;
    return *this;
}

AMateria::~AMateria() {}

std::string const & AMateria::getType() const {
    return this->type;
}

void AMateria::use(ICharacter& target) {
    (void)target;
}