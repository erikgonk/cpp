/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erigonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 09:58:07 by erigonza          #+#    #+#             */
/*   Updated: 2024/10/14 12:00:13 by erigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream> 
#include "Zombie.hpp"

Zombie::Zombie()
	: name("") {}

Zombie::Zombie(std::string name)
	: name(name) {} 

Zombie::~Zombie() {
	std::cout << "Zombie " << name << " has been destroyed ✟" << std::endl;
}

void Zombie::announce() {
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

std::string Zombie::getName() const {
	return name;
}
