#include <stdio.h>

int main(int argc, char *argv[])
{
	int i, j;

	for(i = 0; i < 3; i++){
		for(j = 0; j < 4; j++){
			printf("i = %d, j = %d\n", i, j);
		}

		puts("");
	}

	return 0;
}
