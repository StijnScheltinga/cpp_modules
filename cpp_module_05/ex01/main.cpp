#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

int main()
{
    Bureaucrat  Tom = Bureaucrat("Tom", 100);
    Form        permit = Form("A", 110, 50);

    std::cout << Tom << std::endl;
    std::cout << permit << std::endl;
    Tom.signForm(permit);
    std::cout << "\n" << permit << std::endl;

    // Bureaucrat  Tom = Bureaucrat("Tom", 150);
    // Form        permit = Form("A", 110, 50);

    // std::cout << Tom << std::endl;
    // std::cout << permit << std::endl;
    // Tom.signForm(permit);
    // std::cout << "\n" << permit << std::endl;
}
