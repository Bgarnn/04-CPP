#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
	private:
		int					_fixed_point_num_val;
		static const int	_fractional_bits;
	public:
		Fixed(void);
		Fixed(Fixed const &obj);
		Fixed(int const intVal);
		Fixed(float const floatVal);
		~Fixed(void);
		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
		float	toFloat( void ) const;
		int		toInt( void ) const;
		bool	operator>(Fixed const &obj) const;
		bool	operator<(Fixed const &obj) const;
		bool	operator>=(Fixed const &obj) const;
		bool	operator<=(Fixed const &obj) const;
		bool	operator==(Fixed const &obj) const;
		bool	operator!=(Fixed const &obj) const;
		float	operator+(Fixed const &obj) const;
		float	operator-(Fixed const &obj) const;
		float	operator*(Fixed const &obj) const;
		float	operator/(Fixed const &obj) const;
		Fixed	&operator=(Fixed const &obj);
		Fixed	&operator++(void);
		Fixed	operator++(int);
		Fixed	&operator--(void);
		Fixed	operator--(int);
		static Fixed		&min(Fixed &fp1, Fixed &fp2);
		static const Fixed	&min(Fixed const &fp1, Fixed const &fp2);
		static Fixed		&max(Fixed &fp1, Fixed &fp2);
		static const Fixed	&max(Fixed const &fp1, Fixed const &fp2);
};

std::ostream &operator<<(std::ostream &ostream, Fixed const &obj);

#endif