#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(void): Form("ShrubberyCreationForm", 145, 137), _target("Default")
{}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target): Form("ShrubberyCreationForm", 145, 137), _target(target)
{}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &instance): Form(instance), _target(instance._target)
{}
ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	std::cout << "[ShrubberyCreationForm] destroyed" << '\n';
}
ShrubberyCreationForm	&ShrubberyCreationForm::operator=(ShrubberyCreationForm const &instance)
{
	if (this != &instance)
		this->_target = instance._target;
	return (*this);
}

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if (this->getAFormStatus() == false)
		throw Form::NotbeSigned();
	else if (executor.getGrade() > this->getExecuteGrade())
		throw Form::NotbeExecute();
		std::ofstream	outfile(this->_target + "_shrubbery");
	outfile << '\n';
	outfile << "       _-_" << '\n';
	outfile << "    /~~   ~~\\" << '\n';
	outfile << " /~~         ~~\\" << '\n';
	outfile << "{               }" << '\n';
	outfile << " \\  _-     -_  /" << '\n';
	outfile << "   ~  \\\\ //  ~" << '\n';
	outfile << "_- -   | | _- _" << '\n';
	outfile << "  _ -  | |   -_" << '\n';
	outfile << "      // \\\\" << "\n\n";
	std::cout << PINK << this->_target + "_shrubbery" << " created" << DEFAULT << std::endl;
}