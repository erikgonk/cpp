/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erigonza <erigonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 18:15:40 by erigonza          #+#    #+#             */
/*   Updated: 2025/03/08 19:59:52 by erigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

//                                                                            //
//                                 main                                       //
//                                                                            //

int main(int ac, char **av) {
    try {
        if (ac < 2 || ac > 10000)
            throw PmergeMe::errorException();
        PmergeMe    merge(&av[1]);
        merge.merge_process();
        merge.print_time();
    }
    catch (PmergeMe::errorException &e) {
        std::cout << B_RED << e.what() << RESET << std::endl;
    }
}

//                                                                            //
//                                 utils                                      //
//                                                                            //

/*
	This function prints the processing time for sorting a vector and a deque. Converts
	microseconds to milliseconds, formats the output and displays the times for both data structures.
*/
void PmergeMe::print_time() {
	string und = " us";

	if (this->deqTime >= 1000 && this->vecTime >= 1000) {
		this->deqTime /= 1000;
		this->vecTime /= 1000;
		und = " ms";
	}
	std::cout << "Time to process a range of " << this->amount << " elements with std::vector : " << std::fixed << std::setprecision(5) << this->vecTime << und << std::endl;
	std::cout << "Time to process a range of " << this->amount << " elements with std::deque  : " << std::fixed << std::setprecision(5) << this->deqTime << und << std::endl;
}

/*
	Checks if the value is a positive integer.
*/
bool PmergeMe::is_valid(string arg) {
	for (size_t i = 0; i < arg.size(); i++) {
		if (arg[i] < '0' || arg[i] > '9')
			return false;
	}
	return true;
}

/*
	Check if num is repeated
*/
bool PmergeMe::is_repeat(int n, stdVector vec) {
	return std::find(vec.begin(), vec.end(), static_cast<unsigned int>(n)) != vec.end();
}

/*
	Print the vector before and after sorting.
*/
void PmergeMe::print_result() {
	std::cout << "Before: ";
	for (size_t i = 0; i < this->vec.size(); i++)
		std::cout << this->vec[i] << " ";
	std::cout << std::endl;

	std::cout << "After:  ";

	for (size_t i = 0; i < deq.size(); i++)
		std::cout << this->deq[i] << " ";
	std::cout << std::endl;
}

/*
    Exception
*/
PmergeMe::errorException::errorException() : std::logic_error("\terror") {}

//                                                                            //
//                                 deque                                      //
//                                                                            //

/*
	This function determines the range of elements and the insertion position on the deque. 
*/
void PmergeMe::insert_group(stdDeque &main, stdDeque src, size_t init, size_t end, stdDeque::iterator pos) {
	if (end >= src.size())
		return;
	stdDeque::iterator it = src.begin();
	stdDeque::iterator ite = src.begin();
	std::advance(it, init);
	std::advance(ite, end + 1);
	main.insert(pos, it, ite);
}

/*
	This function calculates the correct insertion point by comparing values in groups.	
*/
void PmergeMe::compare_and_insert(stdDeque &main, stdDeque src, size_t pos, size_t groupsize) {
	int compare = 0;
	int groupindex;
	int pair;
	bool flag = false;
	stdDeque::iterator it = main.begin();

	if (pos + groupsize >= src.size())
		compare = main.size() - 1;
	else {
		while (main[compare] != src[pos + groupsize])
			compare++;
	}
	pair = (compare + 1) / groupsize;
	while (!flag && ((src[pos] < main[compare]) || (compare == (int)(main.size() - 1) || src[pos] > main[compare + groupsize]))) {
		while (compare != -1 && src[pos] < main[compare]) {
			groupindex = (compare + 1) / groupsize;
			pair = groupindex;
			compare = (((groupindex - 1) / 2) + 1) * groupsize - 1;
			if (groupindex == 1 && src[pos] < main[compare]) {
				flag = true;
				compare = -1;
			}
		} while (compare != -1 && src[pos] > main[compare]) {
			if (compare == (int)(main.size() - 1)) {
				flag = true;
				break;
			}
			groupindex = (compare + 1) / groupsize;
			compare = (((pair - groupindex) / 2) + groupindex) * groupsize - 1;
			if (groupindex == pair - 1) {
				flag = true;
				break;
			}
			if (src[pos] < main[compare]) {
				compare -= groupsize;
				break;
			}
		}
	}
	std::advance(it, compare + 1);
	insert_group(main, src, pos - groupsize + 1, pos, it);
}

/*
	This function calculates positions dynamically and repeatedly inserts groups into the main deque
*/
stdDeque PmergeMe::jacob_sort(stdDeque src, size_t groupsize) {
	stdDeque main;
	size_t groups = src.size() / groupsize;
	size_t prevpos = groupsize - 1;

	for (size_t i = 1; i <= groups; i += 2)
		insert_group(main, src, i * groupsize, i * groupsize + groupsize - 1, main.end());
	insert_group(main, src, 0, groupsize - 1, main.begin());
	for (size_t i = 1; main.size() < src.size(); i++) {
		size_t pos = ((jacob[i] + jacob[i - 1]) * 2 + 1) * groupsize - 1;
		if (pos >= src.size())
			pos = (groups % 2 == 0 ? src.size() - groupsize - 1 : src.size() - 1);
		size_t aux = pos;
		while (pos > prevpos) {
			compare_and_insert(main, src, pos, groupsize);
			pos -= groupsize * 2;
		}
		prevpos = aux;
	}
	return main;
}

/*
	This function compares values at calculated positions, inserts them in order an applies Jacob sorting.
*/
stdDeque PmergeMe::merge_deques(stdDeque src, size_t groupsize) {
	stdDeque aux;
	size_t pos;

	groupsize *= 2;
	size_t groups = src.size() / groupsize;
	if (!groups)
		groups = 1;
	if (groups * groupsize > src.size())
		return src;
	else {
		for (size_t i = 1; i <= groups; i++) {
			pos = i * groupsize - 1;
			if (src[pos] < src[pos - groupsize / 2]) {
				insert_group(aux, src, pos - groupsize / 2 + 1, pos, aux.end());
				insert_group(aux, src, pos - groupsize + 1, pos - groupsize / 2, aux.end());
			} else {
				insert_group(aux, src, pos - groupsize + 1, pos - groupsize / 2, aux.end());
				insert_group(aux, src, pos - groupsize / 2 + 1, pos, aux.end());
			}
		}
		aux = merge_deques(aux, groupsize);
		aux = jacob_sort(aux, groupsize);
		insert_group(aux, src, pos + 1, pos + groupsize / 2, aux.end());
	}
	if (groupsize == 2)
		aux = jacob_sort(aux, 1);
	return aux;
}
