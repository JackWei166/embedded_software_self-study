#include <stdio.h>

int main(int argc, char *argv[])
{
	unsigned char x = 0126, y = 0xac, z;

	z = x & y;

	printf("%#x\n", z);

	return 0;
}
