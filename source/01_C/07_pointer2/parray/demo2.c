#include <stdio.h>

int main(int argc, char *argv[]){
	int a[2][3] = {{1, 2, 3}, {4, 5, 6}};
	int *p[2];

	p[0] = a[0];
	p[1] = a[1];

	printf("%d %d\n", p[0][1], a[0][1]);

	return 0;
}
