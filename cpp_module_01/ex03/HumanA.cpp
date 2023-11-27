#include "HumanA.hpp"

HumanA::HumanA( std::string name, Weapon& weapon ): _weapon(weapon), _name(name)
{
}

HumanA::~HumanA()
{
}

void HumanA::attack()
{
    std::string weapontype = _weapon.getType();
    std::cout << _name << " attacks with their " << weapontype << std::endl;
}