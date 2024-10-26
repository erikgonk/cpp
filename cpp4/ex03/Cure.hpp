/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erigonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 18:07:14 by erigonza          #+#    #+#             */
/*   Updated: 2024/10/26 18:07:16 by erigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Cure : public AMateria {
	public:
		Cure(void);
		Cure(const Cure& copy);
		Cure& operator=(const Cure& copy);
		~Cure();

		AMateria*		clone() const;
		virtual void	use(ICharacter& target);
};

#endif
