#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

int main()
{
	AForm	*form1 = new PresidentialPardonForm("Remco");
	AForm	*form2 = new RobotomyRequestForm("Jan");
	Bureaucrat				wessel("Wessel", 5);

	wessel.signForm(*form1);
	wessel.executeForm(*form1);
	
	wessel.signForm(*form2);
	wessel.executeForm(*form2);

}
