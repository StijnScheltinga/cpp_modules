#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

int main()
{
	Intern	remco;
	AForm	*form = PresidentialPardonForm("remco");

	form = remco.makeForm("robotomy", "Wessel");

}
