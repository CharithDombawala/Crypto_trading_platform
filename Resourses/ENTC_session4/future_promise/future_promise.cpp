#include "stdafx.h"
#include <iostream>
#include <future>
#include <thread>

void calculate(std::promise<uint64_t>&& prom, uint64_t from, uint64_t to)
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
	prom.set_value(sum);
}

int main()
{
	std::cout << "Thread id of main (Caller): " << std::this_thread::get_id() << std::endl;

	uint64_t from = 0;
	uint64_t to = 7000000000;
	std::promise<uint64_t> prom;
	std::future<uint64_t> fut = prom.get_future();

	std::thread worker(calculate, std::move(prom), from, to);

	std::cout << "Waiting for results ..." << std::endl;
	std::cout << "Result: " << fut.get() << std::endl;

	std::cout << "Completed!" << std::endl;
	worker.join();

	std::cin.get();
}


