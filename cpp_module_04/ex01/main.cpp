#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"

int main(void)
{
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