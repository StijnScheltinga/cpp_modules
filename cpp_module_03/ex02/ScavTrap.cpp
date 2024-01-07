#include "ScavTrap.hpp"

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name)
{
    this->hitPoints = 100;
    this->energyPoints = 50;
    this->attackDamage = 20;
    std::cout << "A Scavtrap named " << name << " has been created." << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& old_obj) : ClapTrap(old_obj)
{
    std::cout << "ScavTrap copy constructor called" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
    if (this != &other)
    {
        ClapTrap::operator=(other);
        std::cout << "ScavTrap copy assignment operator called." << std::endl;
    }
    return (*this);
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap " << name << " deconstructor called" << std::endl;
}

void    ScavTrap::attack(const std::string& target)
{
    if (energyPoints > 0)
    {
        std::cout << "ScavTrap " << name <<  " attacks " << target << " , causing " << attackDamage <<  " points of damage!" << std::endl;
        energyPoints--;
    }
    else
        std::cout << "ScavTrap " << name << " has insufficient energy points to attack " << target << std::endl;
}

void    ScavTrap::guardGate(void)
{
    std::cout << "ScavTrap " << name << " is now in gate keeper mode." << std::endl;
}
