#include <stdio.h>

int main(int argc, char *argv[])
{
	int a = 10, *p = &a;
	double b = 3, *q = &b;

	printf("%p %p\n", p, p + 2);
	printf("%p %p\n", q, q + 2);

	return 0;
}
