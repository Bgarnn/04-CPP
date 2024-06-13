#include "Span.hpp"
// #include <cstdlib>
// #include <ctime> 

int main(void){
	std::cout << "\n---------------------[ Subject test ]---------------------\n";
	Span subject_span = Span(5);
	subject_span.addNumber(6);
	subject_span.addNumber(3);
	subject_span.addNumber(17);
	subject_span.addNumber(9);
	subject_span.addNumber(11);
	std::cout << subject_span;
	std::cout << "-> shortest span: " << subject_span.shortestSpan() << '\n';
	std::cout << "-> longest span: " << subject_span.longestSpan() << '\n';

	std::cout << "\n-----------------[ Duplicated number test ]----------------\n";
	Span dup_span = Span(2);
	dup_span.addNumber(1);
	dup_span.addNumber(1);
	std::cout << dup_span;

	std::cout << "\n--------------------[ Full span testt ]--------------------\n";
	Span full_span = Span(2);
	full_span.addNumber(1);
	full_span.addNumber(2);
	full_span.addNumber(3);
	std::cout << full_span;

	std::cout << "\n--------------[ Fill over range of Span test ]-------------\n";
	//create vector
	std::vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(2);
	std::cout << "Vector: [";
	for(std::vector<int>::iterator it = v.begin(); it != v.end(); it++)   
		std::cout << *it << " ";
	std::cout << "]\n";

	//fill vector into span
	std::cout << "\n>fill vector into span<\n";
	Span vector_span = Span(4);
	vector_span.addNumber(v.begin(), v.end());
	std::cout << vector_span;

	//add more vector into span
	std::cout << "\n>fill MORE vector into span<\n";
	vector_span.addNumber(v.begin(), v.end());

	std::cout << "\n----------------------[ No span test ]---------------------\n";
	Span  no_span = Span(1);
	no_span.addNumber(1);
	no_span.shortestSpan();
	no_span.longestSpan();

	std::cout << "\n------------------[ 10,0000 numbers test ]-----------------\n";
	//create [10,000 numbers] vector
	std::vector<int>  vector;
	std::srand(std::time(0));
	for (int i = 0; i < 10000; i++)
			vector.push_back(i + 1);
	std::vector<int>::iterator vector_begin = vector.begin();
	std::vector<int>::iterator vector_end = vector.end();

	//fill vector into span
	std::cout << ">fill [10,000 numbers] vector into span<\n";
	Span huge_span = Span(10000);
	huge_span.addNumber(vector_begin, vector_end);
	std::cout << "-> shortest span: " << huge_span.shortestSpan() << '\n';
	std::cout << "-> longest span: " << huge_span.longestSpan() << "\n\n";
	return (0);
}