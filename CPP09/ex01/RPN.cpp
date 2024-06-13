#include "RPN.hpp"

RPN::RPN() : _stack(), _res(0) {}

RPN::~RPN() {}

RPN::RPN(const RPN& inst) {
	*this = inst;
} 

RPN& RPN::operator=(const RPN& inst) {
	if (this != &inst) {
		_stack = inst._stack;
		_res = inst._res;
	}
	return *this;
}

void RPN::evaluate(const std::string& argv) {
	if (argv.empty()) {
		std::cout << RED << "Error: empty expression" << std::endl << DEFAULT;
		exit(EXIT_FAILURE);
	}

	std::stringstream stream(argv);
	try {
		std::string token;
		while (stream >> token) {
			int index = findOperator(token); //index = type of operator
			if (index != -1) { //is operator
				if (_stack.size() < 2)
					throw std::invalid_argument("Error: stack must have at least 2 numbers before an operator");
				int operand2 = _stack.top(); //top number = <second number> for operation
				_stack.pop(); //delete from stack
				int operand1 = _stack.top(); //next number = <first number> for operation
				_stack.pop(); //delete from stack
				if (!performOperation(index, operand1, operand2)) //calculate
					throw std::invalid_argument("Error: invalid operator");
				_stack.push(_res);//.push: add an element to the top of the stack
			} else {
				_stack.push(strToInt(validateDigit(token))); 
			}
		}
		if (_stack.size() != 1)
			throw std::invalid_argument("Error: invalid expression");
		std::cout << _stack.top() << std::endl; //print result
	} catch(const std::exception& e) {
		std::cout << RED << e.what() << std::endl << DEFAULT;
	}
}

std::size_t RPN::findOperator(const std::string& token) {
	std::string operators[] = {"+", "-", "*", "/"};
	for (std::size_t i = 0; i < 4; ++i) {
		if (token == operators[i])
			return i;
	}
	return -1;
}

bool RPN::performOperation(int index, int operand1, int operand2) {
	const int results[] = {add(operand1, operand2), subtract(operand1, operand2), multiply(operand1, operand2), divide(operand1, operand2)};
	if (index < 0 || index >= 4)
		return false;
	_res = results[index];
	return true;
}

int RPN::strToInt(const std::string& str) {
	std::stringstream stream(str); 
	int number; 
	stream >> number;
	if (stream.fail()) 
		throw std::invalid_argument("Error: failed to convert to integer");
	return number;
}

std::string RPN::validateDigit(const std::string& token) {
	if (token.empty())
		throw std::invalid_argument("Error: empty input");
	std::size_t i = (token[0] == '+' || token[0] == '-') ? 1 : 0; // if <true> -> point to <token[1]>
	for (; i < token.length(); ++i) {
		if (!std::isdigit(token[i]))
			throw std::invalid_argument("Error: not a valid number");
	}
	return token;
}
