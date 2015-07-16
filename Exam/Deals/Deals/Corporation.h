#pragma once

#include <vector>
#include <string>
#include <initializer_list>
#include <ostream>

using std::vector;
using std::string;
using std::initializer_list;
using std::ostream;

class Corporation {
public:
	static const int current_year;

	// struct for data (includes day, month and year)
	struct data {
		unsigned int day, month, year;
		data(unsigned int day_, unsigned int month_, unsigned int year_) : day(day_), month(month_), year(year_) {};
	};

	// struct for corporation's agent (contains agent's name and his contact numbers)
	struct agent {
		string name;
		vector<string> phone_numbers;
		agent(string name_, initializer_list<string> phone_numbers_) : name(name_), phone_numbers(phone_numbers_) {};
	};

	// struct for deal (includes data of deal and contragent)
	struct deal {
		data data_of_deal;
		agent contragent;
		deal(unsigned int day, unsigned int month, unsigned int year, string contr_agent_name, initializer_list<string> contr_agent_numbers) : 
			data_of_deal(day, month, year), contragent(contr_agent_name, contr_agent_numbers) {};
	};

	// ctor
	Corporation(string name_, unsigned int foundation_year_) : name(name_), foundation_year(foundation_year_) {};

	// methods
	string get_name();
	unsigned int get_foundation_year();
	// adds another deal
	void make_deal(unsigned int day, unsigned int month, unsigned int year, string name, initializer_list<string> numbers);
	// return deals that older than amount_of_years year from current_year 
	vector<deal> get_deals_older_than(unsigned int amount_of_years, unsigned int current_year);
	// sorts vector of deals
	void sort_deals();

private:
	//name of corporation
	string name;
	//year of corporation's foundation
	unsigned int foundation_year;
	//its deals
	vector<deal> deals;
};

