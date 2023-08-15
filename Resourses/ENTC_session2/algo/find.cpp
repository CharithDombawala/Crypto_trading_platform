#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	std::vector<int> vec = { 1, 2, 3, 4, 5 };
	int valToFind = 3;
	auto res1 = std::find(std::begin(vec), std::end(vec), valToFind);
	(res1 != std::end(vec))
		? std::cout << "vector contains " << valToFind << std::endl
		: std::cout << "vector does not contain " << valToFind << std::endl;
	std::cin.get();
}