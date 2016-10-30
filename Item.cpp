#include"Item.hpp"
#include<sstream>
using namespace std;

namespace Restaurant
{
	int Item::itemCount = 0;

	string Item::to_string() const {
		ostringstream oss;
		oss << "Id: " << Id() << "\n"
			<< "Name: " << Name() << "\n"
			<< "Price: " << Price() << endl;

		return oss.str();
	}
};