#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"

int main(void)
{
    const Animal* a = new Dog();
    const Animal* b = new Cat();
    // const Animal* c = new Animal();
    // Animal d;

    delete a;
    delete b;

    return (0);
}