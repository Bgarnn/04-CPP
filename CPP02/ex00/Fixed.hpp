#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
	private:
		int					_fixed_point_num_val;
		static int const	_fractional_bits;
	public:
		Fixed(void);
		Fixed(Fixed const &obj);
		~Fixed(void);
		Fixed	&operator=(Fixed const &obj);
		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
};

#endif