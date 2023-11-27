#include "PhoneBook.hpp"
#include <iostream>
#include <string>

int    sort_input(PhoneBook &PhoneBook)
{
    std::string user_input;
    std::cout << "input: " << std::flush;
    if (!std::getline(std::cin, user_input))
        return (1);
    if (user_input == "EXIT")
        return (1);
    else if (user_input == "ADD")
        PhoneBook.add_contact();
    else if (user_input == "SEARCH")
        PhoneBook.search_contact();
    else
        std::cout << "invalid input\n";
    return (0);
}
int main()
{
    PhoneBook   PhoneBook;
    std::cout << "Welcome to my phonebook!\nThe available commands are: ADD, SEARCH and EXIT\n";
    while(1)
        if (sort_input(PhoneBook))
            return (0);
    return (0);
}