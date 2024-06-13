#ifndef AFORM_HPP
# define AFORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {

	private:
		std::string const	_name;
		bool				_formStatus;
		int const			_signedGrade;
		int const			_executeGrade;
	public:
		AForm(void);
		AForm(std::string const name, int const gradeSigned,int const gradeExecute);
		AForm(AForm const &instance);
		virtual ~AForm(void);
		AForm			&operator=(AForm const &instance);
		std::string		getName(void) const;
		bool			getAFormStatus(void) const;
		int				getSignedGrade(void) const;
		int				getExecuteGrade(void) const;
		void			beSigned(Bureaucrat const &instance);
		virtual void	execute(Bureaucrat const & executor) const =0;

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
		class NotbeSigned : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class NotbeExecute : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};

std::ostream	&operator<<(std::ostream &output, AForm const &instance);



#endif