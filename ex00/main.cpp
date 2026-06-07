#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    std::cout << "=== SUBJECT TESTS (CORRECT POLYMORPHISM) ===" << std::endl;
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    
    i->makeSound(); // Will output the cat sound!
    j->makeSound(); // Will output the dog sound!
    meta->makeSound();

    std::cout << "\n=== CLEANING SUBJECT TESTS ===" << std::endl;
    delete meta;
    delete j;
    delete i;

    std::cout << "\n=== WRONG ANIMAL TESTS (NO POLYMORPHISM) ===" << std::endl;
    const WrongAnimal* wrongMeta = new WrongAnimal();
    const WrongAnimal* wrongCat = new WrongCat();

    std::cout << wrongCat->getType() << " " << std::endl;
    
    wrongCat->makeSound(); // WILL NOT output the wrong cat sound! Outputs WrongAnimal sound.
    wrongMeta->makeSound();

    std::cout << "\n=== CLEANING WRONG TESTS ===" << std::endl;
    delete wrongMeta;
    delete wrongCat;

    return 0;
}