#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
    public:
        FragTrap(const std::string& name);
        FragTrap(const FragTrap& old_obj);
        FragTrap& operator=(const FragTrap& other);
        ~FragTrap();

        void    attack(const std::string& target);
        void    highFivesGuys(void);
};

#endif