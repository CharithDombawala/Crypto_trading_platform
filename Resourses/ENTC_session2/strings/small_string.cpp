#include "stdafx.h"
#include <iostream>
#include <string>

void* operator new (size_t size)
{
	std::cout << "Allocating " << size << " Bytes" << std::endl;
	return malloc(size);
}

int main()
{
	std::cout << "Creating 13 char string" << std::endl;
	std::string msg = "Hello world 1"; 
	//13 chars, fit into small string, no heap allocation.

	std::cout << "Creating 15 char string" << std::endl;
	std::string msg2 = "Hello world 123"; 
	//15 chars, fit into small string, no heap allocation.

	std::cout << "Creating 17 char string" << std::endl;
	std::string msg3 = "Hello world 12345"; 
	//17 chars, not fit into small string, heap allocation.

	std::cin.get();
}
