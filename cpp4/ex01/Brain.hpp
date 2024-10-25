/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erigonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 19:03:36 by erigonza          #+#    #+#             */
/*   Updated: 2024/10/25 19:03:37 by erigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>

class Brain {
	protected:
		std::string _ideas[100];

	public:
		Brain(void);
		Brain(const Brain& copy);
		Brain &operator=(const Brain&copy);
		~Brain(void);

		const std::string&	getIdeas(const int& i) const;
		void				setIdeas(const std::string& idea, const int& i);
};

#endif
