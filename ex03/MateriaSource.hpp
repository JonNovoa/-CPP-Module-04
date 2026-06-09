#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource {
private:
    AMateria* _templates[4];

public:
    MateriaSource();
    MateriaSource(const MateriaSource& src);
    MateriaSource& operator=(const MateriaSource& src);
    ~MateriaSource();

    virtual void learnMateria(AMateria* m);
    virtual AMateria* createMateria(std::string const & type);
};

#endif