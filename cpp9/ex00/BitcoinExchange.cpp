/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erigonza <erigonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 17:17:47 by erigonza          #+#    #+#             */
/*   Updated: 2025/02/27 19:03:13 by erigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(void) {
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) {
	(void)other;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other) {
	(void)other;
    return *this;
}

BitcoinExchange::~BitcoinExchange(void) {
}

void BitcoinExchange::execute(char const *fileName) {
	std::ifstream file(fileName);
	if (!file.is_open())
		throw FileClosedException();

	std::string line;
	for (int i = -1; i < 5; ++i) {
		std::getline(file, line);
		std::string date;
		std::string sValue;
		std::istringstream ss(line);
		std::getline(ss, date, '|');
		std::getline(ss, sValue, '|');
		std::cout << "date: " << date << "\nline: " << line << '\n';
	}
	file.close();
}

