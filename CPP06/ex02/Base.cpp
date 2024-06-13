#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base(void){
	std::cout << "Base destroyed\n";
}

Base *generate(void){
	int randomNumber = std::rand();

	if (randomNumber % 3 == 0)
		return ( new A );
	else if (randomNumber % 3 == 1)
		return ( new B );
	else
		return ( new C );
}

void identify(Base* p){
	if (dynamic_cast< A *>( p ) != NULL)
		std::cout << "the actual type of the object poited to by p: \"A\"\n";
	else if (dynamic_cast< B *>( p ) != NULL)
		std::cout << "the actual type of the object poited to by p: \"B\"\n";
	else if (dynamic_cast< C *>( p ) != NULL)
		std::cout << "the actual type of the object poited to by p: \"C\"\n";
}
//Null ptr will return if cast failed-->if failed: it not that one

void identify(Base& p){
	try{
		A &a = dynamic_cast< A &>( p );
		(void)a;
		std::cout << "the actual type of the object poited to by p: \"A\"" << '\n';
	}
	catch(...) {}

	try{
		B &b = dynamic_cast< B &>( p );
		(void)b;
		std::cout << "the actual type of the object poited to by p: \"B\"" << '\n';
	}
	catch(...){}

	try {
		C &c = dynamic_cast< C &>( p );
		(void)c;
		std::cout << "the actual type of the object poited to by p: \"C\"" << '\n';
	}
	catch(...){}
}
//cast reference fail return bad_cast