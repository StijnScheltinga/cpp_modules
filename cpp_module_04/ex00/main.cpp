#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main(void)
{
    std::cout << "Correct Animal testing\n" << std::endl;

    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    std::cout << meta->getType() << " " << std::endl;
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;

    meta->makeSound();
    i->makeSound(); //will output the cat sound!
    j->makeSound();

    delete meta;
    delete j;
    delete i;

    std::cout << std::endl << "wrong animal testing\n" << std::endl;

    const WrongAnimal* wronganimal = new WrongAnimal();
    const WrongAnimal* wrongcat = new WrongCat();

    std::cout << wronganimal->getType() << " " << std::endl;
    std::cout << wrongcat->getType() << " " << std::endl;

    wronganimal->makeSound();
    wrongcat->makeSound();

    delete wronganimal;
    delete wrongcat;

    return (0);
}