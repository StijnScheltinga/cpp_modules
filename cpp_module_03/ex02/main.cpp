#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(void)
{
    std::cout << "test 1:" << std::endl;
    FragTrap    a("a");
    a.attack("random");
    a.highFivesGuys();

    std::cout << "test 2:" << std::endl;
    FragTrap    b("b");
    FragTrap    c(b);
    FragTrap    d("d");
    d = b;
    b.attack("random");
    c.attack("random");
    d.attack("random");
}