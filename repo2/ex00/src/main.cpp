#include "easyfind.hpp"
#define GREEN "\033[32m"
#define RED "\033[31m"
#define RESET "\033[0m"

void print(bool result)
{
	if (result)
		std::cout << GREEN << "found" << RESET << std::endl;
	else
		std::cout << RED << "not found" << RESET << std::endl;
}

int main()
{
	{
		std::cout << "---" << std::endl;

		std::vector<int> v(5);
		for (size_t i = 0; i < v.size(); ++i)
		v[i] = i + 1;

		std::cout << "v : ";
		for (size_t i = 0; i < v.size(); ++i)
			std::cout << v[i] << " ";
		std::cout << std::endl;

		print(easyfind(v, 3));
		print(easyfind(v, 6));
	}
	{
		std::cout << "---" << std::endl;

		std::list<int> l;
		for (size_t i = 0; i < 5; ++i)
			l.push_back(i + 1);
		
		std::cout << "l : ";
		for (std::list<int>::iterator it = l.begin(); it != l.end(); ++it)
			std::cout << *it << " ";
		std::cout << std::endl;

		print(easyfind(l, 0));
		print(easyfind(l, 10));
		print(easyfind(l, 2));
	}
}
