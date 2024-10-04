#include <stdio.h>

int main(int argc, char *argv[])
{
	int a = 1, b =2, c;

	//+
	c = a + b;
	printf("a + b = %d\n", c);

	//-
	c = a - b;
	printf("a - b = %d\n", c);

	//*
	c = a * b;
	printf("a * b = %d\n", c);
	
	///
	c = a / b;
	printf("a / b = %d\n", c);
	
	//%
	c = a % b;
	printf("a %% b = %d\n", c);	

	return 0;
}
