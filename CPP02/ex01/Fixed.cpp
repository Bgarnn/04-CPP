#include "Fixed.hpp"

int const Fixed::_fractional_bits = 8;

Fixed::Fixed(void)
{	
	std::cout << "Default constructor called" << std::endl;
	this->_fixed_point_num_val = 0;
}

Fixed::Fixed(Fixed const &obj)
{
	std::cout << "Copy constructor called" << std::endl;
	if (this != &obj)
		*this = obj;
}

Fixed::Fixed(int const intVal)
{
	std::cout << "Int constructor called" << '\n';
	this->_fixed_point_num_val = intVal << this->_fractional_bits;
}

Fixed::Fixed(float const floatVal)
{
	std::cout << "Float constructor called" << '\n';
	this->_fixed_point_num_val = roundf(floatVal * (1 << this->_fractional_bits));
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(Fixed const &obj)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &obj)
		this->_fixed_point_num_val = obj.getRawBits();
	return (*this);
}

int Fixed::getRawBits( void ) const
{
	return (this->_fixed_point_num_val);
}

void Fixed::setRawBits( int const raw )
{
	this->_fixed_point_num_val = raw;
}

float	Fixed::toFloat( void ) const
{
	return ((float)this->_fixed_point_num_val / (1 << this->_fractional_bits)); 
}

int	Fixed::toInt( void ) const
{
	return ((int)(this->_fixed_point_num_val >> this->_fractional_bits));
}

std::ostream &operator<<(std::ostream &ostream, Fixed const &obj)
{
	ostream << obj.toFloat();
	return ostream;
}