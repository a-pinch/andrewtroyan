#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <string>
#include <sstream>

using namespace std;

int main() {
	int series = 1000;

	cout << [&series](int add){ return series + add; } (167) << endl;
	
	// -----

	auto lambda = [](int x){return x * x; };

	cout << lambda(60) << endl;

	// -----

	vector<int> v{ -100, 1000, 123, 45, -2341, 2144 };

	int result_all = 0;
	result_all = accumulate(v.begin(), v.end(), result_all);
	cout << result_all << endl;

	int result_double = 1;
	result_double = accumulate(v.begin(), v.end(), result_double, [](int x, int y){ return x * y; });
	cout << result_double << endl;

	// -----

	vector<int> class_task{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 15, 16, 17 };

	// Amount of divisible by 3

	int divisible_by_3 = count_if(class_task.begin(), class_task.end(), [](int x){ return x % 3 == 0; });
	cout << divisible_by_3 << endl;

	// Amount of prime numbers

	vector<int> primes{2, 3, 5, 7, 17};
	auto is_prime = [&primes](int x){
		return any_of(primes.begin(), primes.end(), [x](int i){ return x == i; });
	};

	int amount_of_primes = 0;
	amount_of_primes = accumulate(class_task.begin(), class_task.end(), amount_of_primes, [is_prime](int x, int y){
		if (is_prime(y))
			return x + y;
		return x;
	});

	cout << amount_of_primes << endl;

	// String with ";" delimiter

	string third_task = "";

	for_each(class_task.begin(), class_task.end(), [&third_task](int i){ 
		stringstream ss;
		ss << i << "; ";
		third_task += ss.str();
	});

	cout << third_task << endl;

	// Two numbers are different more than 1

	vector<int> amount_of_different;

	for_each(class_task.begin(), class_task.end(), [&amount_of_different, &class_task](int& i){
		static int current_index = 0;

		if (current_index) {
			if (abs(class_task[current_index] - class_task[current_index - 1]) > 1) {
				amount_of_different.push_back(i);
			}
		}

		++current_index;	
	});

	for (auto it : amount_of_different)
		cout << it << " ";

	cin.get();

	return 0;
}