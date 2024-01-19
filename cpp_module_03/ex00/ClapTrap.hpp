#include <string>
#include <iostream>

class ClapTrap
{
    private:
        std::string	name;
        int			hitPoints;
		int			energyPoints;
		int			attackDamage;
    public:
        ClapTrap( const std::string& name );
        ~ClapTrap();
        ClapTrap( const ClapTrap& old_obj );
        ClapTrap&    operator=( const ClapTrap& old_obj );
		void 	attack(const std::string& target);
		void 	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
        void    displayStats(void);
};