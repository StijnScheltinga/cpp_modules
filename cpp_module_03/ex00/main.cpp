#include "ClapTrap.hpp"


void    dead_test(void)
{
    ClapTrap    Jan("Jan");

    Jan.takeDamage(20);
    Jan.attack("Piet");
    Jan.beRepaired(20);
    Jan.takeDamage(20);
}

void    no_energy_test(void)
{
    ClapTrap    Piet("Piet");

    Piet.attack("jan");
    Piet.beRepaired(10);
    Piet.attack("jan");
    Piet.beRepaired(10);
    Piet.attack("jan");

    Piet.displayStats();

    Piet.beRepaired(10);
    Piet.attack("jan");
    Piet.beRepaired(10);
    Piet.attack("jan");
    Piet.beRepaired(10);

    Piet.displayStats();

    Piet.attack("jan");
    Piet.beRepaired(10);
    Piet.takeDamage(60);
}

void ocf_test(void)
{
    ClapTrap    a("A");
    ClapTrap    b(a);
    ClapTrap    c("c");

    c = a;
    std::cout << "a stats are: " << std::endl;
    a.displayStats();
    std::cout << "b stats are: " << std::endl;
    b.displayStats();
    std::cout << "c stats are: " << std::endl;
    c.displayStats();

}

int main(void)
{
    dead_test();
    std::cout << std::endl;
    no_energy_test();
    std::cout << std::endl;
    ocf_test();
}