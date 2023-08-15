#include "stdafx.h"
#include <stdio.h>
#include <iostream>
#include <string>

int main()
{
	const char* msg1 = "Hello world 1";
	std::cout << msg1 << std::endl;
	//You cannot change value in msg1 as it is declared as const

	char* msg2 = "Hello world 2";
	std::cout << msg2 << std::endl;
	//even though this is pointer, this is not allocated in the heap
	//So no need to use delete[]

	char msg3[13] = { 'H', 'e', 'l', 'l', 'o', ' ', 'w', 'o', 'r', 'l', 'd', ' ', '3' };
	std::cout << msg3 << std::endl;
	//Manually declared char array

	char msg4[14] = { 'H', 'e', 'l', 'l', 'o', ' ', 'w', 'o', 'r', 'l', 'd', ' ', '4', '\0' };
	std::cout << msg4 << std::endl;
	//Added \0, now msg4 string ends properly. See the cout results
	
	//Using string is easy. Lot of utility functions available
	std::string msg5 = "Hello world 5";
	std::cout << msg5 << std::endl;
	std::cout << msg5.size() << std::endl;

	std::cin.get();
}
