/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erigonza <erigonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 13:42:05 by erigonza          #+#    #+#             */
/*   Updated: 2025/02/12 18:51:55 by erigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AForm_HPP
# define AForm_HPP

# include "Bureaucrat.hpp"
# include <iostream>

class	Bureaucrat;

class AForm
{
  public:
	AForm(void);
	AForm(const std::string &name, int sign_grade, int exec_grade);
	AForm(const AForm &other);
	AForm &operator=(const AForm &other);
	~AForm(void);

	const std::string &getName(void) const;
	bool isSigned() const;
	int getSignGrade() const;
	int getExecGrade() const;
	void beSigned(const Bureaucrat &bureaucrat);
	virtual void execute(const Bureaucrat &executor) const = 0;
	
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

	class FormNotSignedException : public std::exception
	{
		public:
		const char *what(void) const throw();
	};
	
	void checkExecution(const Bureaucrat &executor) const;

	
	private:
	const std::string	name_;
	bool				is_signed_;
	const int			sign_grade_;
	const int			exec_grade_;
};

std::ostream &operator<<(std::ostream &os, const AForm &form);

#endif
