/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erigonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 11:27:21 by erigonza          #+#    #+#             */
/*   Updated: 2024/10/11 11:27:24 by erigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <limits>
#include <cstdlib>
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

enum	Options {
	ADD,
	SEARCH,
	EXIT,
	WARN,
};

Options stringEnum(const std::string &input) {
	if (input == "ADD") return ADD;
	else if (input == "SEARCH") return SEARCH;
	else if (input == "EXIT") return EXIT;
	else return WARN;
}

std::string getValidUserInput() {
	std::string userInput;

    while (true) {
        std::cout << BLUE << "Please enter your choice: "<< RESET << std::endl;
        std::cout << "Enter ADD for creating a new Contact." << std::endl;
        std::cout << "Enter SEARCH for searching contacts" << std::endl;
        std::cout << "Enter EXIT for closing the phonebook" << std::endl;

		std::getline(std::cin, userInput);

		if (std::cin.eof()) {
			std::cout << RED << "EOF encountered. Exiting." << RESET << std::endl;
            exit(0);
        }
		if (userInput == "\n") {
            std::cout << RED << "Empty input is not valid. Please enter a valid number." << RESET << std::endl;
            continue;
        }
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(4200, '\n');
            std::cout << RED << "Invalid input. Please enter a  valid number .." << RESET << std::endl;
		} else if (userInput != "ADD" && userInput != "SEARCH" && userInput != "EXIT" && userInput != "hidden") {
				std::cout << "\033[2J\033[H" << std::endl; 
				std::cout << RED << "Please enter a valid command: ADD, SEARCH or EXIT" << RESET << std::endl;
				continue;
        } else {
            return userInput;
        }
    }
}

int	main(int argc, char *argv[]) {
	(void)argv;
	if (argc > 1)
	{
		std::cout << RED << "error: args not admited 😡" << RESET << std::endl;
		return 1;
	}
	PhoneBook phony;
	std::cout << "\033[2J\033[H" << std::endl; 
    std::cout << GREEN << "Welcome to the PhoneBook application!" << RESET << std::endl;
	std::string	userInput;
	while (true) {
		userInput = getValidUserInput(); 
		Options input = stringEnum(userInput);
		switch (input) {
			case ADD:
        		phony.addContact();
				break;
			case SEARCH:
				phony.search();
				break;
			case EXIT:
				std::cout << GREEN <<"see you next time.. Goodbye.. 👋" << RESET << std::endl;
				return 0;
			default:
				std::cout << RED << "Please enter a valid option 😡" << RESET << std::endl;
				break;
		}
	}
	return 0;
}
