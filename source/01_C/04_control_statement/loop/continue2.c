#include <stdio.h>
#include <math.h>

int main(int argc, char *argv[])
{
	int i = 2, n;
	int temp;
	
loop:
	printf("Please input:");
	if(scanf("%d", &n) == 0){
		printf("Input error!\n");
		getchar();
		goto loop;
	}

	temp = sqrt(n);

	while(i <= temp){
		if(n % i == 0)
			break;
		i++;
	}

	if(i <= temp){
		printf("not\n");
	}
	else{
		printf("is\n");
	}
	
	return 0;
}
