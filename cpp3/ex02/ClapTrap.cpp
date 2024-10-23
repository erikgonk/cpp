/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erigonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 12:19:28 by erigonza          #+#    #+#             */
/*   Updated: 2024/10/19 12:55:19 by erigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap( void ) : name("Default"), hitPoints(10), energyPoints(10), attackDamage(0) {
    std::cout << "ClapTrap " << getName() << " is born!" << std::endl;
    return ;
}

ClapTrap::ClapTrap( const ClapTrap& src ) {
    *this = src;
    std::cout << "ClapTrap " << getName() << " copy is born!" << std::endl;
    return ;
}

ClapTrap::~ClapTrap( void ) {
    std::cout << "ClapTrap " << getName() << " is destroyed!" << std::endl;
    return ;
}

ClapTrap& ClapTrap::operator=( const ClapTrap& rhs ) {
    std::cout << "ClapTrap " << getName() << " assignation is born!" << std::endl;
    if (this != &rhs) {
        this->name = rhs.name;
        this->hitPoints = rhs.hitPoints;
        this->energyPoints = rhs.energyPoints;
        this->attackDamage = rhs.attackDamage;
    }
    return (*this);
}

ClapTrap::ClapTrap( const std::string& name ) : name(name), hitPoints(10), energyPoints(10), attackDamage(0) {
    std::cout << "ClapTrap " << getName() << " is born!" << std::endl;
    return ;
}

ClapTrap::ClapTrap( const std::string& name, unsigned int hitPoints, unsigned int energyPoints, unsigned int attackDamage )\
 : name(name), hitPoints(hitPoints), energyPoints(energyPoints), attackDamage(attackDamage) {
    std::cout << "ClapTrap " << getName() << " is born!" << std::endl;
    return ;
    
}

//                            MEMBER FUNCTIONS

/**
 * @name Attack
 * @brief Member function to attack a target.
 *
 * If the ClapTrap has sufficient hit points and energy, it attacks the target,
 * causing damage specified by AttackDamage.
 * Decreases energy by 1.
 */
void ClapTrap::attack( const std::string& target ) {
    if ( hitPoints == 0 ) {
        std::cout << RED_BACKGROUND << "ClapTrap " << getName() << " is dead and cannot attack " << target << "!" << RESET << std::endl;
        return ;
    } else if ( energyPoints < 1 ) {
        std::cout << RED_BACKGROUND << "ClapTrap " << getName() << " has no energy left and cannot attack " << target << "!" << RESET << std::endl;
        return ;
    } else {
        std::cout << RESET << "ClapTrap " << getName() << " attacks " << target << ", causing " << getAttackDamage() << " points of damage!" << RESET << std::endl;
        energyPoints--;
    }
}

/**
 * @name TakeDamage
 * @brief Member function to take damage.
 * 
 * Reduces the ClapTrap's hit points by the specified amount.
 */
void ClapTrap::takeDamage( unsigned int amount ) {
    if (hitPoints == 0) {
        std::cout << RED_BACKGROUND << "ClapTrap " << getName() << " can't take damage because it has no hit points left." << RESET << std::endl;
    } else {
        std::cout << RESET << "ClapTrap " << getName() << " takes " << amount << " points of damage!" << RESET << std::endl;
        hitPoints -= amount;
        if (hitPoints <= 0 ) {
            hitPoints = 0;
            std::cout << RED_BACKGROUND << "ClapTrap " << getName() << " has no hit points left." << RESET << std::endl;
        }
    }
}

/**
 * @name BeRepaired
 * @brief Member function to be repaired.
 * 
 * Increases the ClapTrap's hit points by the specified amount.
 * Decreases energy by 1.
 */
void ClapTrap::beRepaired( unsigned int amount ) {
    if ( hitPoints == 0 ) { // If the ClapTrap has no hit points left, it can't be repaired.
        std::cout << "ClapTrap " << getName() << " can't be repaired because it has no hit points left." << RESET << std::endl;
    } else if ( hitPoints == 10 ) { // If the ClapTrap has full hit points, it can't be repaired.
        std::cout << RED_BACKGROUND << "ClapTrap " << getName() << " has already full hit points." << std::endl;
    } else if ( energyPoints < 1 ) { // If the ClapTrap has no energy left, it can't be repaired.
        std::cout << RED_BACKGROUND << "ClapTrap " << getName() << " has no energy left and cannot be repaired." << RESET << std::endl;
    } else {
        std::cout << GREEN << "ClapTrap " << getName() << " is repaired by " << amount << " points!" << RESET << std::endl;
        hitPoints += amount;
        if ( hitPoints > 10 ) {
            hitPoints = 10;
            std::cout << BLUE << "ClapTrap " << getName() << " has full hit points." << RESET << std::endl;
        }
        energyPoints--;
    }
}

// SETTERS
// =======

/**
 * @name NameSetter
 * @brief Set the name of the ClapTrap.
 * 
 * This function sets the name of the ClapTrap.
*/
void ClapTrap::setName( const std::string& name ) {
    this->name = name;
}

/**
 * @name HitPointsSetter
 * @brief Set the current hit points of the ClapTrap.
 * 
 * This function sets the current hit points of the ClapTrap.
*/
void ClapTrap::setHitPoints( unsigned int hitPoints ) {
    this->hitPoints = hitPoints;
}

/**
 * @name EnergyPointsSetter
 * @brief Set the current energy points of the ClapTrap.
 * 
 * This function sets the current energy points of the ClapTrap.
 * 
 * @param energyPoints - The current energy points.
*/
void ClapTrap::setEnergyPoints( unsigned int energyPoints ) {
    this->energyPoints = energyPoints;
}

/**
 * @name AttackDamageSetter
 * @brief Set the current attack damage of the ClapTrap.
 * 
 * This function sets the current attack damage of the ClapTrap.
*/
void ClapTrap::setAttackDamage( unsigned int attackDamage ) {
    this->attackDamage = attackDamage;
}

// GETTERS
// =======

/**
 * @name NameGetter
 * @brief Get the name of the ClapTrap.
 * 
 * This function returns the name of the ClapTrap.
*/
std::string ClapTrap::getName( void ) const {
    return (this->name);
}

/**
 * @name HitPointsGetter
 * @brief Get the current hit points of the ClapTrap.
 *
 * This function returns the current hit points of the ClapTrap.
 */
unsigned int ClapTrap::getHitPoints( void ) const {
    return (this->hitPoints);
}

/**
 * @name EnergyPointsGetter
 * @brief Get the current energy points of the ClapTrap.
 * 
 * This function returns the current energy points of the ClapTrap.
*/
unsigned int ClapTrap::getEnergyPoints( void ) const {
    return (this->energyPoints);
}

/**
 * @name AttackDamageGetter
 * @brief Get the current attack damage of the ClapTrap.
 * 
 * This function returns the current attack damage of the ClapTrap.
*/
unsigned int ClapTrap::getAttackDamage( void ) const {
    return (this->attackDamage);
}
