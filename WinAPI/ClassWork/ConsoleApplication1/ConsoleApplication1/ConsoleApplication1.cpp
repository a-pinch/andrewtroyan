// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdlib.h>
#include <time.h>

void reverse_arr(int mass[], int);


void revert_arr(int mass[], int size)
{
	int t;
	for (int i = 0; i < size/2; ++i)
	{
		t = mass[i];
		mass[i] = mass[size - i - 1];
		mass[size - i - 1]=t;
	}

}

int _tmain(int argc, _TCHAR* argv[])
{
	
	const int size = 10;
	int mass[size] = { 10, 15, 5, 14, 3 };
	//srand(time(NULL));
	
	
	for (int i = 0; i < size; ++i)
		mass[i] = rand() % 9;

	for (int i = 0; i < size; ++i)
		printf(" %d ", mass[i]);
	printf("\n");

	reverse_arr(mass, size);

	for (int i = 0; i < size; ++i)
		printf("%d", mass[i]);
	printf("\n");

	getchar();

	return 0;
}

