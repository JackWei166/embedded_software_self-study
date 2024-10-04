#include <stdio.h>

int main(int argc, char *argv[])
{
	int x = 70, y = 10;

	y = ++x > 70 ? x + y : 5;

	printf("x = %d\ny = %d\n", x, y);

	return 0;
}
