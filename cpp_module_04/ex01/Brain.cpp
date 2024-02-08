#include "Brain.hpp"

Brain::Brain()
{
    for (int i = 0; i != 100; i++)
        this->ideas[i] = "random thought";
    std::cout << "Brain constructor called" << std::endl;
}

Brain::~Brain()
{
    std::cout << "Brain destructor called" << std::endl;
}

Brain::Brain(const Brain& other)
{
    for (int i = 0; i != 100; i++)
        this->ideas[i] = "copied" + other.ideas[i];
    std::cout << "Brain copy constructor called" << std::endl;
}

Brain&  Brain::operator=(const Brain& other)
{
    std::cout << "Brain copy assignment operator called" << std::endl;
    if (this != &other)
    {
        for (int i = 0; i != 100; i++)
            this->ideas[i] = "copied" + other.ideas[i];
    }
    return (*this);
}
