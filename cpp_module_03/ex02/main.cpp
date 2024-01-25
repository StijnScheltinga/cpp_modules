#include "FragTrap.hpp"

void    high_five_test()
{
    FragTrap    Jan("jan");
    // ClapTrap    Piet("Piet");

    Jan.highFivesGuys();
    // Piet.guardGate();
}

void    dead_test(void)
{
    FragTrap    Jan("Jan");

    Jan.takeDamage(110);
    Jan.attack("Piet");
    Jan.beRepaired(20);
    Jan.takeDamage(20);
}

void    no_energy_test(void)
{
    FragTrap    Piet("Piet");

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
    FragTrap    a("A");
    std::cout << "a stats are: " << std::endl;
    a.displayStats();
    a.attack("Piet");

    FragTrap    b(a);
    FragTrap    c("c");

    a.attack("Jan");
    c = a;
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
    std::cout << std::endl;
    high_five_test();
}