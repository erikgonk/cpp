/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erigonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 17:27:31 by erigonza          #+#    #+#             */
/*   Updated: 2024/10/26 17:27:32 by erigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void) {
	std::cout << "Brain created by default" << std::endl;
}

Brain::Brain(const Brain& copy) {
	std::cout << "Brain created with copy constructor" << std::endl;
	*this = copy;
}

Brain& Brain::operator=(const Brain& copy) {
	if (this != &copy) {
		for (int i = 0; i < 100; i++) {
			this->_ideas[i] = copy._ideas[i]; // Deep copy of _ideas array
		}
	}
	std::cout << "Brain assigned via operator" << std::endl;
	return *this;
}

Brain::~Brain(void) {
	std::cout << "Brain deconstructd." << std::endl;
}

const std::string&	Brain::getIdeas(const int& i) const {
	if (i >= 0 && i < 100) {
		return this->_ideas[i];
	}
	return this->_ideas[0];
}

void Brain::setIdeas(const std::string& idea, const int& i) {
	if (i >= 0 && i < 100) {
		this->_ideas[i] = idea;
	}
}
