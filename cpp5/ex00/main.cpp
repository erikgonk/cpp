#include "Bureaucrat.hpp"

int	main(void)
{
	try
	{
		Bureaucrat mario("Mario", 3);
		std::cout << mario << '\n';
		mario.incrementGrade();
		std::cout << mario << '\n';
		mario.decrementGrade();
		mario.decrementGrade();
		std::cout << mario << '\n';
		Bureaucrat luigi("Luigi", 0);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
	return (0);
}
