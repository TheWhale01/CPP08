#include "Span.hpp"

Span::Span(void)
{
	return ;
}

Span::Span(size_t N): _tab(new int[N]), _len(0), _max(N)
{
	return ;
}

Span::Span(Span const &rhs)
{
	*this = rhs;
	return ;
}

Span::~Span(void)
{
	delete this->_tab;
	return ;
}

/* OPERATOR OVERLOADS */

Span &Span::operator=(Span const &rhs)
{
	if (this == &rhs)
		return (*this);
	delete this->_tab;
	this->_len = rhs._len;
	this->_max = rhs._max;
	this->_tab = rhs._tab;
	return (*this);
}

/* MEMBER FUNCTIONS */

void Span::addNumber(int nb)
{
	if (this->_len == this->_max)
		throw (Span::SpanFullExcpetion());
	this->_tab[this->_len++] = nb;
}

int Span::shortestSpan(void)
{
	int min;

	min = abs(this->_tab[0] - this->_tab[1]);
	for (size_t i = 0; i < this->_len - 1; i++)
		for (size_t j = i + 1; j < this->_len; j++)
			if (min > abs(this->_tab[i] - this->_tab[j]))
				min = abs(this->_tab[i] - this->_tab[j]);
	return (min);

}

int Span::longestSpan(void)
{
	int min;
	int max;

	min = this->_tab[0];
	max = this->_tab[0];
	for (size_t i = 0; i < this->_len; i++)
	{
		if (this->_tab[i] < min)
			min = this->_tab[i];
		else if (this->_tab[i] > max)
			max = this->_tab[i];
	}
	return (max - min);
}

/* EXCEPTIONS */

const char *Span::CouldNotFindSpan::what(void) const throw()
{
	return ("Could not find span.");
}

const char *Span::SpanFullExcpetion::what(void) const throw()
{
	return ("Span full.");
}