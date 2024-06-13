#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void): AForm("PresidentialPardonForm", 25, 5), _target("Default")
{}

PresidentialPardonForm::PresidentialPardonForm(std::string const &target): AForm("PresidentialPardonForm", 25, 5), _target(target)
{}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &instance): AForm(instance), _target(instance._target)
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
		throw AForm::NotbeSigned();
	else if (executor.getGrade() > this->getExecuteGrade())
		throw AForm::NotbeExecute();
	std::cout << PINK << this->_target << " has been pardoned by Zaphod Beeblebrox. " << DEFAULT << std::endl;
}