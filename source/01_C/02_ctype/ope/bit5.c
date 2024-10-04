#include <stdio.h>

int main(int argc, char *argv[])
{
	unsigned char x = 0x4, y = 2, z;	

	z = x | (1 << (y - 1));
	printf("z = %#x\n", z);

	return 0;
}
