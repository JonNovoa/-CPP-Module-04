#include "Dog.hpp"
#include "Cat.hpp"

int main() {
    std::cout << "=== 1. INTENTAR INSTANCIAR AANIMAL ===" << std::endl;
    // Si descomentas la línea de abajo, el código NO DEBE COMPILAR.
    // Esa es la prueba de que el ejercicio está bien hecho.
    // AAnimal* prueba = new AAnimal(); 

    std::cout << "Descomenta la línea en main.cpp si quieres comprobar que el compilador lo bloquea." << std::endl;

    std::cout << "\n=== 2. CREANDO POLIMORFISMO VALIDO ===" << std::endl;
    const AAnimal* i = new Cat();
    const AAnimal* j = new Dog();

    std::cout << "\n=== 3. COMPROBANDO SONIDOS ===" << std::endl;
    std::cout << i->getType() << " dice: ";
    i->makeSound();
    std::cout << j->getType() << " dice: ";
    j->makeSound();

    std::cout << "\n=== 4. LIBERANDO MEMORIA ===" << std::endl;
    delete i;
    delete j;

    return 0;
}