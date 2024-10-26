/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erigonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 18:07:42 by erigonza          #+#    #+#             */
/*   Updated: 2024/10/26 18:07:56 by erigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Ice : virtual public AMateria {

	public:
		Ice(void);
		Ice(const Ice& copy);
		Ice& operator=(const Ice& copy);
		~Ice();

		AMateria*		clone() const;
		virtual void	use(ICharacter& target);
};

#endif
