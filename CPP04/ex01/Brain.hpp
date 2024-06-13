#ifndef BRAIN_HPP
# define BRAIN_HPP

# define DEFAULT	"\033[0m"
# define RED		"\033[31m"
# define PINK		"\033[38;2;255;105;180m"

# include <iostream>

class	Brain
{
	private:
		std::string	ideas[100];
	public:
		Brain(void);
		Brain(const Brain &obj);
		~Brain(void);
		Brain	&operator=(const Brain &obj);
		void	setIdeas(const std::string ideas);
		void	displayIdeas(void) const;
};

#endif
