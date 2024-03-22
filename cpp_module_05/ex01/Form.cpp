#include "Form.hpp"

Form::Form(std::string name, int gradeToSign, int gradeToExecute) : _name(name), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
    this->_signed = false;
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw gradeTooLowException();
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw gradeTooHighException();
}

Form::Form(const Form& other) : _name(other._name), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute)
{
    this->_signed = false;
}

Form::~Form()
{
}

Form&   Form::operator=(const Form& other)
{
    if (this != &other)
        this->_signed = other._signed;
    return (*this);
}

/*gettters*/
std::string Form::getName(void) const
{
    return (this->_name);
}

bool    Form::getSigned(void) const
{
    return (this->_signed);
}

int Form::getGradeToSign(void) const
{
    return (this->_gradeToSign);
}

int Form::getGradeToExecute(void) const
{
    return (this->_gradeToExecute);
}

const char *Form::gradeTooHighException::what(void) const throw()
{
    return ("form grade to high");
}

const char *Form::gradeTooLowException::what(void) const throw()
{
    return ("form grade to low");
}

void    Form::beSigned(const Bureaucrat& Bureaucrat)
{
    if (Bureaucrat.getGrade() <= this->_gradeToSign)
        this->_signed = true;
    else
        throw Form::gradeTooLowException();
}

std::ostream& operator<<(std::ostream& os, const Form& form)
{
    os << "form name: " << form.getName() << "\n";
    os << "grade to sign: " << form.getGradeToSign() << "\n";
    os << "grade to execute: " << form.getGradeToExecute() << "\n";
    os << "signed: " << form.getSigned() << std::endl;
    return (os);
}
