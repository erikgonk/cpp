/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erigonza <erigonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 13:45:20 by erigonza          #+#    #+#             */
/*   Updated: 2025/02/12 18:10:32 by erigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int	main(void)
{
	Bureaucrat mario("Mario", 5);
	Bureaucrat luigi("Luigi", 145);
	ShrubberyCreationForm shrubbery("Toad");
	RobotomyRequestForm robotomy("Wario");
	PresidentialPardonForm pardon("Peach");
	mario.signAForm(shrubbery);
	luigi.signAForm(robotomy);
	mario.signAForm(pardon);
	mario.executeForm(shrubbery);
	mario.executeForm(robotomy);
	mario.executeForm(pardon);
	return (0);
}
