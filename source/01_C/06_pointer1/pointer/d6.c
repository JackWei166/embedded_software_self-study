#include <stdio.h>

#define N 5

int main(int argc, char *argv[])
{
	int a[N];
	int *p, i;

	p = a;
	for(i = 0; i < N; i++){
		scanf("%d", p++);
	}	
	
	p = a;
	for(i = 0;i < N; i++){
	printf("%d ", *p++);
	}
	puts("");
	
	return 0;
}
