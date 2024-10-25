/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erigonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 18:10:28 by erigonza          #+#    #+#             */
/*   Updated: 2024/10/25 18:22:10 by erigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

class Animal
{
  protected:
	std::string _type;

  public:
	Animal(void);
	Animal(const Animal &copy);
	Animal &operator=(const Animal &copy);
	virtual ~Animal(void);

	std::string getType(void) const;
	void setType(const std::string type);

	virtual void makeSound(void) const;
};

#endif
