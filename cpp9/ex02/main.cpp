/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erigonza <erigonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 18:15:40 by erigonza          #+#    #+#             */
/*   Updated: 2025/03/06 18:16:33 by erigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int ac, char **av) {
    try {
        if (ac < 2 || ac > 10000)
            throw PmergeMe::errorException();
        PmergeMe    merge(&av[1]);
        merge.merge_process();
        merge.print_time();
    }
    catch (PmergeMe::errorException &e) {
        std::cout << B_RED << e.what() << RESET << std::endl;
    }
}
