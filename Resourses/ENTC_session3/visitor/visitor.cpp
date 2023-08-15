#include "stdafx.h"
#include <stdio.h>
#include <iostream>
#include <memory>

class FullTimeEmployee;
class PartTimeEmployee;

class EmployeeVisitor
{
public:
	EmployeeVisitor() {}
	virtual ~EmployeeVisitor() {}

	virtual void visit(FullTimeEmployee& employee) = 0;
	virtual void visit(PartTimeEmployee& employee) = 0;
};

class Employee
{
public:
	Employee() {}
	virtual ~Employee() {}

	virtual float getRate() = 0;
	virtual float getTotalHours() = 0;

	virtual void accept(EmployeeVisitor& visitor) = 0;
};

class FullTimeEmployee : public Employee
{
public:
	FullTimeEmployee() {}
	virtual ~FullTimeEmployee() {}

	float getRate() override { return 350.0; }
	float getTotalHours() override { return 150.0; }
	void accept(EmployeeVisitor& visitor) override { visitor.visit(*this); }
	float getAllowance() { return 10000.0; }
};

class PartTimeEmployee : public Employee
{
public:
	PartTimeEmployee() {}
	virtual ~PartTimeEmployee() {}
	float getRate() override { return 250.0; }
	float getTotalHours() override { return 100.0; }
	void accept(EmployeeVisitor& visitor) override { visitor.visit(*this); }
};

class EmployeeVisitorImpl : public EmployeeVisitor
{
public:
	EmployeeVisitorImpl() {}
	virtual ~EmployeeVisitorImpl() {}

	void visit(FullTimeEmployee& employee) override
	{
		float salary = (employee.getRate() * employee.getTotalHours()) + employee.getAllowance();
		std::cout << "Visiting FullTimeEmployee, Salary: " << salary << std::endl;
	}

	void visit(PartTimeEmployee& employee) override
	{
		float salary = (employee.getRate() * employee.getTotalHours());
		std::cout << "Visiting PartTimeEmployee, Salary: " << salary << std::endl;
	}
};

int main()
{
	std::unique_ptr<Employee> e1 = std::make_unique<FullTimeEmployee>();
	std::unique_ptr<Employee> e2 = std::make_unique<PartTimeEmployee>();
	std::unique_ptr<EmployeeVisitor> visitor = std::make_unique<EmployeeVisitorImpl>();
	e1->accept(*visitor);
	e2->accept(*visitor);

	std::cin.get();
}

