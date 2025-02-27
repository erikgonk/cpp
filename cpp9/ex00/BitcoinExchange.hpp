/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erigonza <erigonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 17:17:44 by erigonza          #+#    #+#             */
/*   Updated: 2025/02/27 18:55:55 by erigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

# include  <stdlib.h> // for system(clear);
# include <iostream>
# include <fstream> // open files 
#include <sstream> // stream

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define BOLD_RED "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[1;33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"

#define BOLD "\x1B[1m"
#define ITAL "\x1B[3m"
#define UNDL "\x1B[4m"

#define B_RED "\x1B[41m"
#define B_GRN "\x1B[42m"
#define B_YLW "\x1B[43m"
#define B_BLU "\x1B[44m"
#define B_MAG "\x1B[45m"
#define B_CYN "\x1B[46m"
#define B_WHI "\x1B[47m"

class BitcoinExchange
{
  public:
	BitcoinExchange(void);
	BitcoinExchange(const BitcoinExchange &other);
	BitcoinExchange &operator=(const BitcoinExchange &other);
	~BitcoinExchange(void);

	void	execute(char const *file);
	class FileClosedException : public std::exception {
		public:
			const char *what() const throw() {
				return "\033[31m       Could not open file!\033[0m";
			}
	};
};

#endif
