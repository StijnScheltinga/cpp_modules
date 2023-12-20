#include "Zombie.hpp"

Zombie* newZombie( std::string name );

void randomChump( std::string name );

int main(void)
{
    Zombie* ptr = newZombie("remco");
    ptr->announce();
    delete ptr;
    randomChump("wessel");
}
