#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <list>
#include <map>
#include "../../../ClassWork/Map/Map/ordered_map.h"
#include <chrono>
#include <fstream>
#include <algorithm>

std::chrono::milliseconds sort_array(int *source, int num);
std::chrono::milliseconds sort_vector(int *source, int num);
std::chrono::milliseconds sort_list(int *source, int num);

std::chrono::milliseconds find_map(int *source, int num);
std::chrono::milliseconds find_hash(int *source, int num);

const int max_size = 0x1000;

using namespace std;

int main() {
	using namespace std::chrono;

	int *source = (int *)malloc(max_size * sizeof(int));
	for (int i = 0; i < max_size; ++i)
		source[i] = rand();

	ofstream file_sort("results_for_sort.csv");
	ofstream file_find("results_for_find.csv");

	file_sort << "N;array;vector;list" << endl;
	file_find << "N;map;hash" << endl;

	for (int i = 0x100; i <= max_size; i *= 2) {
		cout << i << endl;

		file_sort << i << ";";
		file_sort << sort_array(source, i).count() << ";";
		file_sort << sort_vector(source, i).count() << ";";
		file_sort << sort_list(source, i).count() << endl;

		file_find << i << ";";
		file_find << find_map(source, i).count() << ";";
		file_find << find_hash(source, i).count() << endl;
	}

	file_sort.close();
	file_find.close();
	cout << "End of testing." << endl;
	cin.get();
	free(source);
	return 0;
	return 0;
}

std::chrono::milliseconds sort_array(int *source, int num) {
	using namespace std::chrono;
	int *test = (int *)malloc(num * sizeof(int));

	for (int i = 0; i < num; ++i)
		test[i] = source[i];

	system_clock::time_point before = system_clock::now();
	sort(test, test + num);
	system_clock::time_point after = system_clock::now();

	milliseconds result = duration_cast<milliseconds>(after - before);
	free(test);
	return result;
}

std::chrono::milliseconds sort_vector(int *source, int num) {
	using namespace std::chrono;
	vector<int> test(num);

	for (int i = 0; i < num; ++i)
		test.push_back(source[i]);

	system_clock::time_point before = system_clock::now();
	sort(test.begin(), test.end());
	system_clock::time_point after = system_clock::now();

	milliseconds result = duration_cast<milliseconds>(after - before);
	return result;
}

std::chrono::milliseconds sort_list(int *source, int num) {
	using namespace std::chrono;
	list<int> test;

	for (int i = 0; i < num; ++i)
		test.push_back(source[i]);

	system_clock::time_point before = system_clock::now();
	test.sort();
	system_clock::time_point after = system_clock::now();

	milliseconds result = duration_cast<milliseconds>(after - before);
	return result;
}

std::chrono::milliseconds find_map(int *source, int num) {
	using namespace std::chrono;
	map<int, int> test;

	for (int i = 0; i < num; ++i)
		test[i] = source[i];

	system_clock::time_point before = system_clock::now();
	for (int i = 0; i < num; ++i)
		test.find(i);
	system_clock::time_point after = system_clock::now();

	milliseconds result = duration_cast<milliseconds>(after - before);
	return result;
}

std::chrono::milliseconds find_hash(int *source, int num) {
	using namespace std::chrono;
	ordered_map<int, int> test;
	test.initialize(num);

	for (int i = 0; i < num; ++i)
		test[i] = source[i];

	system_clock::time_point before = system_clock::now();
	for (int i = 0; i < num; ++i)
		test.find(i);
	system_clock::time_point after = system_clock::now();

	milliseconds result = duration_cast<milliseconds>(after - before);
	return result;
}