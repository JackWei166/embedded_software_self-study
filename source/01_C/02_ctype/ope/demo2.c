#include <stdio.h>

int main(int argc, char *argv[])
{
	float a = 1, b =2, c;

	//+
	c = a + b;
	printf("a + b = %f\n", c);

	//-
	c = a - b;
	printf("a - b = %f\n", c);

	//*
	c = a * b;
	printf("a * b = %f\n", c);
	
	///
	c = a / b;
	printf("a / b = %f\n", c);
	
	//%
	//c = a % b;
	//printf("a %% b = %f\n", c);	

	return 0;
}
