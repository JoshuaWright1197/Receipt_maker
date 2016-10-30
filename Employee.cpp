#include"Employee.hpp"
#include<sstream>
using namespace std;

namespace Restaurant
{
	int Employee::employeeCount = 0;

	string Employee::to_string() const {
		ostringstream oss;
		oss << "Name:" << firstName_ + " " + LastName() << "\n"
			<< "Age: " << Age() << "\n"
			<< "Pay: " << Pay() << "\n"
			<< address_.to_string();

		return oss.str();
	}
};