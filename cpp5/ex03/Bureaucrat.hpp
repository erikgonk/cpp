/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erigonza <erigonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 13:45:04 by erigonza          #+#    #+#             */
/*   Updated: 2025/02/13 15:39:27 by erigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include "AForm.hpp"
# include <iostream>

# define MAX_GRADE 1
# define MIN_GRADE 150

class	AForm;

class Bureaucrat
{
	public:
		Bureaucrat(void);
		Bureaucrat(const std::string &name, int grade);
		Bureaucrat(const Bureaucrat &other);
		Bureaucrat &operator=(const Bureaucrat &other);
		~Bureaucrat(void);

		const std::string &getName(void) const;
		int getGrade(void) const;
		void incrementGrade(void);
		void decrementGrade(void);
		void signAForm(AForm &form);
		void executeForm(const AForm &form) const;

		class GradeTooHighException : public std::exception
		{
			public:
			const char *what(void) const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
			const char *what(void) const throw();
		};

	private:
		const std::string name_;
		int grade_;
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat);

#endif
