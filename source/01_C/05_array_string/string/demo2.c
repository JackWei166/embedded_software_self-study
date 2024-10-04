#include <stdio.h>

int main(int argc, char *argv[])
{
	char fruit[][20] = {"banana", "apple", "strawberry", "watermelen"};
	int i, j, m, n;
	
	m = sizeof(fruit) / sizeof(fruit[0]);
	n = sizeof(fruit[0]) / sizeof(fruit[0][0]);

	for(i = 0; i < m; i++){
		for(j = 0; j < n; j++){
			printf("%c", fruit[i][j]);
		}
		puts("");
	}

	return 0;
}
