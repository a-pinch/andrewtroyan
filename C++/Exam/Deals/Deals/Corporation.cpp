#include "Corporation.h"
#include <stdexcept>
#include <vector>
#include <algorithm>

using std::vector;
using std::invalid_argument;
using std::for_each;
using std::sort;

const int Corporation::current_year = 2015;

string Corporation::get_name() {
	return name;
}

unsigned int Corporation::get_foundation_year() {
	return foundation_year;
}

void Corporation::make_deal(unsigned int day, unsigned int month, unsigned int year, string name, initializer_list<string> numbers) {
	if (year >= foundation_year && year <= Corporation::current_year && month >= 2 && month <= 12 && day >= 1 && day <= 31) {
		deals.push_back(deal(day, month, year, name, numbers));
	}
	else {
		throw invalid_argument("In Corporation::make_deal(unsigned int, unsigned int, unsigned int, string, initializer_list<string>): wrong data.");
	}
}

vector<Corporation::deal> Corporation::get_deals_older_than(unsigned int amount_of_years, unsigned int current_year) {
	vector<deal> deals_to_return;

	// lambda function for selecting
	auto select_lambda = [amount_of_years, current_year, &deals_to_return](deal deal_to_select) {
		if (deal_to_select.data_of_deal.year < current_year && current_year - deal_to_select.data_of_deal.year > amount_of_years) {
			deals_to_return.push_back(deal_to_select);
		}
	};

	for_each(deals.begin(), deals.end(), select_lambda);

	return std::move(deals_to_return);
}

void Corporation::sort_deals() {
	sort(deals.begin(), deals.end(), [](deal d_1, deal d_2){ return d_1.data_of_deal.year < d_2.data_of_deal.year; });
}