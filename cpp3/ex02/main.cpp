/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erigonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 12:01:02 by erigonza          #+#    #+#             */
/*   Updated: 2024/10/23 09:48:35 by erigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main( void ) {
    // Test Default Constructor
    FragTrap fragTrapDefault;
    std::cout << "Default Constructor Test:\n";
    std::cout << GREEN << "Hit Points: " << fragTrapDefault.getHitPoints() << RESET << std::endl;
    std::cout << MAGENTA << "Energy Points: " << fragTrapDefault.getEnergyPoints() << RESET << std::endl;
    std::cout << BOLD << RED << "Attack Damage: " << fragTrapDefault.getAttackDamage() << RESET << std::endl;
    std::cout << BOLD << "Name: " << fragTrapDefault.getName() << RESET<< std::endl;
    std::cout << BOLD << "=========================\n" << RESET;

    // Test Parameterized Constructor
    FragTrap customFragTrap("CustomFragTrap");
    std::cout << "Parameterized Constructor Test:\n";
    std::cout << GREEN << "Hit Points: " << customFragTrap.getHitPoints() << RESET << std::endl;
    std::cout << MAGENTA << "Energy Points: " << customFragTrap.getEnergyPoints() << RESET << std::endl;
    std::cout << BOLD << RED << "Attack Damage: " << customFragTrap.getAttackDamage() << std::endl;
    std::cout << BOLD << "Name: " << customFragTrap.getName() << RESET << std::endl;
    std::cout << BOLD << "=========================\n" << RESET;

    // Test highFivesGuys member function
    std::cout << "Calling highFivesGuys:\n";
    customFragTrap.highFivesGuys();
    std::cout << BOLD << "=========================\n" << RESET;

    return 0;
}
