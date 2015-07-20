#include "B.h"
#include <iostream>

using namespace std;

//int main() {
//	try {
//		int a;
//		cin >> a;
//		if (a == 0) {
//			throw 1; //1 - exception
//		}
//		cout << (1 / a) << endl;
//	}
//	catch (int e) { //exception of int type
//		cout << "Devision by zero." << endl;
//	} 
//	//catch (ios_base::failure z) {...} //exception of ios_base::failure type
//	//catch (...) {...} - any exception
//	getc(stdin);
//	return 0;
//}

int main() {
	try {
		B a;
	}
	catch (int e) {
		cout << "Exception is caught." << endl;
	}
	cin.get();
	return 0;
}