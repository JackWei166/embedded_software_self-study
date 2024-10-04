#include <stdio.h>

int main(int argc, char *argv[])
{
	int a = 65;	

	printf("%d %#x\n", a, a);

	a = a >> 3;

	printf("%d %#x\n", a, a);

	a = a & 0xf;

	printf("%d %#x\n", a, a);
	
	return 0;
}
