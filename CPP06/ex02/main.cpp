#include "Base.hpp"

int main(void){

	Base *a = generate();
	Base *b = generate();
	Base *c = generate();
	Base *d = generate();
	Base *e = generate();

	std::cout << "\n(*a) --> ";
	identify(a);
	std::cout << "(&a) --> ";
	identify(*a);
	std::cout << '\n';

	std::cout << "(*b) --> ";
	identify(b);
	std::cout << "(&b) --> ";
	identify(*b);
	std::cout << '\n';

	std::cout << "(*c) --> ";
	identify(c);
	std::cout << "(&c) --> ";
	identify(*c);
	std::cout << '\n';

	std::cout << "(*d) --> ";
	identify(d);
	std::cout << "(&d) --> ";
	identify(*d);
	std::cout << '\n';

	std::cout << "(*e) --> ";
	identify(e);
	std::cout << "(&e) --> ";
	identify(*e);
	std::cout << '\n';

	delete a;
	delete b;
	delete c;
	delete d;
	delete e;

	return (0);
}