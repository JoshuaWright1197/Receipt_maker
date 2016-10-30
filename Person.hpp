#pragma once
#include<string> 
#include"Address.hpp"

namespace Restaurant
{
	class Person
	{
	protected:
		int id_;
		std::string firstName_;
		std::string lastName_;
		short age_;
		Address address_;
	public:
		Person(std::string fname = "Unknown", std::string lname = "Unknown", short age = 0,
			Address address = Restaurant::Address(), int id = 0)
			: firstName_(fname), lastName_(lname), age_(age), address_(address), id_(id) {}
		
		std::string FirstName() const { return firstName_; }
		void FirstName(std::string val) { firstName_ = val; }
		int Id() const { return id_; }
		void Id(int val) { id_ = val; }
		std::string LastName() const { return lastName_; }
		void LastName(std::string val) { lastName_ = val; }
		short Age() const { return age_; }
		void Age(short val) { age_ = val; }
		Restaurant::Address Address() const { return address_; }
		void Address(Restaurant::Address val) { address_ = val; }

		operator std::string() { return to_string(); }
		virtual std::string to_string()const = 0;
	};
};