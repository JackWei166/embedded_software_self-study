#include <stdio.h>

extern int global_a;

int main(int argc, char *argv[])
{	
	printf("%d\n", global_a);

	return 0;
}
