#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <list>
#include <vector>
#include <map>
#include "../../Map/Map/ordered_map.h"
#include <chrono>
#include <fstream>

std::chrono::milliseconds time_vector(int *source, int num);
std::chrono::milliseconds time_list(int *source, int num);
std::chrono::milliseconds time_map(int *source, int num);
std::chrono::milliseconds time_hash(int *source, int num);

const int max_size = 0x1000;

using namespace std;

int main() {
	using namespace std::chrono;

	int *source = (int *)malloc(max_size * sizeof(int));
	for (int i = 0; i < max_size; ++i)
		source[i] = rand();

	ofstream file("results_for_adding.csv");

	file << "N;vector;list;map;hash" << endl;

	for (int i = 0x100; i <= max_size; i *= 2) {
		cout << i << endl;

		file << i << ";";
		file << time_vector(source, i).count() << ";";
		file << time_list(source, i).count() << ";";
		file << time_map(source, i).count() << ";";
		file << time_hash(source, i).count() << endl;
	}

	file.close();
	cout << "End of testing." << endl;
	cin.get();
	free(source);
	return 0;
}

std::chrono::milliseconds time_vector(int *source, int num) {
	using namespace std::chrono;
	int *test_array = new int[num];
	system_clock::time_point before = system_clock::now();

	for (int i = 0; i < num; ++i)
		test_array[i] = source[i];

	delete[] test_array;

	system_clock::time_point after = system_clock::now();
	milliseconds result = duration_cast<milliseconds>(after - before);
	return result;
}

std::chrono::milliseconds time_list(int *source, int num) {
	using namespace std::chrono;
	list<int> test;
	system_clock::time_point before = system_clock::now();

	for (int i = 0; i < num; ++i) 
		test.push_back(source[i]);

	system_clock::time_point after = system_clock::now();
	milliseconds result = duration_cast<milliseconds>(after - before);
	return result;
}

std::chrono::milliseconds time_map(int *source, int num) {
	using namespace std::chrono;
	map<int, int> test;
	system_clock::time_point before = system_clock::now();

	for (int i = 0; i < num; ++i)
		test[i] = source[i];

	system_clock::time_point after = system_clock::now();
	milliseconds result = duration_cast<milliseconds>(after - before);
	return result;
}

std::chrono::milliseconds time_hash(int *source, int num) {
	using namespace std::chrono;
	ordered_map<int, int> test;
	test.initialize(num);
	system_clock::time_point before = system_clock::now();

	for (int i = 0; i < num; ++i)
		test[i] = source[i];

	system_clock::time_point after = system_clock::now();
	milliseconds result = duration_cast<milliseconds>(after - before);
	return result;
}