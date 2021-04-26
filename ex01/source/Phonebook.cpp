#include "Phonebook.hpp"
#include <iostream>
#include <iomanip>

Phonebook::Phonebook()
{
}

Phonebook::~Phonebook()
{
}


static std::string get_word(std::string name, int fill)
{
	std::string ret;

	ret = "";
	std::cout << name << ": ";
	std::getline(std::cin, ret);
	if (fill == 1 && ret.length() == 0)
		ret = "n/a";
	return (ret);
}

int	Phonebook::setup(Contact *el)
{
	while(!el->setFirst_name(get_word("First name", 0)));

	while(!el->setLast_name(get_word("Last name", 0)));

	while(!el->setNickname(get_word("Nickname", 1)));

	while(!el->setLogin(get_word("Login", 1)));

	while(!el->setPostal_add(get_word("Address Postal", 1)));

	while(!el->setEmail_add(get_word("Address email", 1)));

	while(!el->setPhone(get_word("Phone number", 0)));

	while(!el->setBirthday_date(get_word("Birthday date(mm/dd/yy)", 0)));

	while(!el->setFavorite_meal(get_word("Favorite meal", 1)));

	while(!el->setUnderwear_color(get_word("Underwear color", 1)));

	while(!el->setDarkest_secret(get_word("Secret", 1)));

	el->set_is_empty(0);
	return (1);
}

Contact *Phonebook::get_empty_contact()
{
	size_t i;

	i = 0;
	while (i < _max)
	{
		if (this->book[i].get_is_empty() == 1)
			return (&this->book[i]);
		i++;
	}
	return(NULL);
}

static void	print_string(std::string str)
{
	std::cout << std::setw(10) << str;
	std::cout << "|";
}

void	Phonebook::search_contact_tab()
{
	size_t i;

	i = 0;
	print_string("index");
	print_string("first name");
	print_string("last name");
	print_string("nickname");
	print_string("login");
	std::cout << std::endl;
	while (i < _max)
	{
		if (this->book[i].get_is_empty() == 0)
		{
			std::cout  << std::setw(10) << i << "|";
			this->book[i].print_names();
		}
		i++;
	}
	size_t c;
	c = 0;
	if (std::cout << "type [index] to print or \'n\' to cancel:" &&  !(std::cin  >> c))
	{
		std::cin.clear();
		while (std::cin.get() != '\n');
		std::cerr << "it's not a valide index" << std::endl;
		return ;
	}
	std::cin.ignore();
	if (c == (size_t)'n')
		return ;
	if (c >= 0 && c < _max && this->book[c].get_is_empty() == 0)
		this->book[c].print_contact();
	else
		std::cerr << "it's not a valide index" << std::endl;
}

void		Phonebook::add_contact_tab()
{
	Contact *ptr;

	ptr = this->get_empty_contact();
	if(ptr)
	{
		this->setup(ptr);
	}
	else
	{
		size_t c;

		c = 0;
		std::cout << "Contact is full type [valide number] to remove " << std::endl;
		while (!(std::cin  >> c))
			std::cin.ignore();
		if (c >= 0 && c < _max)
			this->setup(&this->book[c]);
		std::cin.ignore();
	}
}


static std::string		get_next_instruction()
{
	std::string cmd;

	std::cout << "Phonbook: " << std::endl;
	std::getline(std::cin, cmd);
	return (cmd);
}

int		Phonebook::start_phonebook()
{
	int ret;

	ret = 1;
	while (ret == 1)
	{
		std::string cmd;
		cmd = get_next_instruction();
		if (cmd == "ADD")
		{
			add_contact_tab();
		}
		else if (cmd == "SEARCH")
		{
			this->search_contact_tab();
		}
		else if (cmd == "EXIT")
		{
			ret = 0;
		}	
	}
	return (0);
}

