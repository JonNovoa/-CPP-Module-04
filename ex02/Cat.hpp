#ifndef CAT_HPP
#define CAT_HPP

#include "AAnimal.hpp"
#include <string>

class Cat : public AAnimal {
    private:
        // _brain, etc.
    public:
        Cat();
        Cat(const Cat& other);
        Cat& operator=(const Cat& other);
        virtual ~Cat();

        void makeSound() const;
        void setIdea(int index, const std::string& idea);
        std::string getIdea(int index) const;
};

#endif