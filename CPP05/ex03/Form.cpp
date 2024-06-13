
#include "Form.hpp"

Form::Form(void): _name("Default"), _formStatus(false), _signedGrade(150), _executeGrade(0)
{
	std::cout << "[Form: " << this->_name << "] created" << std::endl;
	if (_signedGrade < 1 || _executeGrade < 1) 
		throw Form::GradeTooHighException();
	else if (_signedGrade > 150 || _executeGrade > 150)
		throw Form::GradeTooLowException();
}

Form::Form(std::string const name, int const gradeSigned,int const gradeExecute):_name(name), _formStatus(false), _signedGrade(gradeSigned), _executeGrade(gradeExecute)
{
	std::cout << "[Form: " << this->_name << "] created" << std::endl;
	if (_signedGrade < 1 || _executeGrade < 1)
		throw Form::GradeTooHighException();
	else if (_signedGrade > 150 || _executeGrade > 150)
		throw Form::GradeTooLowException();
}

Form::Form(Form const &instance): _name(instance._name), _formStatus(instance._formStatus),_signedGrade(instance._signedGrade), _executeGrade(instance._executeGrade)
{
	std::cout << "Copy constructor called" << std::endl;
}

Form::~Form(void)
{

	std::cout << "[Form: " << this->_name << "] destroyed" << std::endl;
}

Form	&Form::operator=(Form const &instance)
{	
	if (this != &instance)
		this->_formStatus = instance._formStatus;
	return *this;
}

std::string		Form::getName(void) const
{
	return (this->_name);
}

bool	Form::getAFormStatus(void) const
{
	return (this->_formStatus);
}

int	Form::getSignedGrade(void) const
{
	return (this->_signedGrade);
}


int	Form::getExecuteGrade(void) const
{
	return (this->_executeGrade);
}

void	Form::beSigned(Bureaucrat const &instance)
{
	if (instance.getGrade() > this->_signedGrade)
		throw Form::GradeTooLowException();
	this->_formStatus = true;
}

const char *Form::GradeTooHighException::what() const throw()
{
	return "Grade Too High";
}

const char *Form::GradeTooLowException::what() const throw()
{
	return "Grade Too Low";
}

const char *Form::NotbeSigned::what() const throw()
{
	return "Form not signed";
}

const char *Form::NotbeExecute::what() const throw()
{
	return "Form not execute";
}

std::ostream	&operator<<(std::ostream &output, Form const &instance)
{
	output << "-->[Form] Name            : " << instance.getName() << std::endl;
	output << "           Status          : " << instance.getAFormStatus() << std::endl;
	output << "           Grade to Signed : " << instance.getSignedGrade() << std::endl;
	output << "           Grade to Execute: " << instance.getExecuteGrade() << DEFAULT << std::endl;
	return output;
}