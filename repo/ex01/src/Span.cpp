#include "Span.hpp"

Span::Span()
{}

Span::Span(unsigned int N) : _N(N)
{}

Span::Span(const Span& other)
{
	(void)other;
}

Span& Span::operator=(const Span& other)
{
	(void)other;
	return *this;
}

Span::~Span()
{}

void Span::addNumber(int n)
{
	if (_v.size() == _N)
		return;
	_v.push_back(n);
	std::cout << n << std::endl;
}

unsigned int Span::shortestSpan()
{
	return 0;
}

unsigned int Span::longestSpan()
{
	return 0;
}

void Span::addRange(std::vector<int>::iterator beg, std::vector<int>::iterator end)
{
	(void)beg;
	(void)end;
}
