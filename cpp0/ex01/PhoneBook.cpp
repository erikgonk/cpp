/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erigonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 11:27:28 by erigonza          #+#    #+#             */
/*   Updated: 2024/10/12 14:59:57 by erigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cctype>
#include <sstream>
#include "Phonebook.hpp"
#include "Contact.hpp"

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"

PhoneBook::PhoneBook() : totalContacts(0) {}

PhoneBook::~PhoneBook() {
	std::cout << MAGENTA << "Phonebook: I am being destroyed 😥" << RESET << std::endl;
}

std::string trim(const std::string &str) {
	size_t first = str.find_first_not_of(' ');
	if (first == std::string::npos) return "";
    size_t last = str.find_last_not_of(' ');
    return str.substr(first, (last - first + 1));
}

bool isNumber(const std::string &str) {
    if (str.empty()) return false; 

    for (std::string::const_iterator it = str.begin(); it != str.end(); ++it) {
        if (!std::isdigit(*it)) return false; 
    }

    return true;
}

int	getPhone() {
	int			num;
	std::string input;
	
	while (42) {
		std::cout << "Please enter the contact's phone number.. 📱"  << std::endl; 
		std::getline(std::cin, input);
		if (std::cin.eof()) {
            std::cout << RED << "EOF encountered. Exiting." << RESET << std::endl;
			exit(0);
		}
		if (!isNumber(input) || input.length() > 9) {
        	std::cout << RED << "Please enter a valid phone NUMBER" << RESET << std::endl;
			continue;
		}
		if (isNumber(input)) {
			break;
		}
	}
	num = std::atoi(input.c_str());
	return num;
}

std::string getInput(const std::string &prompt, const std::string &inputField) {
	std::string input;
	while (42) {
		std::cout << prompt << std::endl; 
		std::getline(std::cin, input);
		if (std::cin.eof()) {
            std::cout << RED << "EOF encountered. Exiting." << RESET << std::endl;
			exit(0);
		}
		input = trim(input);
		if (!input.empty()) {
			break;
		}
        std::cout << RED << "Please enter a valid input" << GREEN << inputField << RESET << std::endl;
	}
	return input;
}
	
void PhoneBook::addContact() {
	std::string name, lastName, nickName, secret;
	int	phoneNumber;
    name = getInput("Please enter the contact's name.. ㍻", " name");
    lastName = getInput("Please enter the contact's last name..", " last name");
    nickName = getInput("Please enter the contact's nickname.. 🤗", " nickname");
    phoneNumber = getPhone();
    secret = getInput("Please enter the contact's darkest secret. 👿", " darkest secret");
	contacts[totalContacts % 8] = Contact(totalContacts % 8, name, lastName, nickName, phoneNumber, secret);
	std::cout <<std::endl;
	totalContacts++;
}

std::string formatField(const std::string &field) {
    if (field.length() > 10) {
        return field.substr(0, 9) + ".";
	} else {
		std::stringstream ss;
		ss << std::setw(10) << field;
		return ss.str();
	}
}

std::string intToString(int value) {
    std::ostringstream oss;
    oss << value;
    return oss.str();
}

void PhoneBook::search() {
	if (totalContacts == 0) {
		std::cout << RED << "No Contacts stored 😓,.. nothing to display..." << RESET << std::endl;
		return;
	}
	std::cout << "" << std::endl;	
	std::cout << "**********************************************************************************************" << std::endl;	
	std::cout << "" << std::endl;	

	if (totalContacts < 8) {
		for (int i = 0; i < totalContacts; i++) {
			std::cout << std::setw(10) << "Index: " << formatField(intToString(contacts[i].getIndex())) << " | ";
        	std::cout << std::setw(10) << "Name: " << formatField(contacts[i].getFirstName()) << " |  ";
        	std::cout << std::setw(10) << "Last Name: " << formatField(contacts[i].getLastName()) << " | ";
        	std::cout << std::setw(10) << "Nickname: " << formatField(contacts[i].getNickName()) << std::endl;
		} 
	} else {
		for (int i = 0; i < 8; i++) {
			std::cout << std::setw(10) << "Index: " << formatField(intToString(contacts[i].getIndex())) << " | ";
        	std::cout << std::setw(10) << "Name: " << formatField(contacts[i].getFirstName()) << " |  ";
        	std::cout << std::setw(10) << "Last Name: " << formatField(contacts[i].getLastName()) << " | ";
        	std::cout << std::setw(10) << "Nickname: " << formatField(contacts[i].getNickName()) << std::endl;
		}
	}
	std::cout << std::endl;	
	std::cout << "**********************************************************************************************" << std::endl;	
	std::cout << std::endl;	
	std::cout << "Please enter the contacts index number to display all details " << std::endl;

	int	searched;
	std::cin >> searched;
	while (!std::cin)
		return ;
	std::cin.ignore(4200, '\n');
	int i = 0;
	std::cout << searched << std::endl;	
	while (i < totalContacts)
		i++;
	std::cout << searched << i << std::endl;	
	if (searched > i - 1 || searched >= 8) {
		std::cout << RED << "The contact at index " << searched << " has not been created or is out of bounds" << RESET << std::endl;
		return;
	}
	
	std::cout << "" << std::endl;	
	std::cout << "**********************************************************************************************" << std::endl;	
	std::cout << "" << std::endl;	
	std::cout << "Name:     		" << GREEN << contacts[searched].getFirstName() << RESET << std::endl;
	std::cout << "Lastname: 		" << GREEN << contacts[searched].getLastName() << RESET << std::endl;
	std::cout << "Nickname: 		" << GREEN << contacts[searched].getNickName() << RESET << std::endl;
	std::cout << "Telephone:	 	" << GREEN << contacts[searched].getPhoneNumber() << RESET << std::endl;
	std::cout << "Darkest Secret:		" << GREEN << contacts[searched].getSecret() << RESET << std::endl;
	std::cout << std::endl;	
	std::cout << "**********************************************************************************************" << std::endl;	
	std::cout << std::endl;	
}
