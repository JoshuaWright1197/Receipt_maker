#pragma once
#include<string>
#include<memory>
#include<vector>

namespace Restaurant
{
	class Item
	{
	public:
		typedef std::unique_ptr<Item>	upointer_type;
		typedef std::shared_ptr<Item>	spointer_type;
		typedef std::vector<upointer_type>	Bill_uptr;
		typedef std::vector<spointer_type>	Bill_sptr;
		typedef std::vector<Item>	Bill_t;
		
	private:
		static int itemCount;
		int id_;
		std::string name_;
		double price_;

	public:
		Item(std::string name = "unknown", double price = 0) : name_(name), price_(price), id_(++itemCount) {}
		
		int Id() const { return id_; }
		void Id(int val) { id_ = val; }
		std::string Name() const { return name_; }
		void Name(std::string val) { name_ = val; }
		double Price() const { return price_; }
		void Price(double val) { price_ = val; }

		std::string to_string() const;
	};
};