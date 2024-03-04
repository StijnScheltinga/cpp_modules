#ifndef FORM_HPP
# define FORM_HPP

#include "Bureaucrat.hpp"

#include <string>
#include <iostream>

class Bureaucrat;

class Form
{
    private:
        const std::string   _name;
        bool                _signed;
        const int           _gradeToSign;
        const int           _gradeToExecute;
    public:
        Form(std::string name, int gradeToSign, int gradeToExecute);
        Form(const Form& other);
        ~Form();
        Form&   operator=(const Form& other);

        std::string getName(void) const;
        bool        getSigned(void) const;
        int         getGradeToSign(void) const;
        int         getGradeToExecute(void) const;

        void    beSigned(const Bureaucrat& bureaucrat);

        class gradeTooHighException : std::exception
        {
            public:
                virtual const char *what(void) const throw();
        };

        class gradeTooLowException : std::exception
        {
            public:
                virtual const char *what(void) const throw();
        };

        
};

std::ostream& operator<<(std::ostream& os, const Form& form);

#endif