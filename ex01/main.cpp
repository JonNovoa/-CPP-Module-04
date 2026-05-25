#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

static void arrayTest()
{
	std::cout << "----- ARRAY TEST -----" << std::endl;

	const int N = 10;
	Animal* animals[N];

	for (int i = 0; i < N; ++i) {
		if (i < N / 2)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
	}

	for (int i = 0; i < N; ++i)
		delete animals[i];
}

static void deepCopyTest()
{
	std::cout << "----- DEEP COPY TEST -----" << std::endl;

	Dog a;
	a.getBrain()->setIdea(0, "I want a bone");
	Dog b(a);

	std::cout << "a.idea0 = " << a.getBrain()->getIdea(0) << std::endl;
	std::cout << "b.idea0 = " << b.getBrain()->getIdea(0) << std::endl;

	a.getBrain()->setIdea(0, "I want TWO bones");
	std::cout << "After modifying a:" << std::endl;
	std::cout << "a.idea0 = " << a.getBrain()->getIdea(0) << std::endl;
	std::cout << "b.idea0 = " << b.getBrain()->getIdea(0) << std::endl;

	Cat c;
	c.getBrain()->setIdea(1, "Sleep");
	Cat d;
	d = c;
	c.getBrain()->setIdea(1, "Sleep more");

	std::cout << "After assignment + modifying c:" << std::endl;
	std::cout << "c.idea1 = " << c.getBrain()->getIdea(1) << std::endl;
	std::cout << "d.idea1 = " << d.getBrain()->getIdea(1) << std::endl;
}

static void wrongTest()
{
	std::cout << "----- WRONG TEST -----" << std::endl;

	const WrongAnimal* wa = new WrongAnimal();
	const WrongAnimal* wc_as_base = new WrongCat();

	std::cout << wa->getType() << std::endl;
	std::cout << wc_as_base->getType() << std::endl;

	wa->makeSound();
	wc_as_base->makeSound(); // calls WrongAnimal::makeSound (not virtual)

	WrongCat real_wc;
	real_wc.makeSound();

	delete wa;
	delete wc_as_base;
}

int main()
{
	arrayTest();
	deepCopyTest();
	wrongTest();

	// Subject-style basic leak test
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	delete j;
	delete i;

	return 0;
}