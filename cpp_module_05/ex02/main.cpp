#include "PresidentalPardonForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

int main()
{
	AForm	*form1 = new PresidentialPardonForm("Remco");
	// PresidentialPardonForm	form1("Remco");
	Bureaucrat				wessel("wessel", 1);

	wessel.signForm(*form1);
	wessel.executeForm(*form1);
}
