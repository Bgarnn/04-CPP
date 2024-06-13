#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>
#include <iomanip>

class Contact
{
	private:
		std::string	contact_fn;
		std::string	contact_ln;
		std::string	contact_nn;
		std::string	contact_pn;
		std::string	contact_ds;
	public:
		Contact(void);
		~Contact(void);
		void		set_value(std::string input_fn, std::string input_ln, std::string input_nn, std::string input_pn, std::string input_ds);
		std::string	get_value(std::string mode);
};

#endif