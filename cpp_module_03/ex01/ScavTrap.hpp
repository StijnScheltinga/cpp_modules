#ifndef SCAVTRAP_H
# define SCAVTRAP_H

#include "ClapTrap.hpp"

class ScavTrap : private ClapTrap
{
    private:

    public:
        ScavTrap(const std::string& name);
        ~ScavTrap();
        ScavTrap(const ScavTrap& old_obj);
        void    operator=(const ScavTrap& old_obj);
};

#endif