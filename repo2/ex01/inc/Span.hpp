#ifndef SPAN_HPP
#define SPAN_HPP
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

class Span
{
	private :
		std::vector<int> _v;

		Span();

	public :
				Span(unsigned int N);
				Span(const Span& other);
		Span&	operator=(const Span& other);
				~Span();

		void			addNumber(int n);
		void			print() const;
		unsigned int	shortestSpan() const;
		unsigned int	longestSpan() const;
		void			addRange(std::vector<int>::iterator beg, std::vector<int>::iterator end);
};

#endif