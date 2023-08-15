#include "stdafx.h"
#include <iostream>
#include <string>

#include <unordered_map>

struct FoodItem
{
	std::string m_name;
	int m_qty;
	double m_price;
	FoodItem() {}

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
	std::unordered_map<std::string, FoodItem> foodItems;
	foodItems.emplace(std::pair<std::string, FoodItem>("Rice", { "Rice", 10, 2300.0 }));
	foodItems.emplace(std::pair<std::string, FoodItem>("Dahl", { "Dahl", 1, 130.0 }));
	foodItems.emplace(std::pair<std::string, FoodItem>("Mango", {"Mango", 15, 450.0 }));
	foodItems.emplace(std::pair<std::string, FoodItem>("Sugar", { "Sugar", 2, 460.0 }));
	foodItems.emplace(std::pair<std::string, FoodItem>("Apple", { "Apple", 3, 680.0 }));

	//lets say I want to find food item sugar
	const FoodItem& foodItem = foodItems["Sugar"];
	std::cout << "Food Item Found. " << foodItem << std::endl;

	std::cin.get();
}