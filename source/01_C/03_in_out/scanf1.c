#include <stdio.h>

int main(int argc, char *argv[])
{
	int ch, n;
	long m;

	printf(">");
	n = scanf("%x %ld", &ch, &m);
	
	printf("%d %ld %d\n", ch, m, n);

	return 0;
}
