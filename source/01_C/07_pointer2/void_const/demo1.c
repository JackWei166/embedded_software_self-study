#include <stdio.h>

int main(int argc, char *argv[]){
	int m = 10;
	double n = 3.14;
	void *p, *q;
	int *s;

	p = (void *)&m;

	printf("%d %d\n", m, *(int *)p);
	printf("%p\n", p);
	p++;
	printf("%p\n", p);

	q = (void *)&n;
	printf("%.2lf %.2lf\n", n, *(double *)q);
	printf("%p\n", q);
	q++;
	printf("%p\n", q);

	s = &m;
	printf("%p\n", s);
	s++;
	printf("%p\n", s);

	return 0;
}

