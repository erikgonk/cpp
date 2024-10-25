/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Olifant.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erigonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 18:11:27 by erigonza          #+#    #+#             */
/*   Updated: 2024/10/25 18:11:31 by erigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "WrongAnimal.hpp"

class Olifant : public WrongAnimal {
	public:
		Olifant(void);
		Olifant(const Olifant& copy);
		~Olifant(void);
		Olifant&	operator=(const Olifant& copy);
		void	makeSound(void) const;
};
