/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erigonza <erigonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 17:17:47 by erigonza          #+#    #+#             */
/*   Updated: 2025/02/28 17:36:18 by erigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int ac, char **av) {
	if (ac != 2) {
		std::cout << RED << "Usage: ./RPN \"expression\"" << RESET << std::endl;
            return 1;
	}
	try {
		RPN calculator;
		double result = calculator.evaluateRPN(av[1]);
		std::cout << YELLOW << "Result: " << GREEN << result << RESET << std::endl;
	} catch (std::exception &e) {
		std::cout << RED << "Error: " << e.what() << RESET << std::endl;
		return 1;
	}
	return 0;
}
