#include "MateriaSource.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

int main() {
    std::cout << "=== TEST SUITE OFICIAL ===" << std::endl;
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

    std::cout << "\n=== TESTS ADICIONALES (Gestión de suelo e inventario) ===" << std::endl;
    // Guardamos la dirección de la materia antes de desequipar para borrarla manualmente del suelo
    AMateria* floor_item = tmp; 
    me->unequip(1); // Desequipamos slot 1 (cure)
    delete floor_item; // Evitamos leak en el suelo

    std::cout << "\n=== DESTRUYENDO OBJETOS ===" << std::endl;
    delete bob;
    delete me;
    delete src;

    return 0;
}