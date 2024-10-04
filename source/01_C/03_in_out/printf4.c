#include <stdio.h>

int main(int argc, char *argv[])
{
	int a = 123;
	float b = 123.4;
	char c = 'a';

	int d = 12345;
	int e = 123;
	int f = 123456789;

	printf("%08d %0+8d\n", a, a);

	printf("%09f %09.2f %.3f\n", b, b, b);

	printf("%5c\n", c);

	printf("%9d\n", d);
	printf("%9d\n", e);
	printf("%9d\n", f);	
	//printf("%d\n", d);

	return 0;
}
