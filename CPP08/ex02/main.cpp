#include "MutantStack.hpp"
#include <list>

int main()
{
	std::cout << "\n----------------------------[ MutantStack ]----------------------------\n";
	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);

	// print back of stack
	std::cout << mstack.top() << std::endl; // .top = c.back()

	mstack.pop(); // .pop = c.pop_back()

	// print size of stack
	std::cout << mstack.size() << std::endl;

	mstack.push(3);
	mstack.push(5); 
	mstack.push(737);
	//[...] mstack.push(0);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	
	++it;
	--it;
	while (it != ite) {
		//print all number in stack
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);

	std::cout << "\n-----------------------------[ List ]-------------------------------\n";
	std::list<int> list;

	list.push_back(5);
	list.push_back(17);

	// print back of list
	std::cout << list.back() << std::endl;

	list.pop_back();

	// print size of list
	std::cout << list.size() << std::endl;

	list.push_back(3);
	list.push_back(5); 
	list.push_back(737);
	//[...] list.push_back(0);

	std::list<int>::iterator list_it = list.begin();
	std::list<int>::iterator list_ite = list.end();
	
	++list_it;
	--list_it;
	while (list_it != list_ite) {
		//print all number in list
		std::cout << *list_it << std::endl;
		++list_it;
	}
	return 0;
}