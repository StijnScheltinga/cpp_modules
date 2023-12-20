#ifndef HUMAN_A_HPP
# define HUMAN_A_HPP

#include "Weapon.hpp"
#include <iostream>
#include <string>

class HumanA
{
    private:
        Weapon& weapon;
        std::string name;
    public:
        HumanA( std::string name, Weapon& weapon );
        ~HumanA();
        void attack( void );
};

#endif