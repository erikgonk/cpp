/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erigonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 12:01:02 by erigonza          #+#    #+#             */
/*   Updated: 2024/10/21 11:32:05 by erigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main() {
   // Test Default Constructor
    ClapTrap clapTrapDefault;
    std::cout << "Default Constructor Test:\n";
    std::cout << BOLD << "Name: " << clapTrapDefault.getName() << RESET << std::endl;
    std::cout << GREEN << "Hit Points: " << clapTrapDefault.getHitPoints() << RESET << std::endl;
    std::cout << BLUE << "Energy Points: " << clapTrapDefault.getEnergyPoints() << RESET << std::endl;
    std::cout << BOLD << RED << "Attack Damage: " << clapTrapDefault.getAttackDamage() << RESET << std::endl;
    clapTrapDefault.attack("DefaultTarget");  // Testing attack member function
    std::cout << BOLD << "=========================\n" << RESET ;

    // Test Parameterized Constructor
    ClapTrap customClapTrap("CustomClapTrap");
    std::cout << "Parameterized Constructor Test:\n";
    std::cout << BOLD << "Name: " << customClapTrap.getName() << RESET << std::endl;
    std::cout << GREEN << "Hit Points: " << customClapTrap.getHitPoints() << RESET << std::endl;
    std::cout << BLUE << "Energy Points: " << customClapTrap.getEnergyPoints() << RESET << std::endl;
    std::cout << BOLD << RED << "Attack Damage: " << customClapTrap.getAttackDamage() << RESET << std::endl;
    customClapTrap.attack("CustomTarget");
    std::cout << BOLD << "=========================\n" << RESET ;

    // Test Setter and Getter
    std::cout << BOLD << "Setter and Getter Test:\n" << RESET;
    customClapTrap.setName("NewName");
    customClapTrap.setHitPoints(50);
    customClapTrap.setEnergyPoints(75);
    customClapTrap.setAttackDamage(20);
    std::cout << BOLD << "Name after setter: " << customClapTrap.getName() << RESET << std::endl;
    std::cout << GREEN << "Hit Points after setter: " << customClapTrap.getHitPoints() << RESET << std::endl;
    std::cout << BLUE << "Energy Points after setter: " << customClapTrap.getEnergyPoints() << RESET << std::endl;
    std::cout << BOLD << RED << "Attack Damage after setter: " << customClapTrap.getAttackDamage() << RESET << std::endl;
    std::cout << BOLD << "=========================\n" << RESET ;

    // Add more test cases as needed

    return 0;
}
