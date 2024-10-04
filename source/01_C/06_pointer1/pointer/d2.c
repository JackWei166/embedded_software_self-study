#include <stdio.h>

int main(int argc, char *argv[])
{
	double a;
	double *p = &a;

	printf("%p %d %d\n", p, sizeof(p), sizeof(double));

	return 0;
}
