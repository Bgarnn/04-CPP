#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	pb_total_index = -1;
	pb_max_i = 0;
}

PhoneBook::~PhoneBook(void)
{
	std::cout << ">> EXIT <<" << '\n';
}

void	PhoneBook::get_input(std::string promp_msg, std::string	*input_str)
{
	if (std::cin.eof())
		return;
	while (1)
	{
		std::cout << promp_msg;
		if(!(std::getline(std::cin, *input_str)))
			break;
		if(input_str->empty())
			std::cout << ">> Empty <<" << '\n';
		else
			return;
	}
	std::cout << '\n';
}

void PhoneBook::do_add(void)
{
	std::string	input_fn, input_ln, input_nn, input_pn, input_ds;

	get_input("Enter first name: ", &input_fn);
	get_input("Enter last name: ", &input_ln);
	get_input("Enter nickname: ", &input_nn);
	get_input("Enter phone number: ", &input_pn);
	get_input("Enter darkest secret: ", &input_ds);
	pb_total_index++;
	pb_contact_arr[pb_total_index % 8].set_value(input_fn, input_ln, input_nn, input_pn, input_ds);
	if (!std::cin.eof())
		std::cout << ">> Contact saved <<" << '\n';
	std::cout << ">> BACK <<" << '\n';
}

std::string	PhoneBook::str_truncate(std::string str)
{
	return (str.length() <= 10 ? str : str.substr(0, 9) + ".");
}

void	PhoneBook::print_table(void)
{
	std::cout << "\n|     Index|First name| Last name|  Nickname|\n";
	if(pb_total_index >= 7)
		pb_max_i = 7;
	else
		pb_max_i = pb_total_index;
	for (int i = 0; i <= pb_max_i; i++)
	{
		std::cout << "|";
		std::cout << std::setfill (' ') << std::setw (10);
		std::cout << i + 1 << "|";
		std::cout << std::setfill (' ') << std::setw (10);
		std::cout << str_truncate(pb_contact_arr[i].get_value("mode_fn")) << "|";
		std::cout << std::setfill (' ') << std::setw (10);
		std::cout << str_truncate(pb_contact_arr[i].get_value("mode_ln")) << "|";
		std::cout << std::setfill (' ') << std::setw (10);
		std::cout << str_truncate(pb_contact_arr[i].get_value("mode_nn")) << "|";
		std::cout << '\n';
	}
	std::cout << '\n';
}

void	PhoneBook::print_detail(void)
{
	std::string	input_str;

	PhoneBook::get_input("Search index: ", &input_str);
	if (std::cin.eof())
	{
		std::cout << ">> BACK <<" << '\n';
		return ;
	}
	int	i = 0;
	while (input_str[i])
	{
		if(std::isalpha(input_str[i]) || input_str[i] == ' ')
		{
			std::cout << ">> Invalid <<" << '\n' << ">> BACK <<" << '\n';
			return ;
		}
		i++;
	}
	i = atoi(input_str.c_str());
	if (i < 1 || i > 8 || i > (pb_max_i + 1))
	{
		std::cout << ">> Invalid <<" << '\n' << ">> BACK <<" << '\n';
		return ;
	}
	std::cout << '\n' << ">> Search <<" << '\n';
	std::cout << "Index: " << i << '\n';
	std::cout << "First name: " << pb_contact_arr[i - 1].get_value("mode_fn") << '\n';
	std::cout << "Last name: " << pb_contact_arr[i - 1].get_value("mode_ln") << '\n';
	std::cout << "Nickname: " << pb_contact_arr[i - 1].get_value("mode_nn") << '\n';
	std::cout << "Phone number: " << pb_contact_arr[i - 1].get_value("mode_pn") << '\n';
	std::cout << "Darkest secret: " << pb_contact_arr[i - 1].get_value("mode_ds") << '\n' ;
	std::cout << ">> BACK <<" << '\n';
}

void	PhoneBook::do_search(void)
{
	if(pb_total_index == -1)
	{
		std::cout << ">> Empty phonebook <<" << '\n';
		return;
	}
	PhoneBook::print_table();
	PhoneBook::print_detail();
}