/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erigonza <erigonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 17:50:04 by erigonza          #+#    #+#             */
/*   Updated: 2025/03/06 18:23:51 by erigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(char **arg) {
	int n;
	int i;

	int jacobs[15] = {0, 2, 2, 6, 10, 22, 42, 87, 170, 342, 682, 1366, 2730, 5462, 10922};
	std::copy(jacobs, jacobs + 15, this->jacob);

	for (i = 0; arg[i]; i++) {
		n = atoi(arg[i]);
		if (!is_valid(arg[i]) || is_repeat(n, vec))
			throw errorException();
		this->deq.push_back(n);
		this->vec.push_back(n);
	}
	this->amount = i;
}

PmergeMe::PmergeMe(const PmergeMe &cpy) { *this = cpy; }

PmergeMe::~PmergeMe() {}

PmergeMe &PmergeMe::operator=(const PmergeMe &cpy) {
	this->deq = cpy.deq;
	this->vec = cpy.vec;
	this->arg = cpy.arg;
	return *this;
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
	Prints the vector content
*/
void PmergeMe::print_vec() {
	for (size_t i = 0; i < this->vec.size(); i++)
		std::cout << this->vec[i] << " ";
	std::cout << std::endl;
}

/*
	Prints the content of an auxiliar vector
*/
void PmergeMe::print_vec(stdVector aux) {
	for (size_t i = 0; i < aux.size(); i++)
		std::cout << aux[i] << " ";
	std::cout << std::endl;
}

/*
	Prints the vector in an group size align format.
*/
void PmergeMe::print_vec(stdVector aux, size_t groupsize) {
	for (size_t i = 0; i < aux.size(); i++) {
		if (i % groupsize == 0)
			std::cout << "| ";
		std::cout << aux[i] << " ";
	}
	std::cout << "|";
	std::cout << std::endl;
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
	Inserts a group of elements from the src vector into the main vector from a specific
	position using init and end operators
*/
void PmergeMe::insert_group(stdVector &main, stdVector src, size_t init, size_t end, stdVector::iterator pos) {
	if (end >= src.size())
		return;
	stdVector::iterator it = src.begin();
	stdVector::iterator ite = src.begin();
	std::advance(it, init);
	std::advance(ite, end + 1);
	main.insert(pos, it, ite);
}

/*
	Compares an element with groups (main) to determine the pos for injection.
	Iterative searches and ajustments depending on the group size.
	Inserts the correct group to the calculated position.
*/
void PmergeMe::compare_and_insert(stdVector &main, stdVector src, size_t pos, size_t groupsize) {
	int compare = 0;
	int groupindex;
	int pair;
	bool flag = false;
	stdVector::iterator it = main.begin();

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
			} if (src[pos] < main[compare]) {
				compare -= groupsize;
				break;
			}
		}
	}
	std::advance(it, compare + 1);
	insert_group(main, src, pos - groupsize + 1, pos, it);
}

/*
	Implements the jacob sort for sorting the groups.
	Divide the groups, sorts it and iterates in the same container (main).
	Iterates until all the main container is in order.
*/
std::vector<unsigned int> PmergeMe::jacob_sort(stdVector src, size_t groupsize) {
	stdVector main;
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
	Merge the vectors by grouping them into pairs or larger broups recursively.
	Compares the elements at a calculated pos and inserts them into the correct order.
	This happens until the vector is fully merged	
*/
std::vector<unsigned int> PmergeMe::merge_vectors(stdVector src, size_t groupsize) {
	size_t groups = src.size() / (groupsize * 2);
	size_t pos;
	stdVector aux;

	if (!groups)
		groups = 1;
	groupsize *= 2;
	if (groups * groupsize > src.size())
		return src;
	else {
		for (size_t i = 1; i <= groups; i++) {
			pos = i * groupsize - 1;

			if (src[pos] < src[pos - groupsize / 2]) {
				insert_group(aux, src, pos - groupsize / 2 + 1, pos, aux.end());
				insert_group(aux, src, pos - groupsize + 1, pos - groupsize / 2, aux.end());
			}
			else {
				insert_group(aux, src, pos - groupsize + 1, pos - groupsize / 2, aux.end());
				insert_group(aux, src, pos - groupsize / 2 + 1, pos, aux.end());
			}
		}
		aux = merge_vectors(aux, groupsize);
		aux = jacob_sort(aux, groupsize);
		insert_group(aux, src, pos + 1, pos + groupsize / 2, aux.end());
	}
	if (groupsize == 2)
		aux = jacob_sort(aux, 1);
	return aux;
}

/*
	This function initializes and calls the merge_sort function to sort the unput vector.
	Once is sorted its returned.
*/
std::vector<unsigned int> PmergeMe::vector_merge(stdVector &src) {
	stdVector main = src;
	size_t groupsize = 1;

	main = merge_vectors(main, groupsize);
	return main;
}

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
std::deque<unsigned int> PmergeMe::jacob_sort(stdDeque src, size_t groupsize) {
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
std::deque<unsigned int> PmergeMe::merge_deques(stdDeque src, size_t groupsize) {
	size_t groups = src.size() / (groupsize * 2);
	size_t pos;
	stdDeque aux;

	if (!groups)
		groups = 1;
	groupsize *= 2;
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

/*
	This function begins with a group size of 1 and progressively merges the deque until is fully
	sorted.
*/
std::deque<unsigned int> PmergeMe::deque_merge(stdDeque &src) {
	stdDeque main = src;
	size_t groupsize = 1;

	main = merge_deques(main, groupsize);
	return main;
}

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
	This function measures the time taken to process each data structure, calls the respective merge
	functions, and prints.
*/
void PmergeMe::merge_process() {
	struct timeval start, end;

	gettimeofday(&start, NULL);
	this->deq = deque_merge(this->deq);
	gettimeofday(&end, NULL);
	this->deqTime = (end.tv_sec - start.tv_sec) * MICROSEC + end.tv_usec - start.tv_usec;

	print_result();

	gettimeofday(&start, NULL);
	this->vec = vector_merge(this->vec);
	gettimeofday(&end, NULL);
	this->vecTime = (end.tv_sec - start.tv_sec) * MICROSEC + end.tv_usec - start.tv_usec;
}

// Exceptions
PmergeMe::errorException::errorException() : std::logic_error("\terror") {}
