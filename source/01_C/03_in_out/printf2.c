#include <stdio.h>

int main(int argc, char *argv[])
{
	int a = 123;
	float b = 123.456;
	char c = 'a';

	printf("%8d %2d\n", a, a);

	printf("%8f %8.2f %.3f\n", b, b, b);

	printf("%3c\n", c);

	return 0;
}
