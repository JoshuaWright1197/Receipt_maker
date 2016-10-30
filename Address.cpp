#include"Address.hpp"
#include<sstream>
using namespace std;

namespace Restaurant
{
	string Address::to_string() const {
		ostringstream oss;
		oss << "Street: " << street_ << "\n"
			<< "City: " << City() << "\n"
			<< "Province: " << Province() << "\n"
			<< "Postal Code: " << PostalCode() << endl;
		return oss.str();
	}
};