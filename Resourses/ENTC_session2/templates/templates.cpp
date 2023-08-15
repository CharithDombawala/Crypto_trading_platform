#include "stdafx.h"
#include <iostream>

// template <typename T>
// T add(T a, T b)
// {
// 	return (a + b);
// }
// 
// int add(int a, int b)
// {
// 	return (a + b);
// }
// 
// double add(double a, double b)
// {
// 	return (a + b);
// }

int main()
{
	std::cout << add<int>(20, 30) << std::endl;
	std::cout << add<double>(5.4, 9.7) << std::endl;
	std::cout << add<char>('A', 'B') << std::endl;
	
	std::cin.get();
}