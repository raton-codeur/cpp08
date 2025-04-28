#include "Span.hpp"

Span::Span(unsigned int size) {
	this->_vec.reserve(size);
}

Span::Span(const Span &src) {
	*this = src;
}

Span::~Span() {}

Span &Span::operator=(const Span &src) {
	// Copy capacity and values
	this->_vec.reserve(src._vec.capacity());
	this->_vec = src._vec;
	return *this;
}

void Span::addNumber(int n) {
	if (this->_vec.size() == this->_vec.capacity())
		throw FullException();
	this->_vec.push_back(n);
}

void Span::addRange(std::vector<int>::iterator beg, std::vector<int>::iterator end) {

	// distance: returns the number of elements between beg and end
	// capacity - size: returns the number of elements that can be inserted in the container
	if (static_cast<unsigned long>(std::distance(beg, end)) > _vec.capacity() - _vec.size())
		throw FullException();

	// end: returns an iterator to the element following the last element of the range
	// insert: inserts elements from range [beg, end) before pos
	this->_vec.insert(this->_vec.end(), beg, end);
}

int Span::shortestSpan() const {
	if (this->_vec.size() <= 1)
		throw NoSpanException();
	std::vector<int> tmp(this->_vec);
	std::sort(tmp.begin(), tmp.end());
	int min = tmp[1] - tmp[0];
	for (size_t i = 2; i < tmp.size(); i++) {
		if (tmp[i] - tmp[i - 1] < min)
			min = tmp[i] - tmp[i - 1];
	}
	return min;
}

int Span::longestSpan() const {
	if (this->_vec.size() <= 1)
		throw NoSpanException();
	std::vector<int> tmp(this->_vec);
	std::sort(tmp.begin(), tmp.end());
	return tmp[tmp.size() - 1] - tmp[0];
}

void Span::showNumbers() const {
	for (size_t i = 0; i < this->_vec.size(); i++) {
		std::cout << "vec[" << i << "] = " << this->_vec[i] << std::endl;
	}
	// Show capacity and size
	std::cout << "capacity = " << this->_vec.capacity() << std::endl;
	std::cout << "size = " << this->_vec.size() << std::endl;
}

Span::Span() {}