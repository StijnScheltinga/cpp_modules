#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"

int main(void)
{
    const Dog* a = new Dog();
    const Dog* b = new Dog();

    a->makeSound();
    b->makeSound();


    delete a;
    delete b;    

    return (0);
}