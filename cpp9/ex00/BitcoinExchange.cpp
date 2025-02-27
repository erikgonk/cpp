/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erigonza <erigonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 17:17:47 by erigonza          #+#    #+#             */
/*   Updated: 2025/02/27 10:19:45 by erigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(void) {
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) {
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other) {
	if  (this != &copy) {
		this->_type = copy._type;
	}
    return *this;
}

BitcoinExchange::~BitcoinExchange(void) {
}

void BitcoinExchange::execute(char const *fileName) {
	std::ifstream file(fileName);
	if (!file.is_open())
		throw FileClosedException();

	std::string line;
	std::getline(file, line);

	std::cout << line << std::endl;
	file.close();
}

