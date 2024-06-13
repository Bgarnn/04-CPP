
#include "AForm.hpp"

AForm::AForm(void): _name("Default"), _formStatus(false), _signedGrade(150), _executeGrade(0)
{
	std::cout << "[AForm: " << this->_name << "] created" << std::endl;
	if (_signedGrade < 1 || _executeGrade < 1) 
		throw AForm::GradeTooHighException();
	else if (_signedGrade > 150 || _executeGrade > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm(std::string const name, int const gradeSigned,int const gradeExecute):_name(name), _formStatus(false), _signedGrade(gradeSigned), _executeGrade(gradeExecute)
{
	std::cout << "[AForm: " << this->_name << "] created" << std::endl;
	if (_signedGrade < 1 || _executeGrade < 1)
		throw AForm::GradeTooHighException();
	else if (_signedGrade > 150 || _executeGrade > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm(AForm const &instance): _name(instance._name), _formStatus(instance._formStatus),_signedGrade(instance._signedGrade), _executeGrade(instance._executeGrade)
{
	std::cout << "Copy constructor called" << std::endl;
}

AForm::~AForm(void){

	std::cout << "[AForm: " << this->_name << "] destroyed" << std::endl;
}

AForm	&AForm::operator=(AForm const &instance)
{	
	if (this != &instance)
		this->_formStatus = instance._formStatus;
	return *this;
}

std::string		AForm::getName(void) const
{
	return (this->_name);
}

bool	AForm::getAFormStatus(void) const
{
	return (this->_formStatus);
}

int	AForm::getSignedGrade(void) const
{
	return (this->_signedGrade);
}


int	AForm::getExecuteGrade(void) const
{
	return (this->_executeGrade);
}

void	AForm::beSigned(Bureaucrat const &instance)
{
	if (instance.getGrade() > this->_signedGrade)
		throw AForm::GradeTooLowException();
	this->_formStatus = true;
}

const char	*AForm::GradeTooHighException::what() const throw()
{
	return "Grade Too High";
}

const char	*AForm::GradeTooLowException::what() const throw()
{
	return "Grade Too Low";
}

const char	*AForm::NotbeSigned::what() const throw()
{
	return "AForm not signed";
}

const char	*AForm::NotbeExecute::what() const throw()
{
	return "AForm not execute";
}

std::ostream	&operator<<(std::ostream &output, AForm const &instance)
{
	output << "-->[AForm] Name            : " << instance.getName() << std::endl;
	output << "           Status          : " << instance.getAFormStatus() << std::endl;
	output << "           Grade to Signed : " << instance.getSignedGrade() << std::endl;
	output << "           Grade to Execute: " << instance.getExecuteGrade() << DEFAULT << std::endl;
	return output;
}