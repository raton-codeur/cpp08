#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP
#include <iostream>
#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
	public :
						MutantStack();
						MutantStack(const MutantStack& other);
		MutantStack<T>&	operator=(const MutantStack& other);
						~MutantStack();
};
#include "MutantStack.tpp"

#endif