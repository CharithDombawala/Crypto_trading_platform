#include "stdafx.h"
#include <iostream>
#include <future>

uint64_t calculate(uint64_t from, uint64_t to)
{
	uint64_t sum = 0;
	std::cout << "Thread id of calculate: " << std::this_thread::get_id() << std::endl;
	for (uint64_t i = from; i < to; i++)
	{
		if (i & 1)
		{
			sum += i;
		}
	}
	return sum;
}

int main()
{
	std::cout << "Thread id of main (Caller): " << std::this_thread::get_id() << std::endl;
	uint64_t from = 0;
	uint64_t to = 7000000000;
	std::future<uint64_t> result = std::async(std::launch::async, calculate, from, to);

	std::cout << "Waiting for results ..." << std::endl;
	std::cout << "Result: " << result.get() << std::endl;

	std::cout << "Completed!" << std::endl;

	std::cin.get();
}
