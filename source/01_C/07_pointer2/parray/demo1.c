#include <stdio.h>

int main(int argc, char *argv[]){
	int a[] = {1, 2, 3, 4, 5};
	int *p[3];

	p[0] = a;
	p[1] = a + 1;
	p[2] = a + 2;

	printf("%d %d %d\n", *p[0], *p[1], *p[2]);

	return 0;
}
