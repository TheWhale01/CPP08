#pragma once
#include <list>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <exception>

class Span
{
	public:
		Span(size_t N);
		Span(Span const &rhs);
		~Span(void);

		Span &operator=(Span const &rhs);

		int	shortestSpan(void);
		int longestSpan(void);
		void addNumber(int nb);

		template<typename T>
		void iterAdd(typename T::iterator begin, typename T::iterator end)
		{
			for (typename T::iterator i = begin; i != end; i++)
			{
				try
				{
					this->addNumber(*i);
				}
				catch (std::exception const &e)
				{
					std::cerr << e.what() << std::endl;
					delete this->_tab;
					this->_tab = new int[this->_max];
					break;
				}
			}
		}

		class CouldNotFindSpan: public std::exception
		{
			virtual const char *what(void) const throw();
		};

		class SpanFullExcpetion: public std::exception
		{
			virtual const char *what(void) const throw();
		};

	private:
		Span(void);
		int *_tab;
		size_t _len;
		size_t _max;
};