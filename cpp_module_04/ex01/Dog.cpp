#include "Dog.hpp"

Dog::Dog()
{
    std::cout << "Dog constructor called" << std::endl;
    type = "Dog";
    this->_Brain = new Brain();
}

Dog::Dog(const Dog& other) : Animal(other)
{
    this->_Brain = other._Brain;
    std::cout << "Dog copy constructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& other)
{
    std::cout << "Dog assignment operator called" << std::endl;
    if (this != &other)
    {
        Animal::operator=(other);
        *(this->_Brain) = *(other._Brain);
    }
    return (*this);
}

Dog::~Dog()
{
    std::cout << "Dog destructor called" << std::endl;
    delete this->_Brain;
}

void    Dog::makeSound(void) const
{
    std::cout << "Woof!" << std::endl;
}

void    Dog::printThought(void) const
{
    this->_Brain->printThought();
}

