#include"Customer.hpp"
#include<sstream>
#include<iomanip>
using namespace std;

namespace Restaurant
{
	int Customer::customerCount = 0;

	string Customer::to_string() const {
		ostringstream oss;
		oss << "Name:" << FirstName() + " " + lastName_ << "\n"
			<< "Age: " << age_ << "\n"
			<< "Total: $" << Total() << "\n"
			<< Address().to_string();

		return oss.str();
	}

	string Customer::tab() const {
		ostringstream oss;
		oss.precision(2);
		for (auto it = bill_.cbegin(); it != bill_.cend(); ++it) {
			oss << setw(15) << left << it->get()->Name() << "$" << fixed << it->get()->Price() << endl;
		}
		return oss.str();
	}

	double Customer::Total() const {
		double total = 0;

		for (auto it = bill_.cbegin(); it != bill_.cend(); ++it) {
			total += it->get()->Price();
		}
		return total;
	}

	Customer& Customer::operator+ (Item::spointer_type item) {
		bill_.push_back(item);
		return *this;
	}

	Customer& Customer::operator+ (Item::Bill_sptr bill) {

		for (auto it = bill.begin(); it != bill.end(); ++it)
			bill_.push_back(std::move(*it));
		return *this;
	}
};