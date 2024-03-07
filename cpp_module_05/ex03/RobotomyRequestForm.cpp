#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), _target(target)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : AForm("RobotomyRequestForm", 72, 45), _target(other.getTarget())
{
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
	if (this != &other)
		this->_target = other.getTarget();
	return (*this);
}

std::string RobotomyRequestForm::getTarget(void) const
{
    return (this->_target);
}

void    RobotomyRequestForm::executeForm(void) const
{
	srand(time(NULL));
	int i = rand() % 2;
	std::cout << "brrrrrrr...." << std::endl;
	if (i == 0)
		std::cout << getTarget() << " has been succesfully robotomized" << std::endl;
	else if (i == 1)
		std::cout << getTarget() << " has not been robotomized" << std::endl;

}