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

	saskia.signForm(*form1);
	saskia.executeForm(*form1);

	delete form1;
}
