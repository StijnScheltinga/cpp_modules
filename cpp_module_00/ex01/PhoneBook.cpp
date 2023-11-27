#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
    contact_i = 7;
}
PhoneBook::~PhoneBook()
{
}
void    PhoneBook::add_contact(void)
{
    Contact new_contact;

    this->contact_i++;
    this->contact_i = this->contact_i % 8;
    new_contact.create_contact();
    this->contacts[contact_i] = new_contact;
}
void    PhoneBook::search_contact(void)
{
    std::istringstream  intstream;    
    std::string         temp;
    int                 index;

    for (int i = 0; i != 8; i++)
        this->contacts[i].display_contact(i);
    std::cout << "index: ";
    std::getline(std::cin, temp);
    intstream.str(temp);
    if (intstream >> index && index >= 0 && index <= 7)
        this->contacts[index].display_chosen_contact();
    else
        std::cout << "invalid input" << std::endl;
}