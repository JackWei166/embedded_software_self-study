#include <stdio.h>

int main(int argc, char *argv[])
{
	int sum = 0;
	int i = 1;

	while(i <= 100){
		sum += i;
		i++;
	}

	printf("1 + 2 + 3 + ... + %d = %d\n", i - 1, sum);
	
	return 0;
}
