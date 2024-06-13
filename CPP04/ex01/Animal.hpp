#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# define DEFAULT	"\033[0m"
# define YELLOW		"\033[33m"
# define GREEN		"\033[32m"
# define CYAN		"\033[36m"

# include <iostream>
# include <string>
# include "Brain.hpp"

class	Animal
{
	protected:
		std::string	type;
	public:
		Animal(void);
		Animal(const std::string &animal_type);
		Animal(const Animal &obj);
		Animal			&operator=(const Animal &obj);
		virtual			~Animal(void);
		virtual void	makeSound(void) const;
		std::string		getType(void) const;
};

#endif
