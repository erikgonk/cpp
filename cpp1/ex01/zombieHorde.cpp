/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erigonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 12:33:30 by erigonza          #+#    #+#             */
/*   Updated: 2024/10/14 13:03:59 by erigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sstream>
#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name) {
	Zombie *horde = new Zombie[N];
	for (int i = 0; i < N; i++) {
		std::stringstream ss;
		ss << i + 1;
		std::string z_name = name = + " " + ss.str();
		horde[i].setName(z_name);
	}
	return horde;
}
