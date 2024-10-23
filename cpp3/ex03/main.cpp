/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erigonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 12:01:02 by erigonza          #+#    #+#             */
/*   Updated: 2024/10/23 10:12:41 by erigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main( void ) {
    // Test Default Constructor
    DiamondTrap diamondTrapDefault;
    std::cout << "Default Constructor Test:\n";
    std::cout << GREEN << "Hit Points: " << diamondTrapDefault.getHitPoints() << RESET << std::endl;
    std::cout << MAGENTA << "Energy Points: " << diamondTrapDefault.getEnergyPoints() << RESET << std::endl;
    std::cout << BOLD << RED << "Attack Damage: " << diamondTrapDefault.getAttackDamage() << RESET << std::endl;
    std::cout << "ClapTrap Name: " << diamondTrapDefault.getClapTrapName() << RESET << std::endl;
    diamondTrapDefault.whoAmI();  // Testing whoAmI member function
    diamondTrapDefault.attack("Target");  // Testing attack member function
    std::cout << BOLD << "=========================\n" << RESET;

    // Test Copy Constructor
    DiamondTrap diamondTrapCopy(diamondTrapDefault);
    std::cout << "Copy Constructor Test:\n";
    std::cout << GREEN << "Hit Points: " << diamondTrapCopy.getHitPoints() << RESET << std::endl;
    std::cout << MAGENTA << "Energy Points: " << diamondTrapCopy.getEnergyPoints() << RESET << std::endl;
    std::cout << BOLD << RED << "Attack Damage: " << diamondTrapCopy.getAttackDamage() << RESET << std::endl;
    std::cout << "ClapTrap Name: " << diamondTrapCopy.getClapTrapName() << RESET << std::endl;
    diamondTrapCopy.whoAmI();
    diamondTrapCopy.attack("AnotherTarget");
    std::cout << BOLD << "=========================\n" << RESET;

    // Test Assignment Operator
    DiamondTrap diamondTrapAssign;
    diamondTrapAssign = diamondTrapCopy;
    std::cout << "Assignment Operator Test:\n";
    std::cout << GREEN << "Hit Points: " << diamondTrapAssign.getHitPoints() << RESET << std::endl;
    std::cout << MAGENTA << "Energy Points: " << diamondTrapAssign.getEnergyPoints() << RESET << std::endl;
    std::cout << BOLD << RED << "Attack Damage: " << diamondTrapAssign.getAttackDamage() << RESET << std::endl;
    std::cout << "ClapTrap Name: " << diamondTrapAssign.getClapTrapName() << RESET << std::endl;
    diamondTrapAssign.whoAmI();
    diamondTrapAssign.attack("AnotherTarget");
    std::cout << BOLD << "=========================\n" << RESET;

    // Test Parameterized Constructor
    DiamondTrap customDiamond("CustomDiamond");
    std::cout << "Parameterized Constructor Test:\n";
    std::cout << GREEN <<  "Hit Points: " << customDiamond.getHitPoints() << RESET << std::endl;
    std::cout << MAGENTA << "Energy Points: " << customDiamond.getEnergyPoints() << RESET << std::endl;
    std::cout << BOLD << RED << "Attack Damage: " << customDiamond.getAttackDamage() << RESET << std::endl;
    std::cout << "ClapTrap Name: " << customDiamond.getClapTrapName() << RESET << std::endl;
    customDiamond.whoAmI();
    customDiamond.attack("AnotherTarget");
    std::cout << BOLD << "=========================\n" << RESET;
    
    return 0;
}
