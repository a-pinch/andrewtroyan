#include "Corporation.h"
#include <iostream>
#include <algorithm>
#include <stdexcept>

using std::cout;
using std::cin;
using std::endl;
using std::for_each;
using std::invalid_argument;

int main() {
	try {
		Corporation fruit_company("Fruit Inc.", 1999);

		cout << "Name: " << fruit_company.get_name() << endl << "Found in: " << fruit_company.get_foundation_year() << endl;

		fruit_company.make_deal(15, 10, 2000, "Blah", { "9038179" });
		fruit_company.make_deal(13, 12, 2013, "Cafe", { "09362719" });
		fruit_company.make_deal(10, 11, 2012, "Store", { "39041039" });

		fruit_company.sort_deals();

		// -----
		// lambda function for showing deal
		auto output_deal = [](Corporation::deal output_deal) {
			cout << "-----" << endl;
			cout << "Name: " << output_deal.contragent.name << "\n" << "Contacts: " << endl;
			for (auto num_it = output_deal.contragent.phone_numbers.begin(); num_it != output_deal.contragent.phone_numbers.end(); ++num_it) {
				cout << *num_it << "\n";
			}
			cout << "Data of deal: " << output_deal.data_of_deal.day << "." << output_deal.data_of_deal.month << "." << output_deal.data_of_deal.year << "\n";
			cout << "-----" << endl;
		};
		// -----

		unsigned int amount_of_years = 1;
		vector<Corporation::deal> required_deals = fruit_company.get_deals_older_than(amount_of_years, Corporation::current_year);
		cout << endl << "Deals older than " << amount_of_years << " year(s) from " << Corporation::current_year << ":" << endl;
		for_each(required_deals.begin(), required_deals.end(), output_deal);
	}
	catch (invalid_argument e) {
		cout << e.what() << endl;
	}
	
	cin.get();

	return 0;
}