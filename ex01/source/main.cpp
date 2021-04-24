#include "Contact.hpp"
#include <iostream>
#include <iomanip>

static Contact *get_empty_contact(Contact *tab, size_t len)
{
	size_t i;

	i = 0;
	while (i < len)
	{
		if (tab[i].is_empty == 1)
			return (&tab[i]);
		i++;
	}
	return(NULL);
}

static void	print_string(std::string str)
{
	std::cout << std::setw(10) << str;
	std::cout << "|";
}

static void	search_contact_tab(Contact *tab, size_t len)
{
	size_t i;

	i = 0;
	print_string("index");
	print_string("first name");
	print_string("last name");
	print_string("nickname");
	print_string("login");
	std::cout << std::endl;
	while (i < len)
	{
		if (tab[i].is_empty == 0)
		{
			std::cout  << std::setw(10) << i << "|";
			tab[i].print_names();
		}
		i++;
	}

	size_t c;
	std::cout << "type [Contact index] to print" << std::endl;
	std::cin  >> c;
		if (c >= 0 && c < len && tab[c].is_empty == 0)
			tab[c].print_contact();
		else
			std::cout << "it's not a valide index" << std::endl;
}

static std::string		get_next_instruction()
{
	std::string cmd;

	std::cout << "Phonbook: " << std::endl;
	std::cin >> cmd;
	return (cmd);
}

static void		add_contact_tab(Contact *tab, size_t len)
{
	Contact *ptr;

	ptr = get_empty_contact(tab, len);
	if(ptr)
	{
		ptr->setup();
	}
	else
	{
		size_t c;
		std::cout << "Contact is full type [valide number] to remove" << std::endl;
		std::cin  >> c;
		if (c >= 0 && c < len)
			tab[c].setup();
	}
}

static int		start_phonebook()
{
	int ret;
	Contact phonebook[8];

	ret = 1;
	while (ret == 1)
	{
		std::string cmd;
		cmd = get_next_instruction();
		if (cmd == "ADD")
		{
			add_contact_tab(&phonebook[0], 8);
		}
		else if (cmd == "SEARCH")
		{
			search_contact_tab(&phonebook[0], 8);
		}
		else if (cmd == "EXIT")
		{
			ret = 0;
		}	
	}
	return (0);
}

int main()
{
	start_phonebook();
	return (1);
}