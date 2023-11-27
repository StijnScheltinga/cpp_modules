#include "Weapon.hpp"
#include <iostream>

Weapon::Weapon( std::string type )
{
    this->type = type;
}

Weapon::~Weapon()
{
}

const std::string& Weapon::getType( void )
{
    const std::string& str = this->type;
    return (str);
}

void Weapon::setType( std::string newType )
{
    type = newType;
}