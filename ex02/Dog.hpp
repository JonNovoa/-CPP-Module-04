#ifndef DOG_HPP
#define DOG_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class Dog : public AAnimal {
private:
    Brain* _brain;

public:
    Dog();
    Dog(const Dog& src);
    Dog& operator=(const Dog& src);
    virtual ~Dog();

    virtual void makeSound() const;
    void setIdea(int index, const std::string& idea);
    std::string getIdea(int index) const;
};

#endif