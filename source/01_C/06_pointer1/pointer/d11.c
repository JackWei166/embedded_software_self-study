#include <stdio.h>

int main(int argc, char *argv[])
{
	int a[3][2] = {{1, 2}, {3, 4}, {5, 6}};
	int (*p)[2], i, j;

	p = a;

	printf("%p %p\n", p, p+1);
	printf("%p %p\n", a, a+1);
	
	for(i = 0; i < 3; i++){
		for(j = 0; j < 2; j++){
			printf("%d %d %d %d\n", a[i][j], *(*(a+i)+j), p[i][j], *(*(p+i)+j));
		}
	}

	return 0;
}
