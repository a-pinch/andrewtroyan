// ConsoleApplication3.cpp : Defines the entry point for the console application.
//


#include "stdafx.h"
#include <iostream>


using namespace std;
void show(int op=1);
void print_fromAtoB(int a, int b);
int sum();


int _tmain(int argc, _TCHAR* argv[])
{
	//show();

	//int a, b;
	//cin >> a;
	//cin >> b;

	//print_fromAtoB(a, b);

    printf("sum=%d\n", sum());

	system("pause");
	return 0;
}


void print_fromAtoB(int a, int b)
{
	if (a != b)
	{
		if (a > b)
		{
			cout << a << ' ';
			print_fromAtoB(a - 1, b);
		}
		else
		{
			cout << a << ' ';
			print_fromAtoB(a + 1, b);
		}
	} else 	cout << a << ' '<< endl;

}



void show(int op)
{
	int  n;
	cin >> n;
	if (n != 0)
		show(op+1);

	if (n != 0)
		cout << n  << '(' << op << ')' << ' ';
}



int sum()
{
	int n;
	cin >> n;
	return (n != 0) ? n + sum() :n;

}

