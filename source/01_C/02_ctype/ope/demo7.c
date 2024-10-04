#include <stdio.h>

int main(int argc, char *argv[])
{
	float x = 1.5, y = 2.5, z;

	z = (x += 5, y++, x + y);

	printf("x = %f\ny = %f\nz = %f\n", x, y, z);

	return 0;
}
