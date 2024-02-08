#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"

void    deepCopyTest(void)
{
    std::cout << "Deep copy test:\n" << std::endl;
    
    // Cat a;
    // Cat b;
    Dog a;
    Dog b;

    a = b;

    a.printThought();
    b.printThought();
}

void    subjectTest(void)
{
    std::cout << "subject test:\n" << std::endl;

    const Animal* j = new Dog();
    const Animal* i = new Cat();

    delete j;
    delete i;
}

int main(void)
{
    deepCopyTest();

    std::cout << std::endl;

    subjectTest();

    std::cout << "\narray test\n" << std::endl;

    int num = 4;
    const Animal* a[num];

    for (int i = 0; i != num; i++)
    {
        if (i % 2 == 0)
            a[i] = new Dog();
        else
            a[i] = new Cat();
        std::cout << std::endl;
    }
    
    for (int i = 0; i != num; i++)
        delete a[i];

    return (0);
}