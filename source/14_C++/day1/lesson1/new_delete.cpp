#include <stdio.h>
#include <malloc.h>
#include <string.h>

int main(void)
{
	int *intp = new int;

	*intp = 100;

	printf("*intp = %d\n", *intp);

	delete intp;
	
	
	
	char *p = new char[10];

	strcpy(p, "hello");

	printf("p: %s\n", p);

	delete [] p;
	
	return 0;
}
