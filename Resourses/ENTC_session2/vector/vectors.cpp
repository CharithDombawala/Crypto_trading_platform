#include "stdafx.h"
#include <iostream>
#include <vector>

struct Point
{
	int m_x;
	int m_y;
};

std::ostream& operator << (std::ostream& stream, const Point& point)
{
	stream << "X=" << point.m_x << ", Y=" << point.m_x;
	return stream;
}

int main()
{
	Point p1[5]; 
	//Stack allocated array, limit with hard coded size.

	Point* p2 = new Point[5]; 
	//Heap allocated array, still limit with hard coded size.

	std::vector<Point> vecP;
	//Dynamic array. No hard coded limit
	vecP.push_back({ 50, 89 });
	vecP.push_back({ 14, 60 });
	vecP.push_back({ 80, 90 });

	std::cout << "Printing vector by using index" << std::endl;
	for (int i = 0; i < vecP.size(); i++)
	{
		std::cout << vecP[i] << std::endl;
	}

	std::cout << "Printing vector by using range based for loop" << std::endl;
	for (const Point& p : vecP)
	{
		std::cout << p << std::endl;
	}	

	std::cin.get();
}

