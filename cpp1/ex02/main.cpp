/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erigonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 11:06:45 by erigonza          #+#    #+#             */
/*   Updated: 2024/10/15 11:06:47 by erigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main(void) {
	std::string str = "HI THIS IS BRAIN";
	std::string* stringPTR = &str;
	std::string& stringREF = str;
	
	std::cout << "\033[31m" << str << "\033[0m" << std::endl;
	std::cout << "memory str:                       " << &str << std::endl;
	std::cout << "memory address hold by strPTR:    " << stringPTR << std::endl;
	std::cout << "memory address hold by stringREF: " << &stringREF << std::endl;

	std::cout << "value str:                        " << str << std::endl;
	std::cout << "value hold by strPTR:             " << *stringPTR << std::endl;
	std::cout << "value hold by stringREF:          " << stringREF << std::endl;

	return 0;
}
