#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>
#include <string>
#include <exception>

# define GREEN		"\033[32m"
# define YELLOW		"\033[33m"
# define DEFAULT	"\033[0m"


template <typename T>
class Array{
	private:
		T				*_elements;
		unsigned int	_n;
	public:
		Array( void ){
			std::cout << GREEN << "Array(void) Constructor called\n" << DEFAULT;
			this->_n = 0;
			this->_elements = new T[ this->_n ];
		}
		Array( unsigned int n ){
			std::cout << GREEN << "Array(size parameter) Constructor called\n" << DEFAULT;
			this->_n = n;
			this->_elements = new T[ this->_n ];
		}
		Array( Array const & inst){
			std::cout << GREEN << "Array(Copy) Constructor called\n" << DEFAULT;
			this->_n = 0;
			this->_elements = NULL;
			*this = inst;
		}
		Array	&operator=( Array const &inst ){
			if (this->_elements != NULL)
				delete [] this->_elements;
			if (inst.getSize() != 0){
				this->_n = inst.getSize();
				this->_elements = new T[ this->_n ];
				for (unsigned int i = 0; i < this->_n; i++)
					this->_elements[i] = inst._elements[i];
			}
			return ( *this );
		}
		~Array( void ){
			std::cout << GREEN << "Array Destructor called\n" << DEFAULT;
			delete [] this->_elements;
		}

		//check that is it out of bound?
		T	&operator[](unsigned int index){
			if (index >= this->getSize() || this->_elements == NULL)
			{
				std::cout << YELLOW << "[ INDEX ]: " << index << '\n' << DEFAULT;	
				throw Array<T>::Indexoutofbound();
			}
			return ( this->_elements[index] );
		}

		T const	&operator[](unsigned int index) const{
			if (index >= this->getSize() || this->_elements == NULL)
			{
				std::cout << YELLOW << "[ INDEX ]: " << index << '\n' << DEFAULT;	
				throw Array<T>::Indexoutofbound();
			}
			return ( this->_elements[index] );
		}
							
		unsigned int	getSize(void) const{
			return ( this->_n );
		}

		class	Indexoutofbound: public std::exception{ 		
			public: 
				virtual const char	*what() const throw();
		};
};

template <typename T>
const char	*Array<T>::Indexoutofbound::what() const throw(){
	return "Error: array index is out of bounds";
}

#endif