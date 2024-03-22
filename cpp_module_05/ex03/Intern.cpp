#include "Intern.hpp"

Intern::Intern()
{
	std::cout << "Intern created" << std::endl;
}

Intern::Intern(const Intern& other)
{
	(void)other;
}

Intern::~Intern()
{
}

Intern&	Intern::operator=(const Intern& other)
{
	(void)other;
	return (*this);
}

AForm	*Intern::makeForm(const std::string name, const std::string target)
{
	const std::string	formType[] = {
		"PresidentialPardon",
		"RobotomyRequest",
		"ShrubberyCreation"
	};

	AForm *forms[] = {
		new PresidentialPardonForm(target),
		new	RobotomyRequestForm(target),
		new ShrubberyCreationForm(target)
	};

	for (int i = 0; i < 3; i++)
		if (name == formType[i])
		{
			std::cout << "Intern creates " << formType[i] << std::endl;
			return (forms[i]);
		}
	std::cout << "Intern failed to create a form" << std::endl;
	return NULL;
}