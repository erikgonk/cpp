/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erigonza <erigonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 18:07:06 by erigonza          #+#    #+#             */
/*   Updated: 2025/02/12 18:39:30 by erigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm("ShrubberyCreation",
	145, 137), target_("default_target")
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : AForm("ShrubberyCreation",
	145, 137), target_(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm(other),
	target_(other.target_)
{
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	if (this == &other)
		return (*this);
	AForm::operator=(other);
	target_ = other.target_;
	return (*this);
}

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const
{
	checkExecution(executor);
	std::ofstream outfile((target_ + "_shrubbery").data());
	if (outfile.is_open())
	{
		outfile << "          .  *  .    .    \n";
		outfile << "       .    *    .     *  \n";
		outfile << "    *   .    .  *   .     \n";
		outfile << "      .  *  .    .  *     \n";
		outfile << "   .      *     .    *  . \n";
		outfile << "      *    .  *    .     .\n";
		outfile << "        .  *  .  *   .    \n";
		outfile << "     .    *    .    *     \n";
		outfile << "        *  .    .  *  .   \n";
		outfile << "           .  *  .        \n";
		outfile << "            *    .        \n";
		outfile.close();
	}
}
