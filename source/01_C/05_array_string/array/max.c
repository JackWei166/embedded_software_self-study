#include <stdio.h>

int main(int argc, char *argv[])
{
	int i, j, row, column;
	int a[2][3] = {{1, 2, 3}, {4, 5, 6}};

	row = column = 0;

	for(i = 0; i < 2; i++){
		for(j = 0; j < 3; j++){
			if(a[i][j] > a[row][column]){
				row = i;
				column = j;
			}
		}
	}

	for(i = 0; i < 2; i++){
		for(j = 0; j < 3; j++){
			printf("%d ", a[i][j]);
		}
		puts("");
	}

	printf("%d %d %d\n", a[row][column], row, column);

	return 0;
}
