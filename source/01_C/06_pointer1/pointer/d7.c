#include <stdio.h>

int main(int argc, char *argv[])
{
	int a[] = {1, 2, 3, 4, 5, 6, 7};
	int *p, i, n;

	p = a;
	n = sizeof(a) / sizeof(a[0]);

	printf("%p %p %p %p\n", &a, a, a+1, a+2);

	for(i = 0; i < n; i++){
		printf("%d %d %d %d\n", a[i], *(a+i), p[i], *(p+i));
	}
	
	p++;
	printf("%d\n", p[1]);
	
	return 0;
}
