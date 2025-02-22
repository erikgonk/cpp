/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FlagTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erigonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 12:19:28 by erigonza          #+#    #+#             */
/*   Updated: 2024/10/23 09:41:10 by erigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FRAGTRAP_HPP
# define _FRAGTRAP_HPP

# include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	public:
	    // DEFAULT CONSTRUCTORS AND DESTRUCTORS

		FragTrap( void );
		FragTrap( const FragTrap& src );
		~FragTrap( void );
		FragTrap& operator=( const FragTrap& rhs );

        // CONSTRUCTOR WITH PARAMETERS

		FragTrap( const std::string& name );

		// MEMBER FUNCTIONS

		void	highFivesGuys( void );
		
	private:
		static const unsigned int	hitPoints = 100;
		static const unsigned int	energyPoints = 100;
		static const unsigned int	attackDamage = 30;
};

#endif
