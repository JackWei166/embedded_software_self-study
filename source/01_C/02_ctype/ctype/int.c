#include <stdio.h>
#include <limits.h>

int main(int argc, char *argv[])
{
	printf("%d %d %d %d\n", sizeof(short), sizeof(int), sizeof(char), sizeof(_Bool));

	printf("%d - %d\n", SHRT_MIN, SHRT_MAX);
	printf("%d - %d\n", INT_MIN, INT_MAX);
	printf("%d - %d\n", SCHAR_MIN, SCHAR_MAX);

	return 0;
}
