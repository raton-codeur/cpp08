#ifndef SPAN_HPP
#define SPAN_HPP
#include <iostream>
#include <vector>

class Span
{
	private :
		std::vector<int> _v;
		unsigned int _N;

		Span();

	public :
				Span(unsigned int N);
				Span(const Span& other);
		Span&	operator=(const Span& other);
				~Span();

		void			addNumber(int n);
		unsigned int	shortestSpan();
		unsigned int	longestSpan();
		void			addRange(std::vector<int>::iterator beg, std::vector<int>::iterator end);
};

#endif