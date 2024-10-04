#include <stdio.h>

int main(int argc, char *argv[])
{
	int n = 0, sum = 0;

	while(n++ < 100){
		sum += n;
	}

	printf("sum=%d\n", sum);

	return 0;
}
