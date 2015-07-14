// regex_match example
#include <iostream>
#include <string>
#include <regex>
#include <fstream>

int main()
{
	// ---

	//std::string s("345subject123subject");
	//std::regex e("[^\\d]*(\\d+).*");

	//std::smatch sm;    // same as std::match_results<string::const_iterator> sm;
	//std::regex_match(s, sm, e);
	//std::cout << "string object with " << sm.size() << " matches\n";

	//std::cout << "the matches were: ";
	//for (unsigned i = 0; i < sm.size(); ++i) {
	//	std::cout << "[" << sm[i] << "] ";
	//}

	//std::cout << std::endl;

	// ---

	//std::string s("this subject has 123 a 123subm789arine as a subsequence 456");
	//std::smatch m;
	//std::regex e("\\b\\d+\\b");   // matches words beginning by "sub"

	//std::cout << "Target sequence: " << s << std::endl;
	//std::cout << "Regular expression: /\\b(sub)([^ ]*)/" << std::endl;
	//std::cout << "The following matches and submatches were found:" << std::endl;

	//while (std::regex_search(s, m, e)) {
	//	for (auto x : m) std::cout << x << " ";
	//	std::cout << std::endl;
	//	s = m.suffix().str();
	//}

	// Task 1

	std::string test_1("this -0.1 10.4 te20103.2516st 10 -100 string");
	std::smatch storage_1;
	std::regex search_1("\\-?\\d+\\.?\\d+");

	std::cout << "Task 1. Decimals found:" << std::endl;
	while (std::regex_search(test_1, storage_1, search_1)) {
		for (auto x : storage_1) std::cout << x << " ";
		std::cout << std::endl;
		test_1 = storage_1.suffix().str();
	}
	std::cout << std::endl;

	// Task 2

	std::string test_2("this 0.1 264 10.4 te256.3.0.251st 100.21.21.233string");
	std::smatch storage_2;
	std::regex search_2("\\d{1,3}\\.\\d{1,3}\\.\\d{1,3}\\.\\d{1,3}");

	std::cout << "Task 2. IPs found:" << std::endl;
	while (std::regex_search(test_2, storage_2, search_2)) {
		for (auto x : storage_2) std::cout << x << " ";
		std::cout << std::endl;
		test_2 = storage_2.suffix().str();
	}
	std::cout << std::endl;

	// Task 3

	std::string test_3("this 0.1 10.4 te2010.3.0.2516st -100.21.21.233string andandrew1333@gmail.com jswunqwjqn 123@ajms.ru e-mail@x.co.uk abb@x.com united.states@a.b.c.d.e.f.org sk820sm2n");
	std::smatch storage_3;
	std::regex search_3("\\b(?:\\w+\\.)*\\w+@(?:\\w+\\.)+\\w+\\b");

	std::cout << "Task 3. Emails found:" << std::endl;
	while (std::regex_search(test_3, storage_3, search_3)) {
		for (auto x : storage_3) std::cout << x << " ";
		std::cout << std::endl;
		test_3 = storage_3.suffix().str();
	}
	std::cout << std::endl;


	// Task 4

	//std::string test_4;
	//std::smatch storage_4;
	//std::regex search_4("\\b\\w+@\\w+.\\w+\\b");

	//std::cout << "Task 4. Emails found:" << std::endl;
	//while (std::regex_search(test_3, storage_3, search_3)) {
	//	for (auto x : storage_3) std::cout << x << " ";
	//	std::cout << std::endl;
	//	test_3 = storage_3.suffix().str();
	//}
	//std::cout << std::endl;

	std::cin.get();

	return 0;
}