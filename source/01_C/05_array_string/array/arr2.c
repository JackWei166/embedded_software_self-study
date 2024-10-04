#include <stdio.h>

int main(int argc, char *argv[])
{
	int i, j;
	int a[][3] = {{1}, {2, 3}, {4}};

	for(i = 0; i < 3; i++){
		for(j = 0; j < 3; j++){
			printf("%d ", a[i][j]);
		}
		puts("");
	}

	return 0;
}
