#pragma once
#include<string>
#include<memory>
#include"Employee.hpp"
#include"Customer.hpp"
#include<vector>

namespace Restaurant
{
	class Table
	{
	public:
		typedef std::shared_ptr<Table>		spointer_type;
		typedef std::unique_ptr<Table>		upointer_type;
		
	private:
		static int tableCount;
		int id_;
		int nSeat_;
		Employee server_;
		std::vector<Customer::spointer_type> custs_;

	public:
		Table(int n = 2, Employee server = Employee());

		Customer::spointer_type getCust(int i) const;

		Restaurant::Employee Server() const { return server_; }
		void Server(Restaurant::Employee val) { server_ = val; }
		int Id() const { return id_; }
		void Id(int val) { id_ = val; }

		double Total() const;
		std::string to_string() const;
	};
};