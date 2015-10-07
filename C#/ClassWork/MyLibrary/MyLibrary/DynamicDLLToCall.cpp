#include "DynamicDLLToCall.h"
#include <string>
#include <iostream>
#include <windows.h>

using namespace std;

int MultiplyByTen(int numberToMultiply)
{
	int returnValue = numberToMultiply * 10;
	return returnValue;
}