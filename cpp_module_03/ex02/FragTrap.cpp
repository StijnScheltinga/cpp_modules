#include "FragTrap.hpp"

FragTrap::FragTrap(const std::string& name) : ClapTrap(name)
{
    this->hitPoints = 100;
    this->energyPoints = 50;
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

void    FragTrap::attack(const std::string& target)
{
    if (energyPoints > 0)
    {
        std::cout << "FragTrap " << name <<  " attacks " << target << " , causing " << attackDamage <<  " points of damage!" << std::endl;
        energyPoints--;
    }
    else
        std::cout << "FragTrap " << name << " has insufficient energy points to attack " << target << std::endl;
}

void    FragTrap::highFivesGuys(void)
{
    std::cout << "Fragtrap " << name << " wants to high five" << std::endl;
}
