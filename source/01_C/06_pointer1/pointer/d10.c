#include <stdio.h>

int main(int argc, char *argv[])
{
	int a[3][2] = {{1, 2}, {3, 4}, {5, 6}};
	int *p;

	p = a[0];

	printf("%p %p\n", p, p+1);
	printf("%p %p\n", a, a+1);
	printf("%p %p\n", *a, *a+1);

	return 0;
}
