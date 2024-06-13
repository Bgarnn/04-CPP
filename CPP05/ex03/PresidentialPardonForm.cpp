#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void): Form("PresidentialPardonForm", 25, 5), _target("Default")
{}

PresidentialPardonForm::PresidentialPardonForm(std::string const &target): Form("PresidentialPardonForm", 25, 5), _target(target)
{}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &instance): Form(instance), _target(instance._target)
{}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
	std::cout << "[PresidentialPardonForm] destroyed" << std::endl;
}

PresidentialPardonForm	&PresidentialPardonForm::operator=(PresidentialPardonForm const &instance)
{
	if (this != &instance)
		this->_target = instance._target;
	return (*this);
}

void	PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if (this->getAFormStatus() == false)
		throw Form::NotbeSigned();
	else if (executor.getGrade() > this->getExecuteGrade())
		throw Form::NotbeExecute();
	std::cout << PINK << this->_target << " has been pardoned by Zaphod Beeblebrox. " << DEFAULT << std::endl;
}