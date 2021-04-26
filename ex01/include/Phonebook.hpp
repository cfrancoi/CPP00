#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP
#include "Contact.hpp"

class Phonebook
{
private:
	Contact		book[8];
	static const int	_max = 8;
	Contact		*get_empty_contact(void);
	void		search_contact_tab(void);
	void		add_contact_tab(void);
	int			setup(Contact *el);
public:
	Phonebook();
	~Phonebook();
	int			start_phonebook();
};


#endif