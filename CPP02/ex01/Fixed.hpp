#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
	private:
		int					_fixed_point_num_val;
		static int const	_fractional_bits;
	public:
		Fixed(void);
		Fixed(Fixed const &obj);
		Fixed(int 	const intVal);
		Fixed(float const floatVal);
		~Fixed(void);
		Fixed	&operator=(Fixed const &obj);
		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
		float	toFloat( void ) const;
		int		toInt( void ) const;
};

std::ostream &operator<<(std::ostream &ostream, Fixed const &obj);

#endif