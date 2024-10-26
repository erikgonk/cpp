/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erigonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 18:10:01 by erigonza          #+#    #+#             */
/*   Updated: 2024/10/26 18:10:02 by erigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource {
	private:
		AMateria	*_inventory[INV];
		int			_idx;

	public:
		MateriaSource(void);
		MateriaSource(const MateriaSource& copy);
		MateriaSource &operator=(const MateriaSource& copy);
		~MateriaSource(void);

		virtual void		learnMateria(AMateria *m);
		virtual	AMateria	*createMateria(const std::string &type);
};

#endif
