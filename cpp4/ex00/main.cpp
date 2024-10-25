/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erigonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 18:11:16 by erigonza          #+#    #+#             */
/*   Updated: 2024/10/25 18:11:18 by erigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Olifant.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	const WrongAnimal* k = new WrongCat();
	const WrongAnimal* o = new Olifant();

	std::cout << "Dog type: " << j->getType() << " " << std::endl;
	std::cout << "Cat type: " << i->getType() << " " << std::endl;
	i->makeSound(); 
	j->makeSound();
	std::cout << "Awkward mixture of Whale and Dragon.. " << k->getType() << std::endl;
	k->makeSound();
	meta->makeSound();
	std::cout << ".. Olifant " << o->getType() << std::endl;
	o->makeSound();
	delete(meta);
	delete(j);
	delete(i);
	delete(k);
	delete(o);

	return 0;
}
