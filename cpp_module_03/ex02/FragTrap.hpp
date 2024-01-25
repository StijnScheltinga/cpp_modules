#ifndef FRAGTRAP_H
# define FRAGTRAP_H

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
    public:
        FragTrap(const std::string& name);
        FragTrap(const FragTrap& old_obj);
        FragTrap& operator=(const FragTrap& other);
        ~FragTrap();

        void    highFivesGuys(void);
        std::string getClass(void);
};

#endif