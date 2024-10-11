/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erigonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 13:19:59 by erigonza          #+#    #+#             */
/*   Updated: 2024/10/11 13:20:00 by erigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
