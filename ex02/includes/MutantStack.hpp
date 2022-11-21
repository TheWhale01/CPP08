#pragma once
#include <list>
#include <stack>
#include <iostream>

template<typename T>
class MutantStack: public std::stack<T>
{
	public:
		MutantStack(void){return ;}
		MutantStack(MutantStack const &rhs) {*this = rhs; return;}
		virtual ~MutantStack(void) {return ;}

		MutantStack &operator=(MutantStack const &rhs)
		{
			if (this == &rhs)
				return (*this);
			static_cast< std::stack<T> >(*this) = static_cast< std::stack<T> >(rhs);
			return (*this);
		}

		typedef typename std::stack<T>::container_type container_type;

		typename container_type::iterator begin(void) {return (this->c.begin());}
		typename container_type::iterator end(void) {return (this->c.end());}
		typename container_type::const_iterator begin(void) const {return (this->c.begin());}
		typename container_type::const_iterator end(void) const {return (this->c.end());}
		typename container_type::const_reverse_iterator rbegin(void) const {return (this->c.rbegin());}
		typename container_type::const_reverse_iterator rend(void) const {return (this->c.rend());}
};