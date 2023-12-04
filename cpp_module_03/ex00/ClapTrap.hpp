#include <string>
#include <iostream>

class ClapTrap
{
    private:
        std::string	name;
        int			hitPoints = 10;
		int			energyPoints = 10;
		int			attackDamage = 0;
    public:
        ClapTrap( const std::string& name );
        ~ClapTrap();
        ClapTrap( const ClapTrap& old_obj );
        void    operator=( const ClapTrap& old_obj );
		void 	attack(const std::string& target);
		void 	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
};