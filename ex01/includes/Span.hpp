#pragma once
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
		void iterAdd(typename T::iterator begin, typename T::iterator end);

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