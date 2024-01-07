#include "ScavTrap.hpp"

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name)
{
    this->hitPoints = 100;
    this->energyPoints = 50;
    this->attackDamage = 20;
    std::cout << "ScavTrap constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& old_obj) : ClapTrap(old_obj)
{
    std::cout << "ScavTrap copy constructor called" << std::endl;
}

void    ScavTrap::operator=(const ScavTrap& old_obj) : operator=()
{
    
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap deconstructor called" << std::endl;
}