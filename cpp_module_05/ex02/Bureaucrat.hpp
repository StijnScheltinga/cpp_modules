#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <iostream>
# include "AForm.hpp"

class AForm;

class Bureaucrat
{
    private:
        const std::string	_name;
		int					_grade;
	public:
		Bureaucrat(std::string name, int grade);
		~Bureaucrat();
		Bureaucrat(const Bureaucrat& other);
		Bureaucrat&		operator=(const Bureaucrat& other);
		std::string		getName(void) const;
		int				getGrade(void) const;
		void			incrementGrade(void);
		void			decrementGrade(void);

		void	signForm(AForm& AForm);

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
		
std::ostream&	operator<<(std::ostream& os, Bureaucrat& Bureau);

#endif