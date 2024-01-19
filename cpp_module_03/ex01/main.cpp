#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
    std::cout << "test 1:" << std::endl;
    ScavTrap    a("a");
    a.attack("random");
    a.guardGate();

    std::cout << "test 2:" << std::endl;
    ScavTrap    b("b");
    ScavTrap    c(b);
    ScavTrap    d("d");
    d = b;
    b.attack("random");
    c.attack("random");
    d.attack("random");
    c.beRepaired(10);
}
