#include <stdio.h>

int main(int argc, char *argv[])
{
	int a[3][2] = {{1, 2}, {3, 4}, {5, 6}};
	int *p, i, n;

	n = sizeof(a) / sizeof(a[0][0]);
	p = a[0];

	printf("%p %p\n", p, p+1);
	printf("%p %p\n", a, a+1);
	
	for(i = 0; i < n; i++){
		printf("%d ", p[i]);
	}
	puts("");

	return 0;
}
