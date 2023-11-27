#include "Contact.hpp"

Contact::Contact()
{
    this->is_empty = true;
}
Contact::~Contact()
{
}

void    Contact::set_field(std::string *field, std::string text)
{
    std::string temp;

    while (1)
    {
        std::cout << text;
        if (!std::getline(std::cin, temp))
            exit(0);
        if (temp == "\0")
            std::cout << "Contact can't have empty fields" << std::endl;
        else
        {
            *field = temp;
            break;
        }
    }
}

void    Contact::create_contact(void)
{
    set_field(&first_name, "first name: ");
    set_field(&last_name, "last name: ");
    set_field(&nick_name, "nickname: ");
    set_field(&phone_number, "phonenumber: ");
    set_field(&darkest_secret, "darkest secret: ");
    this->is_empty = false;
}
void    Contact::display_contact(int i)
{
    this->index = i;
    if (!this->is_empty)
    {
        std::cout << "|";
        print_contact_info(ft_atoi(this->index));
        print_contact_info(this->first_name);
        print_contact_info(this->last_name);
        print_contact_info(this->nick_name);
        std::cout << std::endl;
    }
}
void    Contact::print_contact_info(std::string text)
{
    int space_n;
    if (text.length() >= 10)
    {
        text.resize(9);
        std::cout << text << ".|";
    }
    else
    {
        space_n = 10 - text.length();
        text.insert(0, space_n, ' ');
        std::cout << text << "|";
    }
}
std::string Contact::ft_atoi(int i)
{
    std::stringstream   convert;
    std::string         argument;

    convert << i;
    argument = convert.str();
    return (argument);
}

void    Contact::display_chosen_contact()
{
    if (!this->is_empty)
    {
        std::cout << this->first_name << std::endl;
        std::cout << this->last_name << std::endl;
        std::cout << this->nick_name << std::endl;
        std::cout << this->phone_number << std::endl;
        std::cout << this->darkest_secret << std::endl;
    }
    else
        std::cout << "incorrect index" << std::endl;
}