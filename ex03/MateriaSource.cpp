#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; ++i)
		templates[i] = 0;
}

MateriaSource::MateriaSource(const MateriaSource& other)
{
	for (int i = 0; i < 4; ++i)
		templates[i] = 0;
	copyTemplatesFrom(other);
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other)
{
	if (this != &other)
	{
		clearTemplates();
		copyTemplatesFrom(other);
	}
	return *this;
}

MateriaSource::~MateriaSource()
{
	clearTemplates();
}

void MateriaSource::clearTemplates()
{
	for (int i = 0; i < 4; ++i)
	{
		delete templates[i];
		templates[i] = 0;
	}
}

void MateriaSource::copyTemplatesFrom(const MateriaSource& other)
{
	for (int i = 0; i < 4; ++i)
	{
		if (other.templates[i])
			templates[i] = other.templates[i]->clone();
		else
			templates[i] = 0;
	}
}

void MateriaSource::learnMateria(AMateria* m)
{
	if (!m)
		return;
	for (int i = 0; i < 4; ++i)
	{
		if (templates[i] == 0)
		{
			templates[i] = m->clone(); // store a copy
			return;
		}
	}
	// full => do nothing
}

AMateria* MateriaSource::createMateria(std::string const & t)
{
	for (int i = 0; i < 4; ++i)
	{
		if (templates[i] && templates[i]->getType() == t)
			return templates[i]->clone();
	}
	return 0;
}