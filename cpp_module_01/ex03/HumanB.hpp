#ifndef HUMAN_B_HPP
# define HUMAN_B_HPP

#include "Weapon.hpp"
#include <iostream>

class HumanB
{
    private:
        Weapon *_weapon;
        std::string _name;
    public:
        HumanB( std::string name );
        ~HumanB();
        void setWeapon( Weapon &weapon );
        void attack( void );
};

#endif