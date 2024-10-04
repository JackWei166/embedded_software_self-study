#include <stdio.h>

int main(int argc, char *argv[])
{
	int a = 10;
	int *p = &a, *q = p;

	printf("%p %d\n", &p, sizeof(p));
	printf("%p %p\n", p, &a);
	printf("%d %d\n\n", *p, a);
	
	printf("%p %d\n", &q, sizeof(q));
	printf("%p %d\n", q, *q);

	return 0;
}
