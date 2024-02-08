#include "Cat.hpp"

Cat::Cat()
{
    std::cout << "Cat constructor called" << std::endl;
    this->type = "Cat";
    this->_Brain = new Brain();
}

Cat::Cat(const Cat& other) : Animal(other)
{
    this->_Brain = other._Brain;
    std::cout << "Cat copy constructor called" << std::endl;
}

Cat& Cat::operator=(const Cat& other)
{
    std::cout << "Cat assignment operator called" << std::endl;
    if (this != &other)
    {
        Animal::operator=(other);
        this->_Brain = other._Brain;
    }
    return (*this);
}

Cat::~Cat()
{
    std::cout << "Cat destructor called" << std::endl;
    delete this->_Brain;
}

void    Cat::makeSound(void) const
{
    std::cout << "Meow!" << std::endl;
}
