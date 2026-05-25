#include "Character.hpp"

Character::Character(std::string const & n) : name(n)
{
	for (int i = 0; i < 4; ++i)
		inventory[i] = 0;
}

Character::Character(const Character& other) : name(other.name)
{
	for (int i = 0; i < 4; ++i)
		inventory[i] = 0;
	copyInventoryFrom(other);
}

Character& Character::operator=(const Character& other)
{
	if (this != &other)
	{
		name = other.name;
		clearInventory();
		copyInventoryFrom(other);
	}
	return *this;
}

Character::~Character()
{
	clearInventory();
}

void Character::clearInventory()
{
	for (int i = 0; i < 4; ++i)
	{
		delete inventory[i];
		inventory[i] = 0;
	}
}

void Character::copyInventoryFrom(const Character& other)
{
	for (int i = 0; i < 4; ++i)
	{
		if (other.inventory[i])
			inventory[i] = other.inventory[i]->clone();
		else
			inventory[i] = 0;
	}
}

std::string const & Character::getName() const
{
	return name;
}

void Character::equip(AMateria* m)
{
	if (!m)
		return;
	for (int i = 0; i < 4; ++i)
	{
		if (inventory[i] == 0)
		{
			inventory[i] = m;
			return;
		}
	}
	// inventory full => do nothing
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx >= 4)
		return;
	// must NOT delete the materia
	inventory[idx] = 0;
}

void Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx >= 4)
		return;
	if (inventory[idx] == 0)
		return;
	inventory[idx]->use(target);
}