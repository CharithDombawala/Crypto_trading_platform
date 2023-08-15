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
	int* heapVal = new int(9); //Heap allocation
	
    int* heapArr = new int[5]; //heap allocation
	
    Point* heapPoint = new Point(); //heap allocation

	delete heapVal;
	
    delete[] heapArr;
	
    delete heapPoint;
}
