#include <stdio.h>

#define W 3e-23
#define C 950

int main(int argc, char *argv[])
{
	//int n;
	//double sum;
	float n, total;

	printf("Plaese input:");
	scanf("%f", &n);
	
	total = n * C / W;

	printf("Total:%e\n", total);

	return 0;
}
