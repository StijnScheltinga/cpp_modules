#include "ClapTrap.hpp"

int main(void)
{
    ClapTrap random("wessel");
    ClapTrap random2;

    random2 = random;

    for (int i = 0; i < 11; i++)
        random.attack("remco");
    random.beRepaired(4);
    random.takeDamage(5);
}