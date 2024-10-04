#include <stdio.h>

int main(int argc, char *argv[])
{
	int a[] = {1, 2, 3, 4, 5, 6, 7};
	int *p, *q, i, n, t;

	n = sizeof(a) / sizeof(a[0]);
	p = a;
	q = &a[n-1];

	while(p < q){
		t = *p;
		*p = *q;
		*q = t;

		p++;
		q--;
	}

	for(i = 0; i < n; i++){
		printf("%d ", a[i]);
	}
	puts("");

	return 0;
}
