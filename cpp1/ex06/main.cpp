/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erigonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 11:35:43 by erigonza          #+#    #+#             */
/*   Updated: 2024/10/18 17:15:43 by erigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HarlFilter.hpp"

int main(int ac, char *av[])
{
	std::cout << "\033[2J\033[H" << std::endl;
	if (ac != 2) {
		std::cout << RED_BACKGROUND << "error: wrong num of args" << std::endl
			<< "Please enter: <flag>" << RESET << std::endl << std::endl;
		return 0;
	}

    Harl harl;
    return (harl.exec(av[1]));
}

Harl::Harl( void )
{
    this->levels[0] = "DEBUG";
    this->levels[1] = "INFO";
    this->levels[2] = "WARNING";
    this->levels[3] = "ERROR";
    this->f[0] = &Harl::debug;
    this->f[1] = &Harl::info;
    this->f[2] = &Harl::warning;
    this->f[3] = &Harl::error;
}

Harl::~Harl( void ) {}

int Harl::exec( std::string message ) {
    int levelIndex = -1;  // Index for the matched log level

    // Determine the log level based on the message
    for (int i = 0; i < 4; ++i) {
        levelIndex = (message == levels[i]) * i + (message != levels[i]) * levelIndex; 
    }

    // Use switch to call the appropriate function and execute subsequent levels
    switch (levelIndex) {
        case 0:
            (this->*f[0])();  // Call debug
            (this->*f[1])();  // Call info
            (this->*f[2])();  // Call info
            (this->*f[3])();  // Call info
			break;
        case 1:
            (this->*f[1])();  // Call info
            (this->*f[2])();  // Call info
            (this->*f[3])();  // Call info
			break;
        case 2:
            (this->*f[2])();  // Call warning
            (this->*f[3])();  // Call info
			break;
        case 3:
            (this->*f[3])();  // Call error
            break;
        default:
            // If no valid level is found, print the default message
            std::cout << RED << BOLD << "[ Probably complaining about insignificant problems ]"
                << RESET << std::endl << std::endl;
            return 1;
    }
/*
	int	flag = 0;
    for ( int i = 0; i < 4; i++) {
            if (!message.compare(levels[i]) || flag == 1) {
				flag = 1;
                (this->*f[i])();
			}
    }
	if (flag == 0) {
		std::cout << RED << BOLD << "[ Probably complaining about insignificant problems ]"
			<< RESET << std::endl << std::endl;
		return 1;
	}*/
	return 0;
}

void Harl::debug( void )
{
    std::cout << BOLD << "[DEBUG] " << RESET << "I love having extra bacon for my 7XL-\
double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void Harl::info( void )
{
    std::cout << "[INFO] " << "I cannot believe adding extra bacon costs\
more money. You didn't put enough bacon in my burger! If you did,\
I wouldn't be asking for more!" << std::endl;
}

void Harl::warning( void )
{
    std::cout << YELLOW << "[WARNING] " << RESET << "I think I deserve to have some extra\
bacon for free. I've been coming for years whereas you started\
working here since last month." << std::endl;
}

void Harl::error( void )
{
    std::cout << RED_BACKGROUND << "[ERROR]" << RESET << " This is unacceptable! I want to speak\
to the manager now." << std::endl << std::endl;
}
