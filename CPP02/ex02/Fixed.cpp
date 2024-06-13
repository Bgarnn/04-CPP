#include "Fixed.hpp"

int const Fixed::_fractional_bits = 8;

Fixed::Fixed(void)
{
	this->_fixed_point_num_val = 0;
}

Fixed::Fixed(Fixed const &obj)
{
	if (this != &obj)
		*this = obj;
}

Fixed::Fixed(int const intVal)
{
	this->_fixed_point_num_val = intVal << this->_fractional_bits;
}

Fixed::Fixed(float const floatVal)
{
	this->_fixed_point_num_val = roundf(floatVal * (1 << this->_fractional_bits));
}

Fixed::~Fixed(void)
{
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

int Fixed::toInt( void ) const
{
	return ((int)(this->_fixed_point_num_val >> this->_fractional_bits));
}

Fixed &Fixed::operator=(Fixed const &obj)
{
	if (this != &obj)
		this->_fixed_point_num_val = obj.getRawBits();
	return (*this);
}

std::ostream &operator<<(std::ostream &ostream, Fixed const &obj)
{
	ostream << obj.toFloat();
	return ostream;
}

bool	Fixed::operator>(Fixed const &obj) const
{
	return (this->toFloat() > obj.toFloat());
}

bool	Fixed::operator<(Fixed const &obj) const
{
	return (this->toFloat() < obj.toFloat());
}

bool	Fixed::operator>=(Fixed const &obj) const
{
	return (this->toFloat() >= obj.toFloat());
}

bool	Fixed::operator<=(Fixed const &obj) const
{
	return (this->toFloat() <= obj.toFloat());
}

bool	Fixed::operator==(Fixed const &obj) const
{
	return (this->toFloat() == obj.toFloat());
}

bool	Fixed::operator!=(Fixed const &obj) const
{
	return (this->toFloat() != obj.toFloat());
}

float	Fixed::operator+(Fixed const &obj) const
{
	return (this->toFloat() + obj.toFloat());
}

float	Fixed::operator-(Fixed const &obj) const
{
	return (this->toFloat() - obj.toFloat());
}

float	Fixed::operator*(Fixed const &obj) const
{
	return (this->toFloat() * obj.toFloat());
}

float	Fixed::operator/(Fixed const &obj) const
{	
	return (this->toFloat() / obj.toFloat());
}

Fixed	&Fixed::operator++(void)
{	
	// this->_fixed_point_num_val += (1 << this->_fractional_bits);
	this->_fixed_point_num_val += 1;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed tmp = *this;
	// this->_fixed_point_num_val += (1 << this->_fractional_bits);
	this->_fixed_point_num_val += 1;
	return (tmp);
}

Fixed	&Fixed::operator--(void)
{	
	// this->_fixed_point_num_val -= (1 << this->_fractional_bits);
	this->_fixed_point_num_val -= 1;
	return (*this);
}

Fixed	Fixed::operator--(int)
{	
	Fixed tmp = *this;
	// this->_fixed_point_num_val -= (1 << this->_fractional_bits);
	this->_fixed_point_num_val -= 1;
	return (tmp);
}

Fixed	&Fixed::min(Fixed &fp1, Fixed &fp2)
{
	if (fp1 <= fp2)
		return fp1;
	else
		return fp2;
}

Fixed	const &Fixed::min(Fixed const &fp1, Fixed const &fp2)
{
	if (fp1 <= fp2)
		return fp1;
	else
		return fp2;
}

Fixed	&Fixed::max(Fixed &fp1, Fixed &fp2)
{
	if (fp1 >= fp2)
		return fp1;
	else
		return fp2;
}

Fixed	const &Fixed::max(Fixed const &fp1, Fixed const &fp2)
{
	if (fp1 >= fp2)
		return fp1;
	else
		return fp2;
}