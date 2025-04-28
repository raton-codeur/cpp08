#include "Span.hpp"

Span::Span()
{}

Span::Span(unsigned int N)
{
	_v.reserve(N);
}

Span::Span(const Span& other)
{
	*this = other;
}

Span& Span::operator=(const Span& other)
{
	if (this != &other)
	{
		std::vector<int> tmp;
		tmp.reserve(other._v.capacity());
    	tmp.insert(tmp.end(), other._v.begin(), other._v.end());
		_v.swap(tmp);
	}
	return *this;
}

Span::~Span()
{}

void Span::addNumber(int n)
{
	if (_v.size() == _v.capacity())
		throw std::logic_error(
			std::string("cannot add ")
			+ std::to_string(n)
			+ " : the Span instance has already "
			+ std::to_string(_v.capacity())
			+ " elements");
	_v.push_back(n);
}

void Span::print() const
{
	for (size_t i = 0; i < _v.size(); ++i)
	{
		std::cout << _v[i];
		if (i + 1 != _v.size())
			std::cout << ", ";
	}
	std::cout << " | size = " << _v.size();
	std::cout << " | capacity = " << _v.capacity() << std::endl;
}

unsigned int Span::shortestSpan() const
{
	if (_v.size() <= 1)
		throw std::logic_error("cannot find shortest span : not enough elements");
	
	std::vector<int> tmp(_v);
	std::sort(tmp.begin(), tmp.end());

	unsigned int result = tmp[1] - tmp[0];
	for (size_t i = 1; i < tmp.size() - 1; ++i)
	{
		unsigned int diff = tmp[i + 1] - tmp[i];
		if (diff < result)
			result = diff;
	}

	return result;
}

unsigned int Span::longestSpan() const
{
	if (_v.size() <= 1)
		throw std::logic_error("cannot find longest span : not enough elements");

	std::vector<int> tmp(_v);
	std::sort(tmp.begin(), tmp.end());

	return tmp.back() - tmp.front();
}

void Span::addRange(std::vector<int>::iterator beg, std::vector<int>::iterator end)
{
	(void)beg;
	(void)end;
}
