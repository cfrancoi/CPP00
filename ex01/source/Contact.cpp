
#include "Contact.hpp"
#include <iostream>
#include <iomanip>

Contact::Contact(void)
{
	this->is_empty = 1;
	return ;
}

Contact::~ Contact(void)
{
	return ;
}

int	Contact::setup(void)
{
	std::cout << "first name: " << std::endl;
	std::cin >> this->first_name;
	std::cout << "last name: " << std::endl;
	std::cin >> this->last_name;
	std::cout << "nickname: " << std::endl;
	std::cin >> this->nickname;
	std::cout << "login:" << std::endl;
	std::cin >> this->login;
	std::cout << "postal address:" << std::endl;
	std::cin >> this->postal_add;
	std::cout << "favorite meal:" << std::endl;
	std::cin >> this->favorite_meal;
	std::cout << "underwear color:" << std::endl;
	std::cin >> this->underwear_color;
	std::cout << "darkest secret:" << std::endl;
	std::cin >> this->darkest_secret;	
	int ret = 0;
	while (!ret)
	{
		std::string tmp;
		std::cout << "email :" << std::endl;
		std::cin >> tmp;
		ret = this->set_email_add(tmp);
	}
	ret = 0;
	while (!ret)
	{
		std::string tmp;
		std::cout << "phone :" << std::endl;
		std::cin >> tmp;
		ret = this->set_phone(tmp);
	}
	this->is_empty = 0;
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
	print_el("first name:", this->first_name);
	print_el("last name:", this->last_name);
	print_el("nickname:", this->nickname);
	print_el("login:", this->login);
	print_el("postal address:", this->postal_add);
	print_el("favorite meal:", this->favorite_meal);
	print_el("underwear color:", this->underwear_color);
	print_el( "darkest secret:", this->darkest_secret);
	print_el("email:", this->get_email_add());
	print_el("phone:", this->get_phone());
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
	print_one(this->first_name);
	std::cout << "|"; 
	print_one(this->last_name);
	std::cout << "|"; 
	print_one(this->login);
	std::cout << "|"; 
	print_one(this->nickname);
	std::cout << "|";
	std::cout << std::endl;
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

int Contact::set_email_add(const std::string email_add)
{
	if (this->is_email_add(email_add))
	{
		this->email_add = email_add;
		return (1);
	}
	return (0);
}

std::string	Contact::get_email_add(void)
{
	return (this->email_add);
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

std::string 	Contact::get_phone( void )
{
	return (this->phone);
}

int Contact::set_phone(std::string phone)
{
	if (is_phone(phone))
	{
		this->phone = phone;
		return (1);
	}
	return (0);
}

