#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

int main()
{
	std::vector<int> vec = { 3, 2, 1, 5, 4 };
	std::cout << "Before sort: ";
	for (int val : vec)
	{
		std::cout << " " << val;
	}
	std::cout << std::endl;

	std::sort(vec.begin(), vec.end());
	std::cout << "ASC: ";
	for (int val : vec)
	{
		std::cout << " " << val;
	}
	std::cout << std::endl;

	std::sort(vec.begin(), vec.end(), std::greater<int>());
	std::cout << "DES: ";
	for (int val : vec)
	{
		std::cout << " " << val;
	}
	std::cout << std::endl;
	
	std::cin.get();
}