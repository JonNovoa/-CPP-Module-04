#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main(void)
{
  
    std::cout << "\n===== TEST 1: Virtual Functions (Correct) =====" << std::endl;
    {
        const Animal* j = new Dog();
        const Animal* i = new Cat();

        std::cout << "Dog type: " << j->getType() << std::endl;
        std::cout << "Cat type: " << i->getType() << std::endl;

        i->makeSound();
        j->makeSound();

        delete i;
        delete j;
    }

    std::cout << "\n===== TEST 2: Without Virtual (Wrong) =====" << std::endl;
    {
        const WrongAnimal* wrongMeta = new WrongAnimal();
        const WrongAnimal* wrongCat = new WrongCat();

        std::cout << "WrongCat type: " << wrongCat->getType() << std::endl;

        wrongCat->makeSound();  // ❌ Output: "Generic wrong sound" (WrongAnimal, no virtual)
        wrongMeta->makeSound(); // Output: "Generic wrong sound"

        delete wrongCat;
        delete wrongMeta;
    }

    std::cout << "\n===== TEST 3: Array of Virtual Pointers =====" << std::endl;
    {
        const Animal* animals[2];
        animals[0] = new Dog();
        animals[1] = new Cat();

        std::cout << "Animals sounds:" << std::endl;
        for (int i = 0; i < 2; i++)
        {
            std::cout << animals[i]->getType() << " says: ";
            animals[i]->makeSound();
        }

        delete animals[0];
        delete animals[1];
    }

    std::cout << "\n===== TEST 4: Multiple Dogs and Cats =====" << std::endl;
    {
        const Animal* animals[4];
        animals[0] = new Dog();
        animals[1] = new Cat();
        animals[2] = new Dog();
        animals[3] = new Cat();

        for (int i = 0; i < 4; i++)
        {
            std::cout << animals[i]->getType() << " says: ";
            animals[i]->makeSound();
        }

        for (int i = 0; i < 4; i++)
            delete animals[i];
    }

    std::cout << "\n===== TEST 5: Direct Objects (Not Pointers) =====" << std::endl;
    {
        Dog d;
        Cat c;

        std::cout << "Direct Dog: ";
        d.makeSound();
        
        std::cout << "Direct Cat: ";
        c.makeSound();
    }

    std::cout << "\n===== TEST 6: Destruction Order =====" << std::endl;
    {
        std::cout << "Creating Dog..." << std::endl;
        const Animal* dog = new Dog();
        
        std::cout << "Deleting Dog..." << std::endl;
        delete dog;  // Should call Dog destructor, then Animal destructor
    }

    return (0);
}