#include "Bureaucrat.hpp"
#include <iostream>

int main()
{
    try
    {
        Bureaucrat  remco("Remco", 150);
        std::cout << remco.getName() << ", bureaucrat grade: " << remco.getGrade() << std::endl;
        remco.decrementGrade();
        std::cout << "this will not be printed" << std::endl;
    }
    catch (const Bureaucrat::GradeTooLowException& e)
    {
        std::cout << e.what() << '\n';
    }
    try
    {
        Bureaucrat piet("Piet", 1);
        std::cout << piet << std::endl;
        piet.incrementGrade();
        std::cout << "this will not be printed" << std::endl;
    }
    catch(const Bureaucrat::GradeTooHighException& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        Bureaucrat Jan("Jan", 200);
    }
    catch(const Bureaucrat::GradeTooLowException& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        Bureaucrat Wessel("Wessel", 0);
    }
    catch(const Bureaucrat::GradeTooHighException& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        Bureaucrat  remco("Remco", 100);
        Bureaucrat  tom(remco);
        Bureaucrat  piet("Piet", 50);

        piet = remco;
        std::cout << remco << std::endl;
        std::cout << tom << std::endl;
        std::cout << piet << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}
