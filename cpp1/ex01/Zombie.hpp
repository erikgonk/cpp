/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erigonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 09:58:24 by erigonza          #+#    #+#             */
/*   Updated: 2024/10/14 12:44:32 by erigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <string>

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"

class Zombie {
	public:
		Zombie ();
		Zombie(std::string name);
		~Zombie();
		void			announce(void);

		std::string		getName() const;
		void			setName(std::string name);
	private:
		std::string name;
};

Zombie* zombieHorde(int N, std::string name);

#endif
