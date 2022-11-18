#include "easyfind.hpp"

int main(void)
{
	std::list<int> lst;

	for (int i = 0; i < 4; i++)
		lst.push_back(i * 2);
	std::cout << lst << std::endl;
	try
	{
		std::cout << *easyfind(lst, 3) << std::endl;
	}
	catch (std::exception const &e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		std::cout << *easyfind(lst, 4) << std::endl;
	}
	catch (std::exception const &e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (0);
}