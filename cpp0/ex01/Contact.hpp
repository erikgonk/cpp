/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erigonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 13:19:47 by erigonza          #+#    #+#             */
/*   Updated: 2024/10/11 13:19:48 by erigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP


class Contact {
	
	int index;
	std::string firstName;
	std::string lastName;
	std::string nickName;
	int phoneNumber;
	std::string secret;

public:
	Contact();
	Contact(int index, std::string firstName, std::string lastName, std::string nickName, int phoneNumber, std::string secret);
	~Contact();

	int getIndex() const; 
	std::string getFirstName() const;
	std::string getLastName() const;
	std::string getNickName() const;
	int getPhoneNumber() const;
	std::string getSecret() const;
};

#endif
