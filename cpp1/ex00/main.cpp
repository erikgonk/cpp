/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erigonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 09:58:02 by erigonza          #+#    #+#             */
/*   Updated: 2024/10/14 12:00:15 by erigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <iostream>
#include "Zombie.hpp"

int	main() {
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

	Zombie *boo = newZombie("BOO");
	boo->announce();
	sleep(1);
	std::cout << "HELP, 😱... Zombies  🧟 🧟🧟🧟.... 😨" << std::endl;
	sleep(2);
	std::cout << "Dont you worry, van Helsing to rescue..🏃" << std::endl;
	sleep(3);
	delete boo;

	return 1;	
}
