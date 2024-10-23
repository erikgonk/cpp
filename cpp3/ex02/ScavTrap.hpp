/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erigonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 12:11:10 by erigonza          #+#    #+#             */
/*   Updated: 2024/10/22 12:13:45 by erigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _SCAVTRAP_HPP
# define _SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
    public:
        // DEFAULT CONSTRUCTORS AND DESTRUCTORS

        ScavTrap( void );
        ScavTrap( const ScavTrap& src );
        ~ScavTrap();
        ScavTrap& operator=( const ScavTrap& rhs );

        // CONSTRUCTOR WITH PARAMETERS

        ScavTrap( const std::string& name );

        // MEMBER FUNCTIONS

        void attack(const std::string& target);
        void guardGate( void );

    private:
        static const unsigned int hitPoints = 100;
        static const unsigned int energyPoints = 50;
        static const unsigned int attackDamage = 20;
};

#endif
