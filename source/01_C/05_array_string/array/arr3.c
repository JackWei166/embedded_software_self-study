#include <stdio.h>

int main(int argc, char *argv[])
{
	int i, j;
	int a[10][10] = {{0}};

	for(i = 0; i < 10; i++){
		a[i][0] = 1;
		for(j = 1; j <= i; j++){
			a[i][j] = a[i-1][j] + a[i-1][j-1];
		}
	}
	
	for(i = 0; i < 10; i++){
		for(j = 0; j <= i; j++){
			printf("%-8d", a[i][j]);
		}
		puts("");
	}


	return 0;
}
