#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# define DEFAULT	"\033[0m"
# define RED		"\033[31m"
# define PINK		"\033[38;2;255;105;180m"


# include <iostream>
# include <string>

class	WrongAnimal
{
	protected:
		std::string	type;
	public:
		WrongAnimal(void);
		WrongAnimal(const std::string &type);
		WrongAnimal(const WrongAnimal &obj);
		~WrongAnimal(void);
		WrongAnimal	&operator=(const WrongAnimal &obj);
		void		makeSound(void) const;
		std::string	getType(void) const;
};

#endif
