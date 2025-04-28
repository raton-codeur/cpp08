#ifndef EASYFIND_HPP
#define EASYFIND_HPP
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

template <typename T>
bool easyfind(const T& container, int value)
{
	return std::find(container.begin(), container.end(), value) != container.end();
}

#endif