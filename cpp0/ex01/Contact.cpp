/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erigonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 11:27:12 by erigonza          #+#    #+#             */
/*   Updated: 2024/10/11 11:27:14 by erigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include "Contact.hpp"

Contact::Contact() : index(0), firstName(""), lastName(""), nickName(""), phoneNumber(0), secret("") {}

Contact::Contact(int index, std::string firstName, std::string lastName, std::string nickName, int phoneNumber, std::string secret)
	: index(index), firstName(firstName), lastName(lastName), nickName(nickName), phoneNumber(phoneNumber), secret(secret) {}

Contact::~Contact() {}

int Contact::getIndex() const {
	return index;
}

std::string Contact::getFirstName() const {
return firstName;
}
std::string Contact::getLastName() const {
return lastName;
}
std::string Contact::getNickName() const {
return nickName;
}
int Contact::getPhoneNumber() const {
return phoneNumber;
}
std::string Contact::getSecret() const {
return secret;
}
