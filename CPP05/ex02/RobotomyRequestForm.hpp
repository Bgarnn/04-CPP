#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

class Bureaucrat;

class RobotomyRequestForm: public AForm
{
	private:
		std::string	_target;
	public:
		RobotomyRequestForm(void);
		RobotomyRequestForm(std::string const &target);
		RobotomyRequestForm(RobotomyRequestForm const &instance);
		~RobotomyRequestForm(void);
		RobotomyRequestForm	&operator=(RobotomyRequestForm const &instance);
		void	execute(Bureaucrat const & executor) const;
};



#endif