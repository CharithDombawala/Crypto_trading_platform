#include "stdafx.h"
#include <iostream>
#include <string>
#include <memory>

class Student
{
public:
	Student(const std::string& name)
		: m_name(name)
	{
		std::cout << "Created Student: " << m_name << std::endl;
	}

	virtual ~Student()
	{
		std::cout << "Deleted Student: " << m_name << std::endl;
	}

	void print() {}

private:
	const std::string m_name;
};


int main()
{
	{
		std::weak_ptr<Student> student2;
		{
			std::shared_ptr<Student> student1 = std::make_shared<Student>("Student 1");
			student2 = student1;
		}
	}
	
	std::cin.get();
}
