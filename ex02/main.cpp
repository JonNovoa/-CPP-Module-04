#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main() {
    std::cout << "=== PROVING THAT AANIMAL IS NOT INSTANTIABLE ===" << std::endl;
    // Si descommantas la línea de abajo, el código NO COMPILARÁ.
    // Esto demuestra que hemos cumplido el objetivo del ejercicio.
    // const AAnimal* testAbstract = new AAnimal(); 

    std::cout << "AAnimal cannot be instantiated directly! (Tested via code comment)" << std::endl;

    std::cout << "\n=== WORKING WITH POINTERS TO ABSTRACT CLASS ===" << std::endl;
    // El uso de punteros a la clase abstracta sí está permitido y funciona igual que antes
    const AAnimal* doggy = new Dog();
    const AAnimal* kitty = new Cat();

    std::cout << doggy->getType() << " says: ";
    doggy->makeSound();
    
    std::cout << kitty->getType() << " says: ";
    kitty->makeSound();

    std::cout << "\n=== CLEANING UP ===" << std::endl;
    delete doggy;
    delete kitty;

    return 0;
}