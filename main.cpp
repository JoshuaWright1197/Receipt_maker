#include"Recpit_maker.hpp"
#include<iostream>
#include<vector>
#include<cassert>
#include<crtdbg.h>
using namespace std;
using namespace Restaurant;


#define CHECK_MEM_INTENSIVE_
#if defined(CHECK_MEM_INTENSIVE_) && defined(_DEBUG)
#define CHECK_MEMORY_INTEGRITY() assert(_CrtCheckMemory())
#else
#define CHECK_MEMORY_INTEGRITY()
#endif

int main()
{
#if defined(_DEBUG)
	int dbgFlags = _CrtSetDbgFlag(_CRTDBG_REPORT_FLAG);
	dbgFlags = dbgFlags | _CRTDBG_CHECK_ALWAYS_DF; // check block integrity on every memory call
	dbgFlags |= _CRTDBG_DELAY_FREE_MEM_DF; // don't remove block on delete
	dbgFlags |= _CRTDBG_LEAK_CHECK_DF; // check for memory leaks at process termination
	_CrtSetDbgFlag(dbgFlags);
#endif



	Customer::spointer_type c1(new Customer("Joshua", "Wright"));
	
	cout << "just created" << endl;
	cout << c1->to_string() << endl;
	cout << endl;

	Item::spointer_type i1(new Item("Burger", 6.25));

	*c1 + i1;


	cout << "just got something" << endl;
	cout << c1->to_string() << endl;
	cout << endl;

	Item::Bill_sptr b1;

	b1.push_back(Item::spointer_type(new Item("MilkShake", 2.00)));
	b1.push_back(Item::spointer_type(new Item("FenchFires", 3.00)));

	*c1 + b1;

	cout << "just got someones bill" << endl;
	cout << c1->to_string() << endl;
	cout << endl;

	cout << "printing tab" << endl;
	cout << c1->tab() << endl;
	cout << endl;

	Table t1(4);

	Customer::spointer_type c2 = t1.getCust(0);
	
	*c2 + b1;


	cout << "new person's to_string " << endl;
	cout << c2->to_string() << endl;
	cout << endl;

	cout << "new person's tab" << endl;
	cout << c2->tab() << endl;
	cout << endl;

	cout << "table" << endl;
	cout << t1.to_string() << endl;
	cout << endl;

	*t1.getCust(1).get() = std::move(*c1);

	cout << "table + 1 sitting" << endl;
	cout << t1.to_string() << endl;
	cout << endl;

	CHECK_MEMORY_INTEGRITY();
}