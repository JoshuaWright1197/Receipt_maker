#pragma once
#include"Person.hpp"
#include<memory>

namespace Restaurant
{
	class Employee : public Person
	{
	public:
		typedef std::shared_ptr<Employee> spointer_type;
		typedef std::unique_ptr<Employee> upointer_type;
		
	private:
		static int employeeCount;
		double pay_;

	public:
		Employee(std::string fname = "Unknown", std::string lname = "Unknown", short age = 0,
			Restaurant::Address address = Restaurant::Address(), double pay = 0.0)
			: Person(fname, lname, age, address, ++employeeCount), pay_(pay) {}

		double Pay() const { return pay_; }
		void Pay(double val) { pay_ = val; }

		std::string to_string() const;
	};
};