#include "AForm.hpp"

AForm::AForm(std::string name, int gradeToSign, int gradeToExecute) : _name(name), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
    this->_signed = false;
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw AForm::GradeTooLowException();
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw AForm::GradeTooHighException();
}

AForm::AForm(const AForm& other) : _name(other._name), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute)
{
    this->_signed = false;
}

AForm::~AForm()
{

}

AForm&   AForm::operator=(const AForm& other)
{
    if (this != &other)
        this->_signed = other._signed;
    return (*this);
}

/*gettters*/
std::string AForm::getName(void) const
{
    return (this->_name);
}

bool    AForm::getSigned(void) const
{
    return (this->_signed);
}

int AForm::getGradeToSign(void) const
{
    return (this->_gradeToSign);
}

int AForm::getGradeToExecute(void) const
{
    return (this->_gradeToExecute);
}

const char *AForm::GradeTooHighException::what(void) const throw()
{
    return ("AForm grade to high");
}

const char *AForm::GradeTooLowException::what(void) const throw()
{
    return ("AForm grade to low");
}

void    AForm::beSigned(const Bureaucrat& Bureaucrat)
{
    if (Bureaucrat.getGrade() <= this->_gradeToSign)
        this->_signed = true;
    else
        throw Bureaucrat::GradeTooLowException();
}

std::ostream& operator<<(std::ostream& os, const AForm& AForm)
{
    os << "AForm name: " << AForm.getName() << "\n";
    os << "grade to sign: " << AForm.getGradeToSign() << "\n";
    os << "grade to execute: " << AForm.getGradeToExecute() << "\n";
    os << "signed: " << AForm.getSigned() << std::endl;
    return (os);
}
