#include <stdio.h>

int main(int argc, char *argv[]){
	int a[3] = {1, 2, 3};
	int *p[2] = {&a[0], &a[1]};
	int **q = p;

	printf("%d %d %d\n", a[0], *p[0], **q);
	printf("%d %d %d\n", a[1], *p[1], **(q+1));

	return 0;
}
