/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erigonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 12:01:02 by erigonza          #+#    #+#             */
/*   Updated: 2024/10/23 10:14:49 by erigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

/**
 * @name DiamondTrap (default constructor)
 * @brief Constructor implementation.
 * 
 * Initializes the DiamondTrap with the default name, hit points, energy points, and attack damage.
*/
DiamondTrap::DiamondTrap( void ) : ClapTrap( "Default_clap_name", FragTrap::hitPoints, ScavTrap::energyPoints, FragTrap::attackDamage ) {
    this->name = "Default";
    std::cout << "DiamondTrap " << this->getName() << " is born!" << std::endl;
    return ;
}

/**
 * @name DiamondTrap (copy constructor)
 * @brief Constructor implementation.
 * 
 * Initializes the DiamondTrap with the name, hit points, energy points, and attack damage of the source.
 * Displays a birth message.
*/
DiamondTrap::DiamondTrap( const DiamondTrap& src ) : ClapTrap( src.getName() ) {
    std::cout << "DiamondTrap " << src.getName() << " is born!" << std::endl;
    *this = src;
}

/**
 * @name ~DiamondTrap (destructor)
 * @brief Destructor implementation.
 * 
 * Displays a death message.
*/
DiamondTrap::~DiamondTrap( void ) {
    std::cout << "DiamondTrap " << this->getName() << " is destroyed!" << std::endl;
    return ;
}

/**
 * @name operator= (assignment operator)
 * @brief Assignment operator implementation.
 * 
 * Assigns the attributes of the source to the current instance.
*/
DiamondTrap& DiamondTrap::operator=( const DiamondTrap& rhs ) {
    std::cout << "DiamondTrap " << rhs.getName() << " is born!" << std::endl;
    
    if ( this != &rhs ) {
        this->name = rhs.name;
        this->setHitPoints( rhs.getHitPoints() );
        this->setEnergyPoints( rhs.getEnergyPoints() );
        this->setAttackDamage( rhs.getAttackDamage() );
  
    }
    return *this;
}

/**
 * @name DiamondTrap (parameterized constructor)
 * @brief Constructor implementation.
 * 
 * Initializes the DiamondTrap with the given name, hit points, energy points, and attack damage.
 * Displays a birth message.
*/
DiamondTrap::DiamondTrap( std::string name ) : ClapTrap( name + "_clap_name", FragTrap::hitPoints, ScavTrap::energyPoints, FragTrap::attackDamage ){
    std::cout << "DiamondTrap " << name << " is born!" << std::endl;
    this->name = name;
    return ;
}

/**
 * @name whoAmI
 * @brief Member function implementation.
 * 
 * Displays the name of the DiamondTrap and the name of the ClapTrap.
*/
void DiamondTrap::whoAmI( void ) {
    std::cout << "I am " << name << " and my ClapTrap name is " << this->getClapTrapName() << std::endl;
}

/**
 * @name attack
 * @brief Member function implementation.
 * 
 * Displays a message.
*/
void DiamondTrap::attack( std::string const & target) {
    ScavTrap::attack(target);
}

/**
 * @name getHitPoints
 * @brief Accessor implementation.
 * 
 * Returns the hit points of the DiamondTrap.
*/
unsigned int DiamondTrap::getHitPoints( void ) const {
    return FragTrap::getHitPoints();
}

/**
 * @name getEnergyPoints
 * @brief Accessor implementation.
 * 
 * Returns the energy points of the DiamondTrap.
*/
unsigned int DiamondTrap::getEnergyPoints( void ) const {
    return ScavTrap::getEnergyPoints();
}

/**
 * @name getAttackDamage
 * @brief Accessor implementation.
 * 
 * Returns the attack damage of the DiamondTrap.
*/
unsigned int DiamondTrap::getAttackDamage( void ) const {
    return FragTrap::getAttackDamage();
}

/**
 * @name getClapTrapName
 * @brief Accessor implementation.
 * 
 * Returns the name of the ClapTrap.
*/
std::string DiamondTrap::getClapTrapName( void ) const {
    return ClapTrap::getName();
}
