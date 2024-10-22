/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erigonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 12:01:02 by erigonza          #+#    #+#             */
/*   Updated: 2024/10/22 12:11:45 by erigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main()
{
    // Test Default Constructor
    ScavTrap scavTrapDefault;
    std::cout << "Default Constructor Test:\n";
    std::cout << BOLD << "Name: " << scavTrapDefault.getName() << RESET << std::endl;
    std::cout << GREEN << "Hit Points: " << scavTrapDefault.getHitPoints() << RESET << std::endl;
    std::cout << BLUE << "Energy Points: " << scavTrapDefault.getEnergyPoints() << RESET << std::endl;
    std::cout << BOLD << RED << "Attack Damage: " << scavTrapDefault.getAttackDamage() << RESET << std::endl;
    scavTrapDefault.attack("DefaultTarget");  // Testing attack member function
    std::cout << BOLD << "=========================\n" << RESET;

    // Test Parameterized Constructor
    ScavTrap customScavTrap("CustomScavTrap");
    std::cout << "Parameterized Constructor Test:\n";
    std::cout << BOLD << "Name: " << customScavTrap.getName() << RESET << std::endl;
    std::cout << GREEN << "Hit Points: " << customScavTrap.getHitPoints() << RESET << std::endl;
    std::cout << BLUE << "Energy Points: " << customScavTrap.getEnergyPoints() << RESET << std::endl;
    std::cout << BOLD << RED << "Attack Damage: " << customScavTrap.getAttackDamage() << RESET << std::endl;
    customScavTrap.attack("CustomTarget");
    std::cout << BOLD << "=========================\n" << RESET;

    // Test guardGate member function
    std::cout << "Calling guardGate:\n";
    customScavTrap.guardGate();
    std::cout << "=========================\n";

    // Add more test cases as needed

	return ( 0 );
}
