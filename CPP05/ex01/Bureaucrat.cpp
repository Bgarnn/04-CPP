#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void): _name("Default"), _grade(150)
{
	std::cout << "[" << this->_name << "] created" << std::endl;
}

Bureaucrat::Bureaucrat(std::string const name, int const grade): _name(name)
{
	std::cout << "[" << this->_name << "] created" << std::endl;
	if (grade < 1) 
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	this->_grade = grade;
}

Bureaucrat::Bureaucrat(Bureaucrat const &instance)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = instance;
}

Bureaucrat	&Bureaucrat::operator=(Bureaucrat const &instance)
{
	if (instance._grade < 1) 
		throw Bureaucrat::GradeTooHighException();
	else if (instance._grade > 150)
		throw Bureaucrat::GradeTooLowException();
	if (this != &instance)
	{
		this->_grade = instance._grade;
	}
	return (*this);
}

Bureaucrat::~Bureaucrat(void)
{
	std::cout << "[" << this->_name << "] destroyed" << std::endl;
}


std::string	Bureaucrat::getName(void) const
{
	return (this->_name);
}

int	Bureaucrat::getGrade(void) const
{
	return (this->_grade);
}

void	Bureaucrat::increment(void)
{
	if (_grade - 1 < 1)
		throw Bureaucrat::GradeTooHighException();
	this->_grade--;
}
void	Bureaucrat::decrement(void)
{
	if (_grade + 1 > 150)
		throw Bureaucrat::GradeTooLowException();
	this->_grade++;
}

const char	*Bureaucrat::GradeTooHighException::what() const throw()
{	
	return "Grade Too High";
}

const char	*Bureaucrat::GradeTooLowException::what() const throw()
{	
	return "Grade Too Low";
}

std::ostream	&operator<<(std::ostream &output, Bureaucrat const &instance)
{
	output << YELLOW << instance.getName() <<  ", bureaucrat grade " << instance.getGrade() << "." << DEFAULT <<std::endl;
	return output;
}

void	Bureaucrat::signForm(Form &paper)
{
	try
	{
		paper.beSigned(*this);
		std::cout << GREEN << this->_name << " signed " << paper.getName() << DEFAULT << std::endl ;
	}
	catch (std::exception &e)
	{
		std::cout << RED << this->_name << " couldn't sign " << paper.getName() << " because " << e.what() << "." << DEFAULT << std::endl ;
	}
}
