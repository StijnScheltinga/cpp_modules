#ifndef AFORM_HPP
# define AFORM_HPP

#include "Bureaucrat.hpp"

#include <string>
#include <iostream>

class Bureaucrat;

class AForm
{
    private:
        const std::string   _name;
        bool                _signed;
        const int           _gradeToSign;
        const int           _gradeToExecute;
    public:
        AForm(std::string name, int gradeToSign, int gradeToExecute);
        AForm(const AForm& other);
        virtual ~AForm();
        AForm&   operator=(const AForm& other);

        std::string getName(void) const;
        bool        getSigned(void) const;
        int         getGradeToSign(void) const;
        int         getGradeToExecute(void) const;

        void    beSigned(const Bureaucrat& bureaucrat);

        void    		execute(const Bureaucrat& executor) const;
		virtual void	executeForm(void) const = 0;

        class GradeTooHighException : std::exception
        {
            public:
                virtual const char *what(void) const throw();
        };

        class GradeTooLowException : std::exception
        {
            public:
                virtual const char *what(void) const throw();
        };

        
};

std::ostream& operator<<(std::ostream& os, const AForm& AForm);

#endif