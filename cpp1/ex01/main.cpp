/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erigonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 09:58:02 by erigonza          #+#    #+#             */
/*   Updated: 2024/10/14 13:29:14 by erigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <iostream>
#include <cctype> 
#include <stdlib.h>
#include <cstdlib>
#include <string>
#include "Zombie.hpp"

bool	isNum(const std::string &str) {
	for (size_t i = 0; i < str.length(); i++) {
		if (!std::isdigit(str[i])) {
			return false;
		}
	}
	return true;
}

void	help() {
	sleep(1);
	std::cout << std::endl << "                                    HELP, 😱... Zombies  🧟 🧟🧟🧟.... 😨" << std::endl;
	sleep(2);
	std::cout << std::endl << "Dont you worry, van Helsing to rescue..🏃" << std::endl;
	sleep(3);
}

int	main(int argc, char *argv[]) {
    system("clear");
	if (argc != 1 && argc != 3) {
		std::cout << "\nWrong number of inputs" << std::endl;
		return 0;
	} else if (argv[1] && !isNum(argv[1])) {
		std::cout << "\nThe input must be the ./ManyBraiiiiiiinnnzzzZ, a number && a name" << std::endl;
		return 1;
	}
	std::cout << "                         _____" << std::endl;
    std::cout << "                       /      \\ " << std::endl;
    std::cout << "                       | () () |" << std::endl;
    std::cout << "                       |  ^    |" << std::endl;
    std::cout << "                       |  ---  |" << std::endl;
    std::cout << "                       \\______/" << std::endl;
    std::cout << "                     _____|_|_____" << std::endl;
    std::cout << "                   /      | |      \\" << std::endl;
    std::cout << "                  /       | |       \\" << std::endl;
    std::cout << "                 /        | |        \\" << std::endl;
    std::cout << "                /        (   )        \\" << std::endl;
    std::cout << "               /         |_|_|         \\" << std::endl;
    std::cout << "                        /     \\           " << std::endl;
    std::cout << "                       /       \\         " << std::endl;
    std::cout << "                      |         |        " << std::endl;
    std::cout << "                      |         |        " << std::endl;

    std::cout << std::endl << std::endl;

    std::cout << RED;
    std::cout << "   BBBBB    RRRRR    AAAAA   IIIII   N    N   ZZZZZZ  ZZZZZZ " << std::endl;
    std::cout << "   B    B   R    R  A     A    I     NN   N       Z       Z  " << std::endl;
    std::cout << "   BBBBB    RRRRR   AAAAAAA    I     N N  N     Z       Z    " << std::endl;
    std::cout << "   B    B   R   R   A     A    I     N   NN   Z       Z      " << std::endl;
    std::cout << "   BBBBB    R    R  A     A   IIIII  N    N  ZZZZZZ  ZZZZZZZ    OOO   OOO OOO" << std::endl;

    std::cout << RESET;
    std::cout << std::endl;

	if (argc == 1) {
		Zombie *horde = zombieHorde(42, "Bobo");
		for (int i = 0; i < 42; i++) {
			usleep(30000);
			horde[i].announce();
		}
		help();
		delete[] horde;
	} else if (argc == 3) {
		int num = atoi(argv[1]);
		Zombie *horde = zombieHorde(num, argv[2]);
		for (int i = 0; i < num; i++) {
			if (num > 10)
				usleep(30000);
			else if (num <= 10)
				usleep(100000);
			horde[i].announce();
		}
		help();
		delete[] horde;
	}
	return 0;	
}
