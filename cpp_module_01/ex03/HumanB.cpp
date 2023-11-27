#include "HumanB.hpp"

HumanB::HumanB( std::string name ): _name(name)
{
    _weapon = NULL;
}

HumanB::~HumanB()
{
}

void HumanB::attack()
{
    std::string weapontype = _weapon->getType();
    std::cout << _name << " attacks with " << weapontype << std::endl;
}

void HumanB::setWeapon( Weapon &weapon )
{
    _weapon = &weapon;
}
