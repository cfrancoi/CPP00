#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact {

public:

	Contact(void);
	~ Contact(void);

	void			print_names(void);
	void			print_contact(void);
	std::string 	get_word(std::string name);
	int				get_is_empty();
	int				set_is_empty(int is);

	std::string 	getFirst_name();
	int				setFirst_name(std::string first_name);

	std::string 	getLast_name();
	int				setLast_name(std::string last_name);

	std::string 	getNickname();
	int				setNickname(std::string nickname);

	std::string 	getLogin();
	int				setLogin(std::string login);

	std::string 	getPostal_add();
	int				setPostal_add(std::string postal_add);

	std::string 	getEmail_add();
	int				setEmail_add(std::string email_add);
	int				is_email_add(const std::string email_add);

	std::string 	getPhone();
	int				setPhone(std::string phone);
	int				is_phone(const std::string phone);

	std::string 	getBirthday_date();
	int				setBirthday_date(std::string birthday_date);

	std::string 	getFavorite_meal();
	int				setFavorite_meal(std::string favorite_meal);

	std::string 	getUnderwear_color();
	int				setUnderwear_color(std::string favorite_meal);

	std::string 	getDarkest_secret();
	int				setDarkest_secret(std::string secret);

private:
	std::string _first_name;
	std::string _last_name;
	std::string _nickname;
	std::string _login;
	std::string _postal_add;
	std::string _email_add;
	std::string _phone;
	std::string _birthday_date;
	std::string _favorite_meal;
	std::string _underwear_color;
	std::string _darkest_secret;
	int			_is_empty;
};

#endif