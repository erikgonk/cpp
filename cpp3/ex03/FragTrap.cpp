/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FlagTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erigonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 12:19:28 by erigonza          #+#    #+#             */
/*   Updated: 2024/10/23 09:40:53 by erigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

/**
 * @name FragTrap (default constructor)
 * @brief Constructor implementation.
 * 
 * Initializes the FragTrap with the default name, hit points, energy points, and attack damage.
 * Displays a birth message.
*/
FragTrap::FragTrap( void ) : ClapTrap( "Default", FragTrap::hitPoints, FragTrap::energyPoints, FragTrap::attackDamage ) {
	std::cout << "FragTrap " << this->getName() << " is born!" << std::endl;
	return ;
}

/**
 * @name FragTrap (copy constructor)
 * @brief Constructor implementation.
 * 
 * Initializes the FragTrap with the name, hit points, energy points, and attack damage of the source.
 * Displays a birth message.
*/
FragTrap::FragTrap( const FragTrap& src ) : ClapTrap( src ) {
	std::cout << "FragTrap " << this->getName() << " is born!" << std::endl;
	return ;
}

/**
 * @name ~FragTrap (destructor)
 * @brief Destructor implementation.
 * 
 * Displays a death message.
*/
FragTrap::~FragTrap( void ) {
    std::cout << "FragTrap " << this->getName() << " is destroyed!" << std::endl;
    return ;
}

/**
 * @name operator= (assignment operator)
 * @brief Assignment operator implementation.
 * 
 * Assigns the name, hit points, energy points, and attack damage of the source to the FragTrap.
 * Displays a birth message.
*/
FragTrap& FragTrap::operator=( const FragTrap& rhs ) {
	std::cout << "FragTrap " << this->getName() << " is born!" << std::endl;
	if ( this != &rhs ) {
		this->setName( rhs.getName() );
		this->setHitPoints( rhs.getHitPoints() );
		this->setEnergyPoints( rhs.getEnergyPoints() );
		this->setAttackDamage( rhs.getAttackDamage() );
	}
	return *this;
}

/**
 * @name FragTrap (constructor with parameters)
 * @brief Constructor implementation.
 * 
 * Initializes the FragTrap with the name, hit points, energy points, and attack damage.
 * Displays a birth message.
*/
FragTrap::FragTrap( const std::string& name ) : ClapTrap( name, FragTrap::hitPoints, FragTrap::energyPoints, FragTrap::attackDamage ) {
	std::cout << "FragTrap " << this->getName() << " is born!" << std::endl;
	return ;
}

/**
 * @name highFivesGuys
 * @brief Member function implementation.
 * 
 * Displays a message.
*/
void FragTrap::highFivesGuys( void ) {
	std::cout << "FragTrap " << this->getName() << " have high fived everyone on the trap!" << std::endl;
	return ;
}
