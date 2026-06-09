#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
    for (int i = 0; i < 4; i++) this->_templates[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource& src) {
    for (int i = 0; i < 4; i++) {
        if (src._templates[i]) this->_templates[i] = src._templates[i]->clone();
        else this->_templates[i] = NULL;
    }
}

MateriaSource& MateriaSource::operator=(const MateriaSource& src) {
    if (this != &src) {
        for (int i = 0; i < 4; i++) {
            if (this->_templates[i]) delete this->_templates[i];
            if (src._templates[i]) this->_templates[i] = src._templates[i]->clone();
            else this->_templates[i] = NULL;
        }
    }
    return *this;
}

MateriaSource::~MateriaSource() {
    for (int i = 0; i < 4; i++) {
        if (this->_templates[i]) delete this->_templates[i];
    }
}

void MateriaSource::learnMateria(AMateria* m) {
    if (!m) return;
    for (int i = 0; i < 4; i++) {
        if (!this->_templates[i]) {
            this->_templates[i] = m; // Guarda la materia directamente para clonar después
            return;
        }
    }
    delete m; // Si la fuente está llena, liberamos para evitar leaks
}

AMateria* MateriaSource::createMateria(std::string const & type) {
    for (int i = 0; i < 4; i++) {
        if (this->_templates[i] && this->_templates[i]->getType() == type) {
            return this->_templates[i]->clone();
        }
    }
    return NULL;
}