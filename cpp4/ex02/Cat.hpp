/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erigonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 17:28:07 by erigonza          #+#    #+#             */
/*   Updated: 2024/10/26 17:28:08 by erigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

#include "AAnimal.hpp"

class Cat : public AAnimal {
	private:
		Brain	*_brain;

	public:
		Cat(void);
		Cat(const Cat& copy);
		~Cat(void);
		Cat&	operator=(const Cat& copy);
		void	makeSound(void) const;
		Brain& getBrain(void);
		void setBrain(const Brain& brain);
};

#endif
