#include "Contact.hpp"

Contact::Contact(void)
{}

Contact::~Contact(void)
{}

void	Contact::set_value(std::string input_fn, std::string input_ln, std::string input_nn, std::string input_pn, std::string input_ds)
{
	contact_fn = input_fn;
	contact_ln = input_ln;
	contact_nn = input_nn;
	contact_pn = input_pn;
	contact_ds = input_ds;
}

std::string Contact::get_value(std::string mode)
{
	if(!mode.compare("mode_fn"))
		return (contact_fn);
	else if(!mode.compare("mode_ln"))
		return (contact_ln);
	else if(!mode.compare("mode_nn"))
		return (contact_nn);
	else if(!mode.compare("mode_pn"))
		return (contact_pn);
	else if(!mode.compare("mode_ds"))
		return (contact_ds);
	else
		return (NULL);
}