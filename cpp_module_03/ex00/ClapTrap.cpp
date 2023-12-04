#include "ClapTrap.hpp"

ClapTrap::ClapTrap( const std::string& name ): name(name)
{

}

ClapTrap::~ClapTrap()
{

}

ClapTrap::ClapTrap( const ClapTrap& old_obj )
{

}

void    ClapTrap::operator=( const ClapTrap& old_obj )
{

}

void 	ClapTrap::attack(const std::string& target)
{
    if (energyPoints > 0)
        std::cout << "ClapTrap " << name <<  " attacks " << target << " , causing " << attackDamage <<  "points of damage!" << std::endl;
    energyPoints--;
}

void 	ClapTrap::takeDamage(unsigned int amount)
{
    hitPoints = hitPoints - amount;
}

void    ClapTrap::beRepaired(unsigned int amount)
{
    if (energyPoints > 0)
        hitPoints = hitPoints + amount;
    energyPoints--;
}
