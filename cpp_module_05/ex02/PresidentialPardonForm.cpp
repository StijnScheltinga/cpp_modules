#include "PresidentalPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5), _target(target)
{
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) : AForm("PresidentialPardonForm", 25, 5), _target(other.getTarget())
{
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
	if (this != &other)
		this->_target = other.getTarget();
	return (*this);
}

std::string PresidentialPardonForm::getTarget(void) const
{
    return (this->_target);
}

void    PresidentialPardonForm::execute(const Bureaucrat& executor) const
{
	if (executor.getGrade() < 5 && getSigned())
		std::cout << getTarget() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
	else if (executor.getGrade() < 5 && !getSigned())
		std::cout << "Form must be first be signed before it can be executed." << std::endl;
	else
		throw Bureaucrat::GradeTooLowException();
}