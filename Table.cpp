#include"Table.hpp"
#include<sstream>
using namespace std;

namespace Restaurant
{
	int Table::tableCount = 0;

	Table::Table(int n, Employee server) :
		nSeat_(n), server_(server), id_(++tableCount) {
		
		for (int i = 0; i < n; ++i)
			custs_.push_back(Customer::spointer_type(new Customer()));
	}

	double Table::Total() const
	{
		double total = 0;
		for (int i = 0; i < nSeat_; ++i) {
			total += custs_[i]->Total();
		}
		return total;
	}

	string Table::to_string() const {
		ostringstream oss;

		oss << "Table: #" << Id() << "\n"
			<< "Number of seats: " << nSeat_ << "\n";

		for (int i = 0; i < nSeat_; ++i) {
			oss << custs_[i]->tab();
		}
			
		oss << "Tatal: $" << Total() << endl;

		return oss.str();
	}

	Customer::spointer_type Table::getCust(int i) const {
		if (i < nSeat_)
			return custs_[i];	

		throw "out of range";
	}
};