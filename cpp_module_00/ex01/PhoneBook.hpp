#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include "Contact.hpp"

class PhoneBook
{
private:
    Contact contacts[8];
    int     contact_i;
public:
    PhoneBook();
    ~PhoneBook();
    void    add_contact(void);
    void    search_contact(void);
};

#endif