#pragma once
#include <list>
#include <iterator>
#include <iostream>
#include <algorithm>
#include <stdexcept>

class OccurenceNotFoundException: public std::exception
{
	public:
		virtual const char *what(void) const throw()
		{
			return ("Occurence not found.");
		}
};

template<typename T>
typename T::iterator easyfind(T &container, int nb)
{
	typename T::iterator i;

	for (i = container.begin(); i != container.end(); i++)
		if (*i == nb)
			return (i);
	throw (OccurenceNotFoundException());
}

template<typename T>
std::ostream &operator<<(std::ostream &stream, std::list<T> lst)
{
	std::cout << "[";
	for (typename std::list<T>::iterator i = lst.begin(); i != lst.end(); i++)
		std::cout << *i << ", ";
	std::cout << "END]";
	return (stream);
}