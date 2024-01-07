#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : name(""), hitPoints(10), energyPoints(10), attackDamage(0)
{
    std::cout << "An unnamed ClapTrap has been created." << std::endl;
}

ClapTrap::ClapTrap( const std::string& name ): name(name), hitPoints(10), energyPoints(10), attackDamage(0)
{
    std::cout << "A Claptrap named " << name << " has been created." << std::endl;
}

ClapTrap::~ClapTrap()
{
    std::cout << "destructor " << name << " called" << std::endl;
}

ClapTrap::ClapTrap( const ClapTrap& old_obj )
{
    this->attackDamage = old_obj.attackDamage;
    this->energyPoints = old_obj.energyPoints;
    this->hitPoints = old_obj.hitPoints;
    this->name = old_obj.name;
    std::cout << "ClapTrap copy constructor called." << std::endl;
}

ClapTrap&    ClapTrap::operator=( const ClapTrap& old_obj )
{
    if (this != &old_obj)
    {
        this->attackDamage = old_obj.attackDamage;
        this->energyPoints = old_obj.energyPoints;
        this->hitPoints = old_obj.hitPoints;
        this->name = old_obj.name;
    }
    std::cout << "ClapTrap assignment operator called." << std::endl;
    return (*this);
}

void 	ClapTrap::attack(const std::string& target)
{
    if (energyPoints > 0)
    {
        std::cout << "ClapTrap " << name <<  " attacks " << target << " , causing " << attackDamage <<  " points of damage!" << std::endl;
        energyPoints--;
    }
    else
        std::cout << "ClapTrap " << name << " has insufficient energy points to attack " << target << std::endl;
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
        energyPoints--;
        std::cout << "Total energy points: " << energyPoints << std::endl;
    }
    else
        std::cout << "ClapTrap " << name << " has insufficient energy points to be repaired." << std::endl;
}
