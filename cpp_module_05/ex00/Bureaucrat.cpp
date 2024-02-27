#include "Bureaucrat.hpp"

/***constructor***/
Bureaucrat::Bureaucrat(std::string name, unsigned int grade) : _name(name), _grade(grade)
{
}

/***copy constructor***/
Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name), _grade(other._grade)
{
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
	if (this != &other)
		this->_grade = other._grade;
	return *this;
}

Bureaucrat::~Bureaucrat()
{
}

std::string Bureaucrat::getName(void)
{
	return(this->_name);
}

unsigned int Bureaucrat::getGrade(void)
{
	return (this->_grade);
}