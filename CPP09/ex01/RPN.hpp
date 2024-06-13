#ifndef RPN_HPP
#define RPN_HPP

#define DEFAULT "\033[0m"
#define RED     "\033[31m"

#include <string>
#include <stack>
#include <sstream>
#include <iostream>
#include <stdexcept>
#include <cstdlib>

class RPN {
public:
	RPN();
	~RPN();
	RPN(const RPN& inst);
	RPN& operator=(const RPN& inst);
	void evaluate(const std::string& expression);

private:
	std::stack<int> _stack;
	int 			_res;

	std::plus<int> add;
	std::minus<int> subtract;
	std::multiplies<int> multiply;
	std::divides<int> divide;

	std::size_t findOperator(const std::string& arg);
	std::string validateDigit(const std::string& arg);
	bool performOperation(int index, int x, int y);
	int strToInt(const std::string& str);
};

#endif
