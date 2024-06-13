#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook
{
	private:
		Contact		pb_contact_arr[8];
		int			pb_total_index;
		int			pb_max_i;
		void		get_input(std::string promp_msg, std::string *input_str);
		void		print_table(void);
		void		print_detail(void);
		std::string	str_truncate(std::string str);
	public:
		PhoneBook(void);
		~PhoneBook(void);
		void 		do_add(void);
		void 		do_search(void);
};

#endif