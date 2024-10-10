#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
# include "Contact.hpp"
# include <string>

class PhoneBook {
	Contact contacts[8];
	int	totalContacts;

public:
	PhoneBook();
	~PhoneBook();

	std::string speak();
	void search();
	void addContact();
}; 

#endif
