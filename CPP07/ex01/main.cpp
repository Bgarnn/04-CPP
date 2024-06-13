#include "iter.hpp"

void plus_one(int const &n) 
{
	std::cout << n + 1 << std::endl;
}

void print(std::string const &s) 
{
	std::cout << s << std::endl;
}

int main(void) 
{
	std::cout << "-----------------[res: 2, 3, 4, 5, 6]----------------\n";
	int array[] = {1, 2, 3, 4, 5};
	::iter(array, 5, plus_one);

	std::cout << "-----------------[res: s1, s2, s3]-----------------\n";
	std::string strings[] = {"s1", "s2", "s3"};
	::iter(strings, 3, print);
}


// class Awesome
// {
//   public:
// 	Awesome( void ) : _n( 42 ) { return; }
// 	int get( void ) const { return this->_n; }
//   private:
// 	int _n;
// };

// std::ostream & operator<<( std::ostream & o, Awesome const & rhs )
// {
//   o << rhs.get();
//   return o;
// }

// template< typename T >
// void print( T const& x )
// {
//   std::cout << x << std::endl;
//   return;
// }

// int main() {
//   int tab[] = { 0, 1, 2, 3, 4 };
//   Awesome tab2[5];

//   iter( tab, 5, print<const int> );
//   iter( tab2, 5, print<Awesome> );

//   return 0;
// }
