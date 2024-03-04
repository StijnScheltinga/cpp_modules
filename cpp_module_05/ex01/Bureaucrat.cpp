#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade)
{
    if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
    else if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    std::cout << "Bureaucrat " << name << " created" << std::endl;
}

Bureaucrat::~Bureaucrat()
{
}


Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name), _grade(other._grade)
{
    std::cout << "Bureaucrat " << _name << " created" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
    if (this != &other)
        this->_grade = other._grade;
    return (*this);
}


int Bureaucrat::getGrade(void) const
{
    return (this->_grade);
}

std::string Bureaucrat::getName(void) const
{
    return (this->_name);
}

void    Bureaucrat::incrementGrade(void)
{
    this->_grade--;
    if (this->_grade < 1)
        throw Bureaucrat::GradeTooHighException();
}

void    Bureaucrat::decrementGrade(void)
{
    this->_grade++;
    if (this->_grade > 150)
        throw Bureaucrat::GradeTooLowException();
}

void    Bureaucrat::signForm(Form& form)
{
    try
    {
        form.beSigned(*this);
        std::cout << this->getName() << " signed form " << form.getName() << std::endl;
    }
    catch(const Form::gradeTooLowException& e)
    {
        std::cout << this->getName() << " couldn't sign form " << form.getName() << " because: ";
        std::cout << e.what() << std::endl;
    }
}

const char *Bureaucrat::GradeTooHighException::what(void) const throw()
{
    return ("Grade too high");
}

const char *Bureaucrat::GradeTooLowException::what(void) const throw()
{
    return ("Grade too low");
}

std::ostream&	operator<<(std::ostream& os, Bureaucrat& Bureau)
{
    os << Bureau.getName() << ", Bureaucrat grade: " << Bureau.getGrade() << "\n";
    return (os);
}
