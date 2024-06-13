#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void)
{
	ShrubberyCreationForm   form1("HOME");
	RobotomyRequestForm     form2("ROBRO");
	PresidentialPardonForm  form3("KAWIN");
	Bureaucrat              Karn("Karn", 1);

	std::cout << Karn;
	std::cout << "\n------------------[ShrubberyCreationForm]------------------\n\n";
	std::cout << form1;
	Karn.signForm(form1);
	std::cout << form1;
	Karn.executeForm(form1);

	std::cout << "\n------------------[RobotomyRequestForm]------------------\n\n";
	std::cout << form2;
	Karn.signForm(form2);
	std::cout << form2;
	for (int i = 0; i < 4; i++)
		Karn.executeForm(form2);

	std::cout << "\n------------------[PresidentialPardonForm]------------------\n\n";
	std::cout << form3;
	Karn.signForm(form3);
	std::cout << form3;
	Karn.executeForm(form3);
}