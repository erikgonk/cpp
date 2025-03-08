/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erigonza <erigonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 17:50:04 by erigonza          #+#    #+#             */
/*   Updated: 2025/03/08 20:22:57 by erigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

//                                                                            //
//                             OrCaForm                                       //
//                                                                            //

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

//                                                                            //
//                                vector                                      //
//                                                                            //

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
stdVector PmergeMe::jacob_sort(stdVector src, size_t groupsize) {
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
	Inserts a group of elements from the src vector into the main vector from a specific
	position using init and end operators
*/
void PmergeMe::insert_group(stdVector &main, stdVector src, size_t init, size_t end, stdVector::iterator pos) {
	if (end >= src.size())
		return ;
	stdVector::iterator it = src.begin();
	stdVector::iterator ite = src.begin();
	std::advance(it, init);
	std::advance(ite, end + 1);
	main.insert(pos, it, ite);
}

/*
	Merge the vectors by grouping them into pairs or larger broups recursively.
	Compares the elements at a calculated pos and inserts them into the correct order.
	This happens until the vector is fully merged
*/
stdVector PmergeMe::merge_vectors(stdVector src, size_t groupsize) {
	stdVector aux;
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
	This function measures the time taken to process each data structure, calls the respective merge
	functions, and prints.
*/
void PmergeMe::merge_process() {
	struct timeval start, end;
	print_result();

	gettimeofday(&start, NULL);
	this->deq = merge_deques(this->deq, 1);

	gettimeofday(&end, NULL);
	this->deqTime = (end.tv_sec - start.tv_sec) * MICROSEC + end.tv_usec - start.tv_usec;

	gettimeofday(&start, NULL);
	this->vec = merge_vectors(this->vec, 1);

	gettimeofday(&end, NULL);
	this->vecTime = (end.tv_sec - start.tv_sec) * MICROSEC + end.tv_usec - start.tv_usec;
}
