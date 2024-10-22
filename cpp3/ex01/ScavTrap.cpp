/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erigonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 12:10:03 by erigonza          #+#    #+#             */
/*   Updated: 2024/10/22 12:11:05 by erigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

/**
 * @name ScavTrap (default constructor)
 * @brief Constructor implementation.
 * 
 * Initializes the ScavTrap with the default name, hit points, energy points, and attack damage.
 * Displays a birth message.
*/
ScavTrap::ScavTrap( void ) : ClapTrap( "Default", ScavTrap::hitPoints, ScavTrap::energyPoints, ScavTrap::attackDamage ) {
    std::cout << "ScavTrap " << this->getName() << " is born!" << std::endl;
    return ;
}

/**
 * @name ScavTrap (copy constructor)
 * @brief Constructor implementation.
 * 
 * Initializes the ScavTrap with the name, hit points, energy points, and attack damage of the source.
 * Displays a birth message.
*/
ScavTrap::ScavTrap( const ScavTrap& src ) : ClapTrap( src ) {
    std::cout << "ScavTrap " << this->getName() << " copy is born!" << std::endl;
    return ;
}

/**
 * @name ~ScavTrap (destructor)
 * @brief Destructor implementation.
 * 
 * Displays a death message.
*/
ScavTrap::~ScavTrap( void ) {
    std::cout << "ScavTrap " << this->getName() << " is destroyed!" << std::endl;
    return ;
}

/**
 * @name operator= (assignment operator)
 * @brief Assignment operator implementation.
 * 
 * Assigns the name, hit points, energy points, and attack damage of the source to the ScavTrap.
 * Displays a birth message.
*/
ScavTrap& ScavTrap::operator=( const ScavTrap& rhs ) {
    std::cout << "ScavTrap " << this->getName() << " assignation is born!" << std::endl;
    if ( this != &rhs ) {
        this->setName( rhs.getName() );
        this->setHitPoints( rhs.getHitPoints() );
        this->setEnergyPoints( rhs.getEnergyPoints() );
        this->setAttackDamage( rhs.getAttackDamage() );
    }
    return *this;
}

/**
 * @name ScavTrap (parameterized constructor)
 * @brief Constructor implementation.
 * 
 * Initializes the ScavTrap with the given name, hit points, energy points, and attack damage.
 * Displays a birth message.
*/
ScavTrap::ScavTrap( const std::string& name ) : ClapTrap( name, ScavTrap::hitPoints, ScavTrap::energyPoints, ScavTrap::attackDamage ) {
    std::cout << "ScavTrap " << this->getName() << " is born!" << std::endl;
    return ;
}

/**
 * @name attack
 * @brief Attack member function implementation.
 * 
 * Attacks the target, causing the ScavTrap's attack damage.
 * Displays an attack message.
*/
void ScavTrap::attack( const std::string& target ) {
    if ( this->getHitPoints() == 0 ) {
        std::cout << "ScavTrap " << this->getName() << " is dead and cannot attack " << target << "!" << std::endl;
        return ;
    } else if ( this->getEnergyPoints() < 1 ) {
        std::cout << "ScavTrap " << this->getName() << " has not enough energy points to attack " << target << "!" << std::endl;
        return ;
    } else {
        std::cout << "ScavTrap " << this->getName() << " attacks " << target << ", causing " << this->getAttackDamage() << " points of damage!" << std::endl;
        this->setEnergyPoints( this->getEnergyPoints() - 1 );
        return ;
    }
}

/**
 * @name guardGate
 * @brief Guard gate member function implementation.
 * 
 * Enters in gate keeper mode.
 * Displays a message.
*/
void ScavTrap::guardGate( void ) {
    std::cout << "ScavTrap " << this->getName() << " has entered in Gate keeper mode!" << std::endl;
    return ;
}
