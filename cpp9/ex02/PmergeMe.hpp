/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erigonza <erigonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 17:50:17 by erigonza          #+#    #+#             */
/*   Updated: 2025/03/08 19:58:39 by erigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <cstdlib>
# include <deque>
# include <vector>
# include <sys/time.h>
# include <iomanip>
# include <algorithm>

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define BOLD_RED "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[1;33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"

#define BOLD "\x1B[1m"
#define ITAL "\x1B[3m"
#define UNDL "\x1B[4m"

#define B_RED "\x1B[41m"
#define B_GRN "\x1B[42m"
#define B_YLW "\x1B[43m"
#define B_BLU "\x1B[44m"
#define B_MAG "\x1B[45m"
#define B_CYN "\x1B[46m"
#define B_WHI "\x1B[47m"

# define MICROSEC 1000000

using std::string;

typedef typename std::vector<unsigned int> stdVector;
typedef typename std::deque<unsigned int> stdDeque;

class PmergeMe {
    public:
        PmergeMe (char **argv);
        PmergeMe (const PmergeMe& cpy);
        ~PmergeMe ();    
        PmergeMe  &operator=(const PmergeMe  &src);

		void add_arguments(char **arg);
		void print_result();
		void print_time();
		bool is_repeat(int n, stdVector vec);
		bool is_valid(string arg);
		void merge_process();

		void compare_and_insert(stdVector &main, stdVector src, size_t pos, size_t groupsize);
		stdVector merge_vectors(stdVector src, size_t groupsize);
		stdVector jacob_sort(stdVector src, size_t groupsize);
		void insert_group(stdVector &main, stdVector src, size_t init, size_t end, stdVector::iterator pos);

		void compare_and_insert(stdDeque &main, stdDeque src, size_t pos, size_t groupsize);
		stdDeque merge_deques(stdDeque src, size_t groupsize);
		stdDeque jacob_sort(stdDeque src, size_t groupsize);
		void insert_group(stdDeque &main, stdDeque src, size_t init, size_t end, stdDeque::iterator pos);

		class errorException : public std::logic_error {
			public:
				errorException();
		};

	private:
		stdDeque					deq;
		stdVector					vec;
		string						arg;
		unsigned int				amount;
		float						vecTime;
		float						deqTime;
		int							jacob[15];
};

#endif
