#include "ScavTrap.hpp"

void    guard_gate_test()
{
    ScavTrap    Jan("jan");
    // ClapTrap    Piet("Piet");

    Jan.guardGate();
    // Piet.guardGate();
}

void    dead_test(void)
{
    ScavTrap    Jan("Jan");

    Jan.takeDamage(110);
    Jan.attack("Piet");
    Jan.beRepaired(20);
    Jan.takeDamage(20);
}

void    no_energy_test(void)
{
    ScavTrap    Piet("Piet");

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
    ScavTrap    a("A");
    std::cout << "a stats are: " << std::endl;
    a.displayStats();
    a.attack("Piet");

    ScavTrap    b(a);
    ScavTrap    c("c");

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
    guard_gate_test();
}
