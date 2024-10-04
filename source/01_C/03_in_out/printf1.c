#include <stdio.h>

int main(int argc, char *argv[])
{
	int a = 1;
	float b = 1.5;
	char c = 'a';
	char *s = "abc";

	printf("%d %o %x\n", a, a, a);

	printf("%f %g %e\n", b, b, b);

	printf("%c %d\n", c, c);

	printf("%s\n", s);

	return 0;
}
