#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>
# include <iostream>
# include <sstream>
# include <stdlib.h>

class Contact{
private:
    std::string first_name;
    std::string last_name;
    std::string nick_name;
    std::string phone_number;
    std::string darkest_secret;
    bool        is_empty;
    int         index;
    void        print_contact_info(std::string text);
    std::string ft_atoi(int i);
    void        set_field(std::string *field, std::string text);
public:
    Contact();
    ~Contact();
    void    create_contact(void);
    void    display_contact(int i);
    void    display_chosen_contact(void);
};

#endif
