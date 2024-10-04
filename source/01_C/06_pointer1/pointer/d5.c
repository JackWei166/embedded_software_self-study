#include <stdio.h>

int main(int argc, char *argv[])
{
	int a[5] = {1, 2, 3, 4, 5};
	int *p = NULL, *q;

	printf("%d %p\n", p, p);
	
	p = a;

	printf("%d %p %d\n", p, p, *p);

	q = p++;

	printf("%d %d\n", *p, *q);
	printf("%p %p\n", p, q);
	printf("%d\n", q - p);

	return 0;
}
