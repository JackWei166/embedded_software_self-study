#include <stdio.h>

void swap(int &a, int &b)
{
	a ^= b;
	b ^= a;
	a ^= b;
}

int main(void)
{
	int a = 100;
	int b = 10;

	printf("a = %d, b = %d\n", a, b);

	swap(a, b);
	
	printf("a = %d, b = %d\n", a, b);

	return 0;
}
