#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name );

int main(void)
{
    int N = 5;
    Zombie* arr = zombieHorde(N, "remco");

    for (int i = 0; i != N; i++)
        arr[i].announce();

    delete[] arr;
}
