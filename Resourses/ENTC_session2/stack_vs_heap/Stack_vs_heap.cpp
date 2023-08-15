#include "stdafx.h"
#include <stdio.h>
#include <iostream>

struct Point
{
	int m_x;
	int m_y;

	Point()
		: m_x(6), m_y(45)
	{

	}
};

int main()
{
	int stackVal = 9; //stack allocation
	int stackArr[5]; //stack allocation
	stackArr[0] = 1;
	stackArr[1] = 2;
	stackArr[2] = 3;
	stackArr[3] = 4;
	stackArr[4] = 5;

	Point stackPoint; //stack allocation

	int* heapVal = new int(9); //Heap allocation
	int* heapArr = new int[5]; //heap allocation
	heapArr[0] = 1;
	heapArr[1] = 2;
	heapArr[2] = 3;
	heapArr[3] = 4;
	heapArr[4] = 5;

	Point* heapPoint = new Point(); //heap allocation

	std::cin.get();
}

