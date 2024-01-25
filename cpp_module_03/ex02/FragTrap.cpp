#include "FragTrap.hpp"

FragTrap::FragTrap(const std::string& name) : ClapTrap(name)
{
    this->hitPoints = 100;
    this->energyPoints = 100;
    this->attackDamage = 30;
    std::cout << "A FragTrap named " << name << " has been created." << std::endl;
}

FragTrap::FragTrap(const FragTrap& old_obj) : ClapTrap(old_obj)
{
    std::cout << "FragTrap copy constructor called" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other)
{
    if (this != &other)
    {
        ClapTrap::operator=(other);
        std::cout << "FragTrap copy assignment operator called." << std::endl;
    }
    return (*this);
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap " << name << " deconstructor called" << std::endl;
}

void    FragTrap::highFivesGuys(void)
{
    std::cout << getClass() << name << " wants to high five!" << std::endl;
}

std::string    FragTrap::getClass(void)
{
    return ("FragTrap ");
}
