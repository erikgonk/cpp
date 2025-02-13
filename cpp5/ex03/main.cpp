/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erigonza <erigonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 13:45:20 by erigonza          #+#    #+#             */
/*   Updated: 2025/02/13 12:39:08 by erigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include <iostream>

int	main(void)
{
	Intern	intern;

	Bureaucrat mario("Mario", 5);
	AForm *shrubbery(intern.makeForm("shrubbery creation", "Toad"));
	AForm *robotomy(intern.makeForm("robotomy request", "Luigi"));
	AForm *pardon(intern.makeForm("presidential pardon", "Peach"));
	AForm *unknown(intern.makeForm("unknown form", "target"));
	if (shrubbery)
	{
		mario.signAForm(*shrubbery);
		mario.executeForm(*shrubbery);
		delete (shrubbery);
	}
	if (robotomy)
	{
		mario.signAForm(*robotomy);
		mario.executeForm(*robotomy);
		delete (robotomy);
	}
	if (pardon)
	{
		mario.signAForm(*pardon);
		mario.executeForm(*pardon);
		delete (pardon);
	}
	if (unknown)
		delete (unknown);
	return (0);
}
