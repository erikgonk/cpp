/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erigonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 12:19:26 by erigonza          #+#    #+#             */
/*   Updated: 2024/10/23 10:30:53 by erigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _CLAPTRAP_HPP
# define _CLAPTRAP_HPP

# include <string>
# include <iostream>
# include <cstdlib>

#define RESET   "\033[0m"
#define BOLD     "\033[1m"
#define RED_BACKGROUND "\033[41m"
#define RED     "\033[31m"
#define BOLD_RED "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[1;33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"

class ClapTrap
{
    public:
        // DEFAULT CONSTRUCTORS AND DESTRUCTORS

        ClapTrap( void );
        ClapTrap( const ClapTrap& src );
        ~ClapTrap();
        ClapTrap& operator=( const ClapTrap& rhs );

        // CONSTRUCTOR WITH PARAMETERS

        ClapTrap( const std::string& name );
        ClapTrap( const std::string& name, unsigned int hitPoints, unsigned int energyPoints, unsigned int attackDamage );
        
        // MEMBER FUNCTIONS

        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);

        // SETTERS

        void setName( const std::string& name );
        void setHitPoints( unsigned int hitPoints );
        void setEnergyPoints( unsigned int energyPoints );
        void setAttackDamage( unsigned int attackDamage );        

        // GETTERS

        std::string getName( void ) const;
        unsigned int getHitPoints( void ) const;
        unsigned int getEnergyPoints( void ) const;
        unsigned int getAttackDamage( void ) const;

    private:
        std::string name;
        unsigned int hitPoints;
        unsigned int energyPoints;
        unsigned int attackDamage;

};

#endif
