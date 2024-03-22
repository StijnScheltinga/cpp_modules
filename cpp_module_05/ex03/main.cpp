#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

int main()
{
	Bureaucrat	saskia("Saskia", 5);
	Intern		remco;
	AForm		*form1 = remco.makeForm("PresidentialPardon", "Wessel");
	AForm		*form2 = remco.makeForm("random", "Wessel");

	if (form1)
	{
		saskia.signForm(*form1);
		saskia.executeForm(*form1);	
	}
	if (form2)
	{
		saskia.signForm(*form2);
		saskia.executeForm(*form2);	
	}

	delete form1;
	delete form2;
}
