#include "stdafx.h"
#include <stdlib.h>

int MAXnMIN(int a, int b);

int main()
{
	int a, b;
	printf("a=");
	scanf("%d", &a);
	printf("b=");
	scanf("%d", &b);
	printf("%d\n", MAXnMIN(a, b));
	return 0;
}

int MAXnMIN(int a, int b)
{
	int rezult;
	if (a > b)
		rezult = a / b;
	rezult = MAXnMIN(b, a);
	return rezult;
}
