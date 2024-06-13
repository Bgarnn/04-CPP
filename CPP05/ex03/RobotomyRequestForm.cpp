#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void): Form("RobotomyRequestForm", 72, 45), _target("Default")
{}

RobotomyRequestForm::RobotomyRequestForm(std::string const &target): Form("RobotomyRequestForm", 72, 45), _target(target)
{}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &instance): Form(instance), _target(instance._target)
{}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	std::cout << "[RobotomyRequestForm] destroyed" << '\n';
}

RobotomyRequestForm	&RobotomyRequestForm::operator=(RobotomyRequestForm const &instance)
{
	if (this != &instance)
		this->_target = instance._target;
	return (*this);
}

void	RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	if (this->getAFormStatus() == false)
		throw Form::NotbeSigned();
	else if (executor.getGrade() > this->getExecuteGrade())
		throw Form::NotbeExecute();

	static int i;
	std::cout << "Robotomizing...zZz...zZz..." << std::endl;
	if (i % 2 == 0)
		std::cout << BLUE << this->_target << " has been robotomized successfully!\n";
	else
		std::cout << PINK << "Robotomy failed \n\n";
	std::cout << DEFAULT;
	i++;
}
