#include "PresidentalPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target) : _target(target), AForm("PresidentialPardonForm", 25, 5)
{
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) : _target(other.getTarget())
{
}

std::string getTarget(void)
{
    return (this->_target);
}