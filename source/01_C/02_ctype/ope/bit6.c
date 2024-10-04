#include <stdio.h>

int main(int argc, char *argv[])
{
	unsigned char x = 0x14, y = 3, z;	

	z = x & (~(1 << (y - 1)));
	printf("z = %#x\n", z);

	return 0;
}
