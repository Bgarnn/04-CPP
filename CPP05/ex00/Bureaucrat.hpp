#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>

#define DEFAULT	"\033[0m"
#define YELLOW	"\033[33m"
#define CYAN	"\033[36m"

class Bureaucrat
{
	private:
		std::string const	_name;
		int					_grade;
	public:
		Bureaucrat(void);
		Bureaucrat(std::string const name, int const grade);
		Bureaucrat(Bureaucrat const &instance);
		~Bureaucrat(void);
		Bureaucrat	&operator=(Bureaucrat const &instance);
		std::string	getName(void) const;
		int			getGrade(void) const;
		void		increment(void);
		void		decrement(void);

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};

std::ostream	&operator<<(std::ostream &output, Bureaucrat const &instance);

#endif