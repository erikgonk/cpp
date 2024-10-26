/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erigonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 18:09:52 by erigonza          #+#    #+#             */
/*   Updated: 2024/10/26 18:09:54 by erigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void) : _idx(0) {
	std::cout << "Default constructor called for Materia" << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource& copy) {
	*this = copy;
	std::cout << "Copy constructor called for Materia " << std::endl;
}

MateriaSource& MateriaSource::operator=(const MateriaSource& copy ) {
	this->_idx = copy._idx;
	if (this != &copy) {
		for (int i = 0; i < INV; i++) {
			this->_inventory[i] = copy._inventory[i];
		}
	}
	std::cout << "Assignement operator called" << std::endl;
	return *this;
}

MateriaSource::~MateriaSource(void) {
	for (int i = 0; i < INV; i++) {
		if (this->_inventory[i] != NULL)
			delete this->_inventory[i];
	}
	std::cout << "Default destructor called for Materia " << std::endl;
}

void MateriaSource::learnMateria(AMateria *m) {
	if (this->_idx < INV) {
		std::cout << "Now you know-how to create: " << m->getType() << std::endl;
		this->_inventory[this->_idx] = m;
		this->_idx++;
	} else {
		std::cout << "You can not learn more than 4 Materias" << std::endl;
	}
}

AMateria *MateriaSource::createMateria(const std::string& type) {
	int	i;
	for (i = 0; i < INV; i++) {
		if (this->_inventory[i] != NULL) {
			if (type.compare(this->_inventory[i]->getType()) == 0) 
				return this->_inventory[i];
		}
	}
	if (i == INV) {
		std::cout << "You  can not create " << type << " without having it studied first....!" << std::endl;
	}
	return NULL;
}
