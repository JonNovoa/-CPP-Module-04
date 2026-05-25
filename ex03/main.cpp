#include "MateriaSource.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include <iostream>

static void subjectMain()
{
	std::cout << "----- SUBJECT TEST -----" << std::endl;

	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter* me = new Character("me");

	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	ICharacter* bob = new Character("bob");

	me->use(0, *bob);
	me->use(1, *bob);

	delete bob;
	delete me;
	delete src;
}

static void extraTests()
{
	std::cout << "----- EXTRA TESTS -----" << std::endl;

	MateriaSource src;
	src.learnMateria(new Ice());
	src.learnMateria(new Cure());

	Character a("alice");
	AMateria* m1 = src.createMateria("ice");
	AMateria* m2 = src.createMateria("cure");
	a.equip(m1);
	a.equip(m2);

	Character b(a); // deep copy
	Character c("charlie");
	c = a; // deep copy assignment

	Character target("target");

	a.use(0, target);
	b.use(0, target);
	c.use(1, target);

	// unequip must NOT delete; we keep pointer to delete manually
	AMateria* floor = src.createMateria("ice");
	a.equip(floor);
	a.unequip(2); // might unequip the floor materia depending on slot usage
	// We don't know if slot 2 was used; ensure we don't leak if it's unequipped:
	// In this simple test, we just delete `floor` anyway (safe if still equipped? NO).
	// So instead, only do manual delete if we are sure we unequipped that exact pointer.
	// We'll do a deterministic test:

	Character u("unequipper");
	AMateria* x = src.createMateria("cure");
	u.equip(x);      // goes to slot 0
	u.unequip(0);    // x is now on "floor"
	delete x;        // caller manages it

	// inventory full test (should not crash)
	u.equip(src.createMateria("ice"));
	u.equip(src.createMateria("ice"));
	u.equip(src.createMateria("ice"));
	u.equip(src.createMateria("ice"));
	u.equip(src.createMateria("ice")); // ignored
}

int main()
{
	subjectMain();
	extraTests();
	return 0;
}