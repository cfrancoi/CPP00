
#include "Contact.hpp"
#include <iostream>
#include <iomanip>

Contact::Contact(void)
{
	this->_is_empty = 1;
	return ;
}

Contact::~ Contact(void)
{
	return ;
}
void 	static print_err(std::string err)
{
	std::cerr << "\033[0;31m";
	std::cerr << err;
	std::cerr << "\033[0;0m";
	std::cerr << std::endl;
}
int		Contact::get_is_empty()
{
	return (this->_is_empty);
}

int		Contact::set_is_empty(int is)
{
	this->_is_empty = is;
	return (1);
}

static void	print_el(const std::string name, const std::string el)
{
	std::cout.flags(std::ios::left);
	std::cout << std::setw(25);
	std::cout << name << el << std::endl;
}

void		Contact::print_contact(void)
{
	print_el("first name:", this->_first_name);
	print_el("last name:", this->_last_name);
	print_el("nickname:", this->_nickname);
	print_el("login:", this->_login);
	print_el("postal address:", this->_postal_add);
	print_el("favorite meal:", this->_favorite_meal);
	print_el("underwear color:", this->_underwear_color);
	print_el("darkest secret:", this->_darkest_secret);
	print_el("email:", this->_email_add);
	print_el("phone:", this->_phone);
}
static 	void print_one(std::string to_print)
{
	if (to_print.length() > 10)
	{
		to_print = to_print.substr(0, 10);
		to_print[9] = '.';
	}
	std::cout << std::setw(10) << to_print;
}

void	Contact::print_names(void)
{
	print_one(this->_first_name);
	std::cout << "|"; 
	print_one(this->_last_name);
	std::cout << "|"; 
	print_one(this->_login);
	std::cout << "|"; 
	print_one(this->_nickname);
	std::cout << "|";
	std::cout << std::endl;
}

int	Contact::is_phone(const std::string phone)
{
	int i;

	i = 0;
	while (phone[i])
	{
		if (!isdigit(phone[i]))
			return(0);
		i++;
	}
	if (i == 0)
		return(0);
	return(1);
}



int		Contact::is_email_add(const std::string email_add)
{
	int i;
	char check_one;
	char check_two;

	check_one = 0;
	check_two = 0;
	i = 0;
	while (email_add[i] != '\0')
	{
		if (!check_one && email_add[i] == '@')
		{
			if (!isalnum(email_add[i + 1]))
				return(0);
			check_one = 1;
		}
		else if (check_one && !check_two &&  email_add[i] == '.')
		{
			if (!isalnum(email_add[i + 1]))
				return(0);
			check_two = 1;
		}
		else if (!isalnum(email_add[i]))
		{
			return (0);
		}
		i++;
	}
	if (check_two && check_one)
		return (1);
	return(0);
}
/*
	First_name
*/
std::string Contact::getFirst_name()
{
	return this->_first_name;
}

int	Contact::setFirst_name(std::string name)
{
		if (name.length() == 0)
		{
			print_err("First name : empty string");
			return(0);
		}
		this->_first_name = name;
		return (1);
}
/*
	_last_name
*/
std::string Contact::getLast_name()
{
	return this->_last_name;
}

int	Contact::setLast_name(std::string name)
{
		if (name.length() == 0)
		{
			print_err("Last name : empty string");
			return(0);
		}
		this->_last_name = name;
		return (1);
}
/*
	_nickname
*/
std::string Contact::getNickname()
{
	return this->_nickname;
}

int	Contact::setNickname(std::string name)
{
		this->_nickname = name;
		return (1);
}
/*
	_login
*/
std::string Contact::getLogin()
{
	return this->_login;
}

int	Contact::setLogin(std::string name)
{
		this->_login = name;
		return (1);
}

/*
	_postal_add
*/
std::string Contact::getPostal_add()
{
	return this->_postal_add;
}

int	Contact::setPostal_add(std::string name)
{
		this->_postal_add = name;
		return (1);
}
/*
	_Email_add
*/
std::string Contact::getEmail_add()
{
	return this->_email_add;
}

int	Contact::setEmail_add(std::string email_add)
{
	if (email_add.length() == 0)
	{
		print_err("Email : empty string");
		return(0);
	}

	if (is_email_add(email_add))
	{
		this->_email_add = email_add;
	}
	else
	{
		print_err("Email : Bad format sample@for.com");
		return (0);
	}
	return (1);
}
/*
	Phone
*/
std::string Contact::getPhone()
{
	return this->_phone;
}

int	Contact::setPhone(std::string phone)
{
		if (phone.length() == 0)
		{
			print_err("Phone : empty string");
			return(0);
		}
		if (is_phone(phone))
			this->_phone = phone;
		else
		{
			print_err("Phone : Bad format (0-9)");
			return(0);
		}
		return (1);
}
/*
	_birthday_date
*/
std::string Contact::getBirthday_date()
{
	return this->_birthday_date;
}

int	Contact::setBirthday_date(std::string name)
{
	if (name.length() == 0)
	{
		print_err("Birtday : empty string");
		return(0);
	}
	if (name.length() != 8)
	{
		print_err("Birtday : bad format (dd/mm/yy)");
		return(0);
	}
	else
	{
		if ((!(isdigit(name[0]) && isdigit(name[1])))
			|| (name[2] != '/')
			||	(!(isdigit(name[3]) && isdigit(name[4])))
			|| (name[5] != '/')
		 	|| (!(isdigit(name[6]) && isdigit(name[7]))))
		{
			print_err("Birtday : bad format (dd/mm/yy)");
			return(0);
		}
		
	}
	this->_birthday_date = name;
	return (1);
}
/*
	_favorite_meal
*/
std::string Contact::getFavorite_meal()
{
	return this->_favorite_meal;
}

int	Contact::setFavorite_meal(std::string name)
{
		this->_favorite_meal = name;
		return (1);
}
/*
	_underwear_color
*/
std::string Contact::getUnderwear_color()
{
	return this->_underwear_color;
}

int	Contact::setUnderwear_color(std::string name)
{
		this->_underwear_color = name;
		return (1);
}
/*
	_darkest_secret
*/
std::string Contact::getDarkest_secret()
{
	return this->_darkest_secret;
}

int	Contact::setDarkest_secret(std::string name)
{
		this->_darkest_secret = name;
		return (1);
}