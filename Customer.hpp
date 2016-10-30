#pragma once
#include<string>
#include<vector>
#include"Item.hpp"
#include"Person.hpp"
#include<memory>
#include<iostream>

namespace Restaurant
{
	class Customer : public Person
	{
	public:
		typedef std::unique_ptr<Customer>	upointer_type;
		typedef std::shared_ptr<Customer>	spointer_type;
		
	private:
		static int customerCount;
		Restaurant::Item::Bill_sptr bill_;

	public:
		Customer(std::string fname = "Unknown", std::string lname = "Unknown", short age = 0,
			Restaurant::Address address = Restaurant::Address(), Item::Bill_sptr bill = Item::Bill_sptr())
			: Person(fname, lname, age, address, ++customerCount), bill_(bill) {}
		~Customer() {
			std::cout << "destroying Customer" << Id() << std::endl;
		}

		double Total() const;

		Customer& operator+ (Item::spointer_type item);
		Customer& operator+ (Item::Bill_sptr bill);

		std::string tab() const;
		std::string to_string() const;
	};
};