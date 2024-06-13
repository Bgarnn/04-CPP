#ifndef SPAN_HPP
# define SPAN_HPP

#define DEFAULT	"\033[0m"
#define RED		"\033[31m"

#include <iostream>
#include <vector>
#include <exception>
#include <algorithm>

class Span{
	private:
			unsigned int		_N;
			std::vector<int>	_container;
	public:
			Span(void);
			Span(unsigned int N);
			Span(Span const& inst);
			Span &operator=(Span const& inst);
			~Span(void);
			
			void addNumber(unsigned int newNum);
			void addNumber(std::vector<int>::iterator vector_begin, std::vector<int>::iterator vector_end);
			std::vector<int>  const& getContainer(void) const;
			unsigned int shortestSpan(void);
			unsigned int longestSpan(void);
};

std::ostream &operator<<(std::ostream &o, Span const& inst);

#endif