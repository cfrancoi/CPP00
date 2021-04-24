#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact {

public:

	Contact(void);
	~ Contact(void);

	int			setup(void);
	void		print_names(void);
	void		print_contact(void);

	int			set_email_add(const std::string email_add);
	std::string	get_email_add(void);
	int			is_email_add(const std::string email_add);

	int			set_phone(std::string phone);
	std::string	get_phone(void);
	int			is_phone(const std::string email_add);

	std::string first_name;
	std::string last_name;
	std::string nickname;
	std::string login;
	std::string postal_add;
	std::string favorite_meal;
	std::string	underwear_color;
	std::string	darkest_secret;
	int			is_empty;

private:
	std::string email_add;
	std::string phone;

};

#endif