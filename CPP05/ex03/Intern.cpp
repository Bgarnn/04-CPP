#include "Intern.hpp"

Intern::Intern(void)
{
	std::cout << "[Intern] created" << '\n';
}
Intern::Intern(Intern const &instance)
{
	if (this != &instance)
		*this = instance;
}

Intern::~Intern(void)
{
	std::cout << "[Intern] destroyed" << '\n';
}

Intern	&Intern::operator=(Intern const &instance)
{
	(void)instance;
	return *this;
}

Form	*Intern::makeForm(std::string name, std::string target)
{
	std::string formName[] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	std::size_t index = -1;
	Form	*form_ptr = nullptr;
	
	for (std::size_t i=0; i < 3; i++)
	{
		if (name == formName[i])
		{
			index = i;
			break ;
		}
	}

	switch (index)
	{
		case 0:
				form_ptr = new ShrubberyCreationForm(target);
				break;
		case 1:
				form_ptr = new RobotomyRequestForm(target);
				break;
		case 2:
				form_ptr = new RobotomyRequestForm(target);
				break;
		default:
				std::cout << RED << "There is no " << name << " form." << DEFAULT << std::endl;
				return nullptr;
	}
	std::cout << GREEN << "Intern creates " << name << "form" << DEFAULT << std::endl;
	return form_ptr;
}