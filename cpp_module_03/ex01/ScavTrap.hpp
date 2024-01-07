#ifndef SCAVTRAP_H
# define SCAVTRAP_H

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
    public:
        ScavTrap(const std::string& name);
        ScavTrap(const ScavTrap& old_obj);
        ScavTrap& operator=(const ScavTrap& other);
        ~ScavTrap();

        void    attack(const std::string& target);
        void    guardGate(void);
};

#endif