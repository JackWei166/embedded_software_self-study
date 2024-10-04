#include <stdio.h>

int main(int argc, char *argv[])
{
	int a = 1;
	long b = 2;
	long long c = 3;

	printf("%d %d %d\n", sizeof(a), sizeof(b), sizeof(c));
	printf("%d %d %d\n", sizeof(int), sizeof(long), sizeof(long long));

	return 0;
}
