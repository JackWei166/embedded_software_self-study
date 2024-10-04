#include <stdio.h>

int main(int argc, char *argv[])
{
	char fruit[][20] = {"banana", "apple", "strawberry", "watermelen"};
	int i, m;
	
	m = sizeof(fruit) / sizeof(fruit[0]);

	for(i = 0; i < m; i++){
		printf("%s\n", fruit[i]);
	}

	return 0;
}
