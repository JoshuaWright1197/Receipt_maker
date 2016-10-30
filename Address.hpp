#pragma once
#include<string>


namespace Restaurant
{
	class Address
	{
	private:
		std::string street_;
		std::string city_;
		std::string province_;
		std::string postalCode_;
	public:
		Address(std::string street = "Unknown", std::string city = "Unknown",
			std::string province = "Unknown", std::string postalCode = "Unknown")
			: street_(street), city_(city), province_(province), postalCode_(postalCode) {}

		std::string Street() const { return street_; }
		void Street(std::string val) { street_ = val; }
		std::string City() const { return city_; }
		void City(std::string val) { city_ = val; }
		std::string Province() const { return province_; }
		void Province(std::string val) { province_ = val; }
		std::string PostalCode() const { return postalCode_; }
		void PostalCode(std::string val) { postalCode_ = val; }

		std::string to_string() const;
	};
};