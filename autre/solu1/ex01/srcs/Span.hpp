#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <vector>
# include <algorithm>

class Span {
	public:
		Span(unsigned int size); // Constructor
		Span(const Span &src); // Copy constructor
		~Span(); // Destructor
		Span &operator=(const Span &other); // Assignation operator overload

		void	addNumber(int n);
		void	addRange(std::vector<int>::iterator beg, std::vector<int>::iterator end);
		int		shortestSpan() const;
		int		longestSpan() const;
		void	showNumbers() const;

	private:
		std::vector<int>	_vec;
		Span(); // Default constructor

	class FullException : public std::exception {
		public:
			virtual const char *what() const throw() {
				return "Span is full";
			}
	};
	class NoSpanException : public std::exception {
		public:
			virtual const char *what() const throw() {
				return "No span to find";
			}
	};
};

#endif