#include "Span.hpp"

Span::Span(void){}

Span::Span(unsigned int N): _N(N){}

Span::Span(Span const& inst){
	*this = inst;
}

Span &Span::operator=(Span const& inst){
	if (this != &inst)
	{
		this->_container.clear();
		this->_N = inst._N;
		this->_container = inst._container;
	}
	return *this;
}

Span::~Span(void){}

void Span::addNumber(unsigned int newNum){

	try{
		if (this->_container.size() == _N)
			throw std::invalid_argument("Error: Full container");
		else if (std::find(this->_container.begin(), this->_container.end(), newNum) != this->_container.end())
			throw std::invalid_argument("Error: Duplicated number");
		else
			this->_container.push_back(newNum);
		}catch(std::exception &e){
			std::cout << RED << e.what() << '\n' << DEFAULT;
		}
}

void Span::addNumber(std::vector<int>::iterator vector_begin, std::vector<int>::iterator vector_end){

	try{
			if (this->_container.size() == _N)
				throw std::invalid_argument("Error: Full container");
			else if (std::distance(vector_begin, vector_end) + this->_container.size() > _N)
				throw std::invalid_argument("Error: Overflow container");
			for(std::vector<int>::iterator head = vector_begin; head != vector_end; head++){
				if (std::find(this->_container.begin(), this->_container.end(), *head) != this->_container.end())
					throw std::invalid_argument("Error: Duplicated number");
				else
					this->_container.push_back(*head);
			}
		}catch(std::exception &e){
			std::cout << RED << e.what() << '\n' << DEFAULT;
	}
}

unsigned int Span::shortestSpan(void){

	try{
		if (this->_container.size() <= 1)
			throw std::invalid_argument("Error: No_span container");
		std::vector<int>::iterator vector_begin = this->_container.begin();
		std::vector<int>::iterator vector_end = this->_container.end();
		std::vector<int>::iterator num_next = vector_begin + 1;
		unsigned int span_tmp;
		unsigned int span_shortest = UINT_MAX;

		std::sort(vector_begin, vector_end);
		while (num_next != vector_end){
			span_tmp = *num_next - *vector_begin;
			if (span_tmp < span_shortest)
				span_shortest = span_tmp;
			num_next++; 
			vector_begin++;
		}
		return span_shortest;
	}catch(std::exception &e){
		std::cout << RED << e.what() << '\n' << DEFAULT;
	}
	return EXIT_FAILURE;
}

unsigned int Span::longestSpan(void){

	try{
		if (this->_container.size() <= 1)
			throw std::invalid_argument("Error: No_span container");
		std::vector<int>::iterator num_max = std::max_element(this->_container.begin(), this->_container.end());
		std::vector<int>::iterator num_min = std::min_element(this->_container.begin(), this->_container.end());
		return (static_cast<unsigned int>(*num_max - *num_min));
	}catch(std::exception &e){
		std::cout << RED << e.what() << '\n' << DEFAULT;
	}
	return EXIT_FAILURE;
}

std::vector<int>  const& Span::getContainer(void) const{

	return (this->_container);
}

std::ostream &operator<<(std::ostream &output, Span const& inst){

	std::vector<int>::const_iterator it = inst.getContainer().begin();
	output << "Container: [ ";
	while (it != inst.getContainer().end())
	{
		output << *it << " ";
		it++;
	}
	output << "]\n";
	return output;
}