#include "Span.hpp"

std::vector<int> getRandom(size_t size)
{
	std::vector<int> result;
	result.reserve(size);

	for (size_t i = 0; i < size; ++i)
		result.push_back(std::rand());

	return result;
}

int main()
{
	std::srand(std::time(NULL));
	try
	{
		// Span sp0;
		
		std::cout << "--- 1 ---" << std::endl;
		Span sp1(3);
		std::cout << "sp1 : ";
		sp1.print();
		sp1.addNumber(9);
		sp1.addNumber(3);
		std::cout << "sp1 : ";
		sp1.print();
		sp1.addNumber(7);
		std::cout << "sp1 : ";
		sp1.print();

		Span sp2(sp1);
		std::cout << "sp2 : ";
		sp2.print();

		Span sp3(0);
		sp3 = sp1;
		std::cout << "sp3 : ";
		sp3.print();

		Span sp4(10);
		sp4 = sp1;
		std::cout << "sp4 : ";
		sp4.print();

		std::cout << "--- 2 ---" << std::endl;
		sp1.addNumber(2);
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		Span sp(0);
		sp.addNumber(5);
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	{
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		std::cout << "--- 3 ---" << std::endl;
		std::cout << "shortest span : " << sp.shortestSpan() << std::endl;
		std::cout << "longest span : " << sp.longestSpan() << std::endl;
	}
	{
		std::vector<int> v = getRandom(20000);
		Span sp(20000);
		sp.addRange(v.begin(), v.end());
	}
}
