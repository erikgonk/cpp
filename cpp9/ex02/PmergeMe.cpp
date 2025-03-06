#include "PmergeMe.hpp"

PmergeMe::PmergeMe(void)
{
}

PmergeMe::PmergeMe(const PmergeMe &other)
{
	static_cast<void>(other);
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
	static_cast<void>(other);
	return (*this);
}

PmergeMe::~PmergeMe(void)
{
}

