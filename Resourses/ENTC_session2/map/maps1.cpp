#include "stdafx.h"
#include <iostream>
#include <string>

#include <vector>
#include <map>
#include <unordered_map>

struct FoodItem
{
	std::string m_name;
	int m_qty;
	double m_price;
	FoodItem(const std::string& name, int qty, double price)
		: m_name(name), m_qty(qty), m_price(price)
	{

	}
};

std::ostream& operator << (std::ostream& stream, const FoodItem& foodItem)
{
	stream << "Name=" << foodItem.m_name
		<< ", Qty=" << foodItem.m_qty
		<< ", Price=" << foodItem.m_price;
	return stream;
}

int main()
{
	std::vector<FoodItem> foodItems;
	foodItems.emplace_back("Rice", 10, 2300.0);
	foodItems.emplace_back("Dahl", 1, 130.0);
	foodItems.emplace_back("Mango", 15, 450.0);
	foodItems.emplace_back("Sugar", 2, 460.0);
	foodItems.emplace_back("Apple", 3, 680.0);

	//lets say I want to find food item sugar
	for (const FoodItem& foodItem : foodItems)
	{
		if (foodItem.m_name == "Sugar")
		{
			std::cout << "Food Item Found. " << foodItem << std::endl;
			break;
		}
	}
	std::cin.get();
}