/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erigonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 12:01:02 by erigonza          #+#    #+#             */
/*   Updated: 2024/10/23 11:58:20 by erigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _DIAMONDTRAP_HPP
# define _DIAMONDTRAP_HPP

# include "ScavTrap.hpp"
# include "FragTrap.hpp"

/*
 * Updated both ScavTrap and FragTrap with the virtual keyword
 * to avoid the diamond problem.
 * 
 * The diamond problem occurs when two classes B and C inherit from A,
 * and class D inherits from both B and C. If there is a method in A
 * that B and C have overridden, and D does not override it, then which
 * version of the method does D inherit: that of B, or that of C?
 * 
 * Virtual inheritance is a C++ technique that ensures only one copy of a
 * base class's member variables are inherited by grandchild derived classes.
*/

class DiamondTrap : public ScavTrap, public FragTrap
{
    public:
        // DEFAULT CONSTRUCTORS AND DESTRUCTORS

        DiamondTrap( void );
        DiamondTrap( DiamondTrap const & src );
        ~DiamondTrap();
        DiamondTrap & operator=( DiamondTrap const & rhs);

        // CONSTRUCTOR WITH PARAMETERS

        DiamondTrap(std::string name);

		// MEMBER FUNCTIONS

        void    whoAmI( void );

        // OVERLOADS

        void    attack(std::string const & target);

        // ACCESSORS

        unsigned int    getHitPoints( void ) const;
        unsigned int    getEnergyPoints( void ) const;
        unsigned int    getAttackDamage( void ) const;
        std::string     getClapTrapName( void ) const;

    private:
        std::string     name;
};

#endif
