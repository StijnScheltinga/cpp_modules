#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

int main()
{
	AForm	*form1 = new PresidentialPardonForm("Remco");
	AForm	*form2 = new RobotomyRequestForm("Jan");
	AForm	*form3 = new ShrubberyCreationForm("Home");

	Bureaucrat				wessel("Wessel", 5);

	wessel.signForm(*form1);
	wessel.executeForm(*form1);
	
	wessel.signForm(*form2);
	wessel.executeForm(*form2);

	wessel.signForm(*form3);
	wessel.executeForm(*form3);

	delete form1;
	delete form2;
	delete form3;
}
