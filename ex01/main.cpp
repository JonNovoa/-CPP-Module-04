#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main() {
    std::cout << "=== SUBJECT MANDATORY TEST ===" << std::endl;
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    
    delete j; // should not create a leak
    delete i;

    std::cout << "\n=== CREATING ARRAY OF ANIMALS ===" << std::endl;
    const int arraySize = 4;
    Animal* animals[arraySize];

    for (int idx = 0; idx < arraySize; idx++) {
        if (idx < arraySize / 2)
            animals[idx] = new Dog();
        else
            animals[idx] = new Cat();
    }

    std::cout << "\n=== DELETING ARRAY OF ANIMALS ===" << std::endl;
    for (int idx = 0; idx < arraySize; idx++) {
        delete animals[idx];
    }

    std::cout << "\n=== TESTING DEEP COPY ===" << std::endl;
    Dog originalDog;
    originalDog.setIdea(0, "I want a bone");
    originalDog.setIdea(1, "I want to sleep");

    std::cout << "\nCreating a copy of originalDog..." << std::endl;
    Dog copyDog = originalDog; // Llama al operador de asignación (Copia profunda)

    std::cout << "\nModifying the copy's ideas..." << std::endl;
    copyDog.setIdea(0, "I want to chase a cat");

    std::cout << "\nChecking ideas to prove Deep Copy:" << std::endl;
    std::cout << "Original Dog Idea 0: " << originalDog.getIdea(0) << std::endl;
    std::cout << "Copy Dog Idea 0:     " << copyDog.getIdea(0) << std::endl;

    std::cout << "\n=== CLEANING UP TEMPORARY OBJECTS ===" << std::endl;
    return 0;
}