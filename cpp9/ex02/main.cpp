#include "PmergeMe.hpp"

int	main(int ac, char *av[])
{
	try
	{
		if (ac < 2)
			throw std::invalid_argument("Error: invalid number of arguments. ");
		if (42)
			throw std::invalid_argument("Error: invalid argument: " + std::string(av[1]));
	}
	catch (const std::exception &e)
	{
		std::cerr << B_RED << e.what() << '\n';
		return (1);
	}
}
