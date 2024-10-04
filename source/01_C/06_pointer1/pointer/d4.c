#include <stdio.h>

int main(int argc, char *argv[])
{
	int a[5] = {1, 2, 3, 4, 5};
	int *p, *q;

	p = a;
	q = &a[3];

	printf("%d %d\n", *p, *q);
	printf("%p %p\n", p, q);
	printf("%d\n", q - p);

	return 0;
}
