#ifndef FORM_HPP
# define FORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {

	private:
		std::string const	_name;
		bool				_formStatus;
		int const			_signedGrade;
		int const			_executeGrade;
	public:
		Form(void);
		Form(std::string const name, int const gradeSigned,int const gradeExecute);
		Form(Form const &instance);
		~Form(void);
		Form		&operator=(Form const &instance);
		std::string	getName(void) const;
		bool		getFormStatus(void) const;
		int			getSignedGrade(void) const;
		int			getExecuteGrade(void) const;
		void		beSigned(Bureaucrat const &instance);

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

std::ostream	&operator<<(std::ostream &output, Form const &instance);



#endif