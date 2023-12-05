#include "ClapTrap.hpp"

ClapTrap::ClapTrap( const std::string& name ): name(name)
{
    hitPoints = 10;
    energyPoints = 10;
    attackDamage = 0;
}

ClapTrap::~ClapTrap()
{
}

ClapTrap::ClapTrap( const ClapTrap& old_obj )
{
    this->attackDamage = old_obj.attackDamage;
    this->energyPoints = old_obj.energyPoints;
    this->hitPoints = old_obj.hitPoints;
    this->name = old_obj.name;
}

void    ClapTrap::operator=( const ClapTrap& old_obj )
{
    this->attackDamage = old_obj.attackDamage;
    this->energyPoints = old_obj.energyPoints;
    this->hitPoints = old_obj.hitPoints;
    this->name = old_obj.name;
}

void 	ClapTrap::attack(const std::string& target)
{
    if (energyPoints > 0)
        std::cout << "ClapTrap " << name <<  " attacks " << target << " , causing " << attackDamage <<  " points of damage!" << std::endl;
    energyPoints--;
}

void 	ClapTrap::takeDamage(unsigned int amount)
{
    hitPoints = hitPoints - amount;
    std::cout << "ClapTrap " << name << " took " << amount << " points of damage." << std::endl;
}

void    ClapTrap::beRepaired(unsigned int amount)
{
    if (energyPoints > 0)
    {
        hitPoints = hitPoints + amount;
        std::cout << "Claptrap " << name << " repairs himself with " << amount << " points costing 1 energy point" << std::endl;
    }
    energyPoints--;
}
