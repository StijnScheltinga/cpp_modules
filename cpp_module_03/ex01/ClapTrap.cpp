#include "ClapTrap.hpp"

ClapTrap::ClapTrap( const std::string& name ): name(name), hitPoints(10), energyPoints(10), attackDamage(0)
{
    std::cout << "A Claptrap named " << name << " has been created." << std::endl;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap destructor " << name << " called" << std::endl;
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
    if (hitPoints <= 0)
        std::cout << getClass() << name << " can't attack he is dead" << std::endl;
    else if (energyPoints > 0)
    {
        std::cout << getClass() << name <<  " attacks " << target << ", causing " << attackDamage <<  " points of damage and costing 1 energy point" << std::endl;
        energyPoints--;
    }
    else
        std::cout << getClass() << name << " has insufficient energy points to attack " << target << std::endl;
}

void 	ClapTrap::takeDamage(unsigned int amount)
{
    if (hitPoints <= 0)
    {
        std::cout << getClass() << name << " can't take damage, he is already dead" << std::endl;
        return;
    }
    hitPoints = hitPoints - amount;
    if (hitPoints > 0)
        std::cout << getClass() << name << " took " << amount << " points of damage. He has " << hitPoints << "HP left." << std::endl;
    else
        std::cout << getClass() << name << " took " << amount << " points of damage. He has died." << std::endl;
}

void    ClapTrap::beRepaired(unsigned int amount)
{
    if (hitPoints <= 0)
        std::cout << getClass() << name << " can't be repaired he is dead" << std::endl;
    else if (energyPoints > 0)
    {
        hitPoints += amount;
        std::cout << getClass() << name << " repairs himself with " << amount << " points costing 1 energy point" << std::endl;
        energyPoints--;
    }
    else
        std::cout << getClass() << name << " has insufficient energy points to be repaired." << std::endl;
}

void    ClapTrap::displayStats(void)
{
    std::cout << getClass() << name << ": hitPoints: " << hitPoints
        << ", energyPoints: " << energyPoints << ", attackDamage: " << attackDamage << std::endl;
}

std::string ClapTrap::getClass(void)
{
    return ("ClapTrap ");
}
