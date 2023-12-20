#include "ClapTrap.hpp"

int main(void)
{
    ClapTrap random("wessel");

    random.attack("remco");
    random.beRepaired(4);
    random.takeDamage(5);
}